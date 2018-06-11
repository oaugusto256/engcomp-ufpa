clear all
close all

clc
nbits = 208000;
modlevel = 2 ;
nbitpersym  = 52;   % Numero de bits por simbolo QAM OFDM
nsym        = 10^4; % Numero de simbolos
len_fft     = 64;   % Tamanho da FFT
sub_car     = 52;   % Numero de subcaries
EbNo        = 0:2:15;

EsNo= EbNo+10*log10(52/64)+ 10*log10(64/80) +10*log10(4);
snr= EsNo - 10*log10((64/80));

M = modem.qammod('M',16); % Objeto de modulação

% Gerando dados
t_data=randint(nbitpersym*nsym*4,1,2);
qamdata=bi2de(reshape(t_data,4,520000).','left-msb');
maping = bin2gray(qamdata,'qam',16);

mod_data =1/sqrt(10)* modulate(M,maping);             % Modulando os dados
par_data = reshape(mod_data,nbitpersym,nsym).';       % Conversão serial paralelo

% Inserção do piloto
pilot_ins_data=[zeros(nsym,6) par_data(:,[1:nbitpersym/2]) zeros(nsym,1) par_data(:,[nbitpersym/2+1:nbitpersym]) zeros(nsym,5)] ;

IFFT_data =ifft(fftshift(pilot_ins_data.')).';        % Transformada de forier
a=max(max(abs(IFFT_data)));
IFFT_data=IFFT_data./a;                               % Normalização

cylic_add_data = [IFFT_data(:,[49:64]) IFFT_data].';  % Adição do prefixo ciclico
ser_data = reshape(cylic_add_data,80*nsym,1);         % Conversão paralelo serial

% Passando pelo canal

no_of_error=[];
ratio=[];

for ii=1:length(snr)  
  chan_awgn = awgn(ser_data,snr(ii),'measured');    % Adição do ruido AWGN
  ser_to_para = reshape(chan_awgn,80,nsym).';       % Conversão serial paralelo
  cyclic_pre_rem = ser_to_para(:,[17:80]);          % Remoção do prefixo ciclico
  FFT_recdata =a*fftshift(fft(cyclic_pre_rem.')).'; % Transformada no dominio da frequencia

  rem_pilot = FFT_recdata (:,[6+[1:nbitpersym/2] 7+[nbitpersym/2+1:nbitpersym] ]);  % Remoção do piloto
  ser_data_1 =sqrt(10)* reshape(rem_pilot.',nbitpersym*nsym,1);                     % Conversão serial

  z=modem.qamdemod('M',16);

  demod_Data = demodulate(z,ser_data_1);            % Demodulação dos dados
  demaping = gray2bin(demod_Data,'qam',16);
  data1 = de2bi(demaping,'left-msb');
  data2 = reshape(data1.',nbitpersym*nsym*4,1);
  [no_of_error(ii),ratio(ii)]=biterr(t_data , data2) ; % Calculo do erro
end

% Apresentação dos dados
semilogy(EbNo,ratio,'--*r','linewidth',2);
hold on;
theoryBer = (1/4)*3/2*erfc(sqrt(4*0.1*(10.^(EbNo/10))));
semilogy(EbNo,theoryBer ,'--b','linewidth',2);
axis([0 15 10^-5 1])
legend('simulated','theoritical')
grid on
xlabel('SNR (dB)');
ylabel('BER')
title('Curva BER usando QAM OFDM');
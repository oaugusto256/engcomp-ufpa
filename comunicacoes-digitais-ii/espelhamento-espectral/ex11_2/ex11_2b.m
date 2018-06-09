% MATLAB PROGRAM <Ex11 2b.m>
% Este programa efetua a simulação de sinalização DS—CDMA com
% detecção QAM coerente.
% Para ilustrar o efeito de espalhamento de CDMA, um usuário é espalhado por
% sequências PN de diferentes comprimentos. Interferência é adicionada
% como um sinal de banda estreita;

% Variação do ganho de espalhamento Lc;

clear; clf; 
Ldata=20000; % comprimento de dados na simulação; deve ser divisível por 8
Lc=11;       % fator de espalhamento versus taxa de dados
             % também pode usar mais curto Lc=7

% Gera símbolos de modulação QPSK
data_sym=2*round(rand(Ldata,1)) -1+j*(2*round(rand(Ldata,1))-1);
jam_data=2*round(rand(Ldata,1)) -1+j*(2*round(rand(Ldata,1))-1);

% Geração do código de espalhamento
pcode=[1 1 1 -1 -1 -1 1 -1 -1 1 -1]';

% Espalha agora
x_in=kron(data_sym, pcode);

% Potência de sinal da entrada do canal é 2*Lc
% Potência interferente é relativa
SIR=10;     % SIR em dB
Pj=2*Lc/(10^(SIR/10));

% Geração do ruído (AWGN)
noiseq = randn(Ldata*Lc, 1)+j*randn(Ldata*Lc,1); % Potência é 2

% Adiciona senoide interferente; frequência de amostragem é fc = Lc
jam_mod = kron(jam_data, ones(Lc,1)); clear jam_data;
jammer = sqrt(Pj/2)*jam_mod.*exp(j*2*pi*0.12*(1:Ldata*Lc)).'; %fj/fc = 0.12.
clear jam_mod;

[P,x] = pwelch(x_in,[],[],[4096],Lc,'twosided');
figure(1);
semilogy(x-Lc/2, fftshift(P));
axis([-Lc/2 Lc/2 1.e-2 1.e2]);
grid;

xfont=xlabel('Frequencia (em unidades de 1/T_s');
yfont=ylabel('PSD do sinal CDMA + interferencia de banda estreita');
set(xfont, 'FontSize', 11); set(yfont, 'FontSize', 11);
[P,x] = pwelch(jammer+x_in,[],[],[4096],Lc,'twosided');
figure(2); semilogy(x-Lc/2, fftshift(P));
grid;
axis([-Lc/2 Lc/2 1.e-2 1.e2]);
xfont=xlabel('frequencia (em unidades de 1/T_s');
yfont=ylabel('PSD dosinal CDMA + interferencia de banda estreita');
set(xfont, 'FontSize', 11); set(yfont, 'FontSize', 11);

BER=[];
BER_az=[];

for i=1:10,
  Eb2N(i)=(i-1);                % (Eb/N em dB)
  Eb2N_num=10^(Eb2N(i)/10);     % Eb/N numérico
  Var_n=Lc/(2*Eb2N_num);        % 1/SNR é a variância do ruído
  signois=sqrt(Var_n);          % desvio-padrão
  awgnois=signois*noiseq;       % AWGN
  % Adiciona ruído aos sinais na saída do canal
  y_out=x_in + awgnois + jammer;
  y_out=reshape(y_out, Lc, Ldata).'; clear y_out awgnois;

  % Desespalhar primeiro
  z_out=Y_out*pcode;

  % Decisão com base no sinal das amostras
  dec1=sign(real(z_out)) + j*sign(imag(z_out));
  % Compara com os dados originais para calcular a BER
  BER=[BER; sum([real(data_sym)~=real(dec1);...
      imag(data_sym)~=imag(dec1)])/(2*Ldata)];
  BER_az=[BER_az;0.5*erfc(sqrt(Eb2N_num))]; % analítico
end

figure(3)
figber=semilogy(Eb2N, BER_az, 'k-', Eb2N, BER, 'k-o');
legend('Sem interferencia', 'Interferencia de banda estreita (-10 dB');
set(figber, 'LineWidth', 2);
xfont=xlabel('E_b/N (dB)');
yfont=ylabel('Taxa de erro de bit');
title('DSSS (CDMA) com ganho de espalhamento = 11');

clear all;
clc;

M = 64;                 % Modulation order
k = log2(M);            % Bits per symbol
EbNoVec = (0:20)';      % Eb/No values (dB)
N = 1000000;   % Number of QAM symbols per frame

L = 2;                 % Tamanho prefixo ciclico
canal = [1 -0.5 0.3]'; % Canal
H = fft([canal; zeros(N-(L+1),1)]); % funcao de transferencia

for n = 1:length(EbNoVec)
    % Convert Eb/No to SNR
    snrdB = EbNoVec(n) + 10*log10(k);
    % Reset the error and bit counters
    numErrs = 0;
    numBits = 0;
    
    % Generate binary data and convert to symbols
    dataIn = randi([0 1],N,k);
    dataSym = bi2de(dataIn);
        
    % QAM modulate using 'Gray' symbol mapping
    txSig = qammod(dataSym,M);
    
    s_ifft = ifft(txSig);
    s_pref = [s_ifft(N-1); s_ifft(N); s_ifft]; % adicionando prefixo ciclico.
    
    %% Passando pelo canal
    s_conv = conv(s_pref,canal);
    
    % Pass through AWGN channel
    rxSig = awgn(s_conv,snrdB,'measured');
        
    r = rxSig(L+1:N+L); % retirando prefixo
    r_fft = fft(r); % Aplicando DFT    
    rxSym = qamdemod(r_fft,M);
    
    % Convert received symbols to bits
    dataOut = de2bi(rxSym,k);
        
    % Calculate the number of bit errors
    nErrors = biterr(dataIn,dataOut);
        
    % Increment the error and bit counters
    numErrs = numErrs + nErrors;
    numBits = numBits + N*k;
    
    % Estimate the BER
    berEst(n) = numErrs/numBits;
end

berTheory = berawgn(EbNoVec,'qam',M);

semilogy(EbNoVec,berEst,'*')
hold on
semilogy(EbNoVec,berTheory)
grid

legend('BER Estimada','BER Teórica')
xlabel('SNR (dB)')
ylabel('Bit Error Rate')

clear all;
clc;

M = 16;                 % Modulation order
k = log2(M);            % Bits per symbol
EbNoVec = (0:20)';      % Eb/No values (dB)
numSymPerFrame = 100;   % Number of QAM symbols per frame

for n = 1:length(EbNoVec)
    % Convert Eb/No to SNR
    snrdB = EbNoVec(n) + 10*log10(k);
    % Reset the error and bit counters
    numErrs = 0;
    numBits = 0;
    
    % Generate binary data and convert to symbols
    dataIn = randi([0 1],numSymPerFrame,k);
    dataSym = bi2de(dataIn);
        
    % QAM modulate using 'Gray' symbol mapping
    txSig = qammod(dataSym,M);
       
    % Pass through AWGN channel
    rxSig = awgn(txSig,snrdB,'measured');
        
    % Demodulate the noisy signal
    rxSym = qamdemod(rxSig,M);
    % Convert received symbols to bits
    dataOut = de2bi(rxSym,k);
        
    % Calculate the number of bit errors
    nErrors = biterr(dataIn,dataOut);
        
    % Increment the error and bit counters
    numErrs = numErrs + nErrors;
    numBits = numBits + numSymPerFrame*k;
    
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

% MATLAB PROGRAM <Ex11_3.m>
% Este programa efetua a simulação de sinalização CDMA-DS de múltiplus usuários 
% com QPSK coerente para 4 usuários

%clear;clf
Ldata=10000; %comprimento de dados na simulação;Deve ser divisível por 8
Lc=31;% fator de espelhamento versus taxa de dados
% Número de usuários = 4;
% Geração de símbolos de modulação QPSK
data_sym=2*round(rand(Ldata,4))-1+j*(2*round(rand(Ldata,4))-1);

% Seleciona 4 códigos de espelhamento (Código Gold de comprimento 11)
gold31code;
pcode=GPN;
% Códigos de espelhamento estão na matriz pcode de 31x4
PowerMat=diag(sqrt([1 1 1 1]));
pcodew=pcode*PowerMat;
% Espalha agora
x_in = kron(data_sym(:,l),pcodew(:,1))+kron(data_sym(:,2),pcodew(:,2))+...
kron(data_sym(:,3),pcodew(:,3))+kron(data_sym(:,4),pcodew(:,4));

% Potência de sinal da entrada do canal é 2*Lc

%Geração do ruído
noiseq=randn(Ldata*Lc,1)+j*randn(Ldata*Lc,1); %Potência é 2


BER1=[];
BER2=[];
BER3=[];
BER4=[];
BER_az=[];

for i=1:12,
    Eb2N(i)=(i-1);                          % (Eb/N em dB)
    Vat_n=Lc/(2*Eb2N_num);
    signois=sqrt(Var_n);
    awgnois=signois*noiseq;
    % Adiciona ruído aos sinis de saída do canal
    y_out=x_in+awgnois;
    y_out=reshape(y_out,Lc,Ldata).'; clear y_out awgnois;
    
    % Desespalhar primeiro
    z_out=y_out*pcode;
    
    % Decisão baseada no sinal das amostras
    dec=sign(real(z_out))+j*sign(imag(z_out));
    % Comparar com dados originais para calcular BER1
    BER1=[BER1;sum([real(data_sym(:,1))'=real(dec(:,1));...
        imag(data_sym(:,1))'=imag(dec(:,1))])/(2*Ldata)];
    BER2=[BER2;sum([real(data_sym(:,2))'=real(dec(:,2));...
        imag(data_sym(:,2))'=imag(dec(:,2))])/(2*Ldata)];
    BER3=[BER3;sum([real(data_sym(:,3))'=real(dec(:,3));...
        imag(data_sym(:,3))'=imag(dec(:,3))])/(2*Ldata)];
    BER4=[BER4;sum([real(data_sym(:,4))'=real(dec(:,4));...
        imag(data_sym(:,4))'=imag(dec(:,4))])/(2*Ldata)];    
    BER_az=[BER_az;0.5*erfc(sqrt(Eb2N_num))];              % analítico
end
BER=[BER1 BER2 BER3 BER4];
figure(1)
figber=semilogy(Eb2N,BER_az,'k-',Eb2N,BER1,'k-o',Eb2N,BER2,'k-s',...
     Eb2N,BER3,'k-v',Eb2N,BER4,'k-*');
legend('Apenas um usuário (análise)','BER do usuário 1','BER do usuário 2','BER do usuário 3','BER do usuário 4')
axis([0 12 0.99e-5 1.e0]);
set(figber,'LineWidth',2);
xlabel('E_b/N (dB)');ylabel('Taxa de erro de bit de QPSK')
title('BER de CDMA de 4 usuários com código Gold de comprimento 1');

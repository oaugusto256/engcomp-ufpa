% MATLAB PROGRAM <Ex11_4a.m>
% Este programa efetua a simulação de sistema CDMA para múltiplos usuários
% sujeito ao efeito próximo-distante devido a variações de 
% potência de Tx de usuário.
% 
% Receptores descorrelatores são
% aplicados para mitigar o efeito próximo-distante
%
%clear;clf
Ldata=100000; % comprimento dos dados na simulação; deve ser divisível por 8
Lc=31; % fator de espalhamento versus taxa de dados
%Número de usuários = 4
% Geração de símbolos da modulação QPSK
data_sym=2*round(rand(Ldata,4))-1+j*(2*round(rand(Ldata,4))-1);

% Seleciona 4 códigos de espalhamento (códigos Gold de comprimento 11)
gold31code;
pcode=GPN;
% Códigos de espalhamento, agora, na matriz pcode de 31x4
PowerMat=diag(sqrt([10 1 5 1]));
pcodew=pcode*PowerMat;
Rcor=pcodew'*pcodew;
Rinv=pinv(Rcor);
% Aplica o espalhamento
x_in=kron(data_sym(:,1),pcodew(:,1))+kron(data_sym(:,2),pcodew(:,2))+...
kron(data_sym(:,3),pcodew(:,3))+kron(data_sym(:,4),pcodew(:,4));

% Potência de sinal de entrada do canal e 2*Lc

%Geração de ruido (AWGN)
noiseq=randn(Ldata*Lc,1)+j*randn(Ldata*Lc,1); % Potência é 2

BERb2=[];
BERa2=[];
BERb4=[];
BERa4=[];
BER_az=[];
 

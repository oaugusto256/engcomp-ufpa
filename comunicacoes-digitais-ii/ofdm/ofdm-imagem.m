%%Parametros de entrada

clear all
N = 8; %Tamanho simbolo OFDM
L = 2; %Tamanho prefixo ciclico
M = 256; % Ordem da modulacao
h = [1.5 -0.5 0.5]'; %resposta ao impulso
H = fft([h; zeros(N-(L+1),1)]); % funcao de transferencia

%% Simbolos de entrada
%x = randint(8,1,M); %Gerando 8 numeros de 0 a M-1
x = imread('example-image.png');

[A,B,C] = size(x);

x1 = reshape(x,[],1);

s = qammod(x1,M); %Gerando simbolos M-QAM
s_ifft = ifft(s); %passando pela IDFT
% Esse linha abaixo deve ser melhorada caso se deseje simular varios simbolos seguidos ou diferentes valores de L. 
s_pref = [s_ifft(N-1); s_ifft(N); s_ifft]; % adicionando prefixo ciclico.

%% Passando pelo canal
s_conv = conv(s_pref,h);

% Falta adicionar AWGN11
noise = awgn(s_conv,5,'measured');

%% Recepcao
r = noise(L+1:size(x1)+L); % retirando prefixo
r_fft = fft(r); % Aplicando DFT 
% s?mbolos QAM transmitidos
%y = r_fft./H; % Simbolos QAM demodulados (sem ruido, deve ser igual a s)
y1 = qamdemod(r_fft,M);

y2 = uint8(y1);
y3 = reshape(y2,[A,B,C]);
image(y3)
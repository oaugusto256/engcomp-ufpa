%% Simulacao simples de OFDM no dominio do tempo
%% Autor: Francisco Muller

%%Parametros de entrada

pkg load communications % necessario caso Octave

N = 8; %Tamanho simbolo OFDM
L = 2; %Tamanho prefixo ciclico
M = 16; %Ordem da modulacao
h = [1 -0.5 0.3]'; %resposta ao impulso
H = fft([h; zeros(N-(L+1),1)]); % funcao de transferencia

%% Simbolos de entrada
x = randint(8,1,M); %Gerando 8 numeros de 0 a M-1
s=qammod(x,M); %Gerando simbolos M-QAM
s_ifft = ifft(s); %passando pela IDFT
% Esse linha abaixo deve ser melhorada caso se deseje simular varios simbolos seguidos ou diferentes valores de L. 
s_pref = [s_ifft(N-1); s_ifft(N); s_ifft]; % adicionando prefixo ciclico.


%% Passando pelo canal
s_conv = conv(s_pref,h);
% Falta adicionar AWGN

%% Recepcao
r = s_conv(L+1:N+L); % retirando prefixo
r_fft = fft(r); % Aplicando DFT
s % s�mbolos QAM transmitidos
y= r_fft./H % Simbolos QAM demodulados (sem ruido, deve ser igual a s)
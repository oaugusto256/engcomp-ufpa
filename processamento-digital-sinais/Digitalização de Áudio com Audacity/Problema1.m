% Universidade Federal do Pará
% Instituto de Tecnologia 
% Faculdade de Engenharia da Computação
% Processamento Digital de Sinais

% Aluno: Otávio Augusto Alves Silva
% E-mail: tavioalves@gmail.com

% Construção de um filtro digital - Problema1

clc;
clear;

a1 = 3; % Amplitude A1
a2 = 2; % Amplitude A2

teta1 = 45; 
teta2 = 30;

f1 = 5; % Frequencia do cosseno 1 
f2 = 3; % Frequencia do cosseno 2

w1 = 2*pi*f1 + teta1; % Componentes do cosseno 1
w2 = 2*pi*f2 + teta2;  % Componentes do cosseno 2

Fs = 10000; % Frequência de amostragem
Ts = 1/Fs;

t = 0:1000/Fs:100; % Tempo

x = a1*cos(w1*t) + a2*cos(w2*t) % Sinal x(t)
Px = mean(x.^2); % Potencia de x(t)


r = sqrt(Px/10) * randn(1,length(x)) % Ruido r(t) com o tamanho de x(t)
Pr = mean(r.^2); % Potencia de r(t)

RSR = 10*log10 (Px/Pr); % Relação Sinal/Ruido

q = x + r; % Soma do sinal x(t) com o ruido r(t)

X_mags = abs(fft(x)); % Verificar magnitude do espectro x(t)
R_mags = abs(fft(r)); % Verificar magnitude do espectro r(t)
Q_mags = abs(fft(q)); % Verificar magnitude do espectro q(t)

num_bins = length(X_mags);

% Apresentação do espectro de frequência dos sinais
figure(1)
subplot(411), plot([0:1/(num_bins/2 -1):1], X_mags(1:num_bins/2)); title("Sinal x(t)");
subplot(412), plot([0:1/(num_bins/2 -1):1], R_mags(1:num_bins/2)); title("Ruido r(t)");
subplot(413), plot([0:1/(num_bins/2 -1):1], Q_mags(1:num_bins/2)); title("Sinal x(t) somado ao Ruido r(t)");


[b, a] = butter(2, 0.4);    % Sabemos que o nosso sinal x(t) esta em 0.4 rad/s
[h, w] = freqz(b, a, 1024); 

y = filter(b, a, q);        % Filtramos utlizando os valores obtidos do função butter



% Utiliza-se um filtro para rejeitar frequencias de 0.1 a 0.35 rad/s
[b_stop a_stop] = butter(20, [0.1 0.35], 'stop');
qr = filter(b_stop,a_stop,x);

% Utiliza-se um filtro para rejeitar frequencias de 0.45 a 0.9 rad/s
[b_stop a_stop] = butter(20, [0.45 0.9], 'stop');
qr = filter(b_stop,a_stop,x);

% Apresentação dos resultados obtidos
figure(2)
subplot(411), plot(t, x); title("Sinal x(t)");
subplot(412), plot(t, r); title("Ruido r(t)");
subplot(413), plot(t, q); title("Sinal x(t) somado ao Ruido r(t)");
subplot(414), plot(t, qr); title("Sinal x(t) filtrado");




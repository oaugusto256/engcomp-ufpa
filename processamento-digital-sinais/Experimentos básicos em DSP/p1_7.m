% Program P1_7
% Generation of a swept frequency sinusoidal sequence
n = 0:100;
a = pi/2/100;
b = 0;
arg = a*n.*n + b*n;
x = cos(arg);
clf;
stem(n, x);
axis([0,100,-1.5,1.5]);
title('Swept-Frequency Sinusoidal Signal');
xlabel('Time index n');
ylabel('Amplitude');
grid; axis;

X_mags = abs(fft(x)); % Verificar magnitude do espectro x(t)
num_bins = length(X_mags);

figure(1);
plot([0:1/(num_bins/2 -1):1], X_mags(1:num_bins/2)); title("Sinal x(t)");
w = 0:8*pi/511:pi;

num = [0.15 0 -0.15];
den = [1 -0.5 0.7];

h = freqz(num, den, w);

w = 0:8*pi/511:pi;

num1 = [0.15 0 -0.15];
den1 = [0.7 -0.5 1];

h1 = freqz(num1, den1, w);

%Zplane plot
subplot(211)
zplane(num,den);
title('zplane para H(e^{j\omega})')
subplot(212)
zplane(num1,den1);
title('zplane para G(e^{j\omega})')
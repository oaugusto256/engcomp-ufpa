pkg load signal;

num = [2 5 9 5 3];den = [5 45 2 1 1];
[h,w]= freqz(num, den);
[z,p,k] = tf2zp(num,den);

sos = zp2sos(z,p,k);
disp('Factored form');
disp(sos);

disp('Zeros:');
disp(z);

disp('Polos:');
disp(p);

figure(1)
subplot(2,1,1)
zplane(num,den);
title('Transformada Z atraves dos coeficientes do num e den');
subplot(2,1,2)
zplane(z,p);
title('Transformada Z atraves de polos e zeros');

% Program P3_1
% Evaluation of the DTFT
clf;
% Compute the frequency samples of the DTFT

w = 0:8*pi/511:pi;

num1 = [0 1 -1.2 1];
den1 = [1 -1.3 1.04 -0.222];

h1 = grpdelay(num1, den1, w);

% Plot the DTFT
figure(1);
subplot(1,1,1)
plot(w/pi,abs(h1));grid
xlabel('Frequency');
ylabel('Delay');



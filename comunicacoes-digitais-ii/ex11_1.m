% MATLAB PROGRAM <Ex11 1.m>
% Este programa efetua a simulaçãode sinalização FHSS com
% detecção não coerente de FSK.
% O sinal interferente bloqueará 1 das L bandas de frequências e
% pode ser ligado ou desligado fornecendo o valor de entrada janning=l ou
% Detecção MFSK não coerente 0
% requer apenas a comparação das magnitudes dos bin de frequência

clear; clf;
n = 10000; % Número de símbolos de dados na simulação
L = 8;     % Número de bandas de frequências
Lh = 1;    % Número de saltos por símbolo (bit)
m = 1;     % Número de usuários

% Geração dos bits de informação
s_data = round(rand(n, m));

% Liga ou desliga a interferência parcial
jamming = input('interferência=? (Entre 1 para Sim, 0 para Não)');

% Geração de fases aleatórias nas duas frequências
xbase1 = [exp(j*2*pi*rand(Lh*n,1))];
xbase0 = [exp(j*2*pi*rand(Lh*n,1))];

% Modulação de duas frequências ortogonais
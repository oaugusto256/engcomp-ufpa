pkg load image

clc;
clear;

i = imread('moedas.JPEG');
im_original = rgb2gray(i);

im_salt_pepper_005 = imnoise(im_original,'salt & pepper',0.005);
im_salt_pepper_06 = imnoise(im_original,'salt & pepper',0.06);

im_gaussian_001 = imnoise(im_original,'gaussian',0,0.001); 
im_gaussian_03 = imnoise(im_original,'gaussian',0,0.03);

% ------------------------------------- Salt & Pepper com 0.005 -------------------------------------
error= im_original - im_salt_pepper_005; %imagem de erro
MSE= mean(error(:).^2); %error(:) eh um vetor
PSNR = 10*log10(255^2/MSE); %valor em dB

printf('\t\tRuido SALT & Pepper com 0.005 de densidade\n');
printf('Sem filtragem: %d\n', PSNR);

M = 3;
f = fspecial('average', M);
media = filter2(f, im_salt_pepper_005);
mediana = medfilt2(im_salt_pepper_005,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 5;
f = fspecial('average', M);
media = filter2(f, im_salt_pepper_005);
mediana = medfilt2(im_salt_pepper_005,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 7;
f = fspecial('average', M);
media = filter2(f, im_salt_pepper_005);
mediana = medfilt2(im_salt_pepper_005,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

printf('\n\n');

% ------------------------------------- Salt & Pepper com 0.06 -------------------------------------
error= im_original - im_salt_pepper_06; %imagem de erro
MSE= mean(error(:).^2); %error(:) eh um vetor
PSNR = 10*log10(255^2/MSE); %valor em dB

printf('\t\tRuido SALT & Pepper com 0.06 de densidade\n');
printf('Sem filtragem: %d\n', PSNR);

M = 3;
f = fspecial('average', M);
media = filter2(f, im_salt_pepper_06);
mediana = medfilt2(im_salt_pepper_06,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 5;
f = fspecial('average', M);
media = filter2(f, im_salt_pepper_06);
mediana = medfilt2(im_salt_pepper_06,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 7;
f = fspecial('average', M);
media = filter2(f, im_salt_pepper_06);
mediana = medfilt2(im_salt_pepper_06,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

printf('\n\n');

% ------------------------------------- Gaussiano com 0.001 de variancia -------------------------------------
error= im_original - im_gaussian_001; %imagem de erro
MSE= mean(error(:).^2); %error(:) eh um vetor
PSNR = 10*log10(255^2/MSE); %valor em dB

printf('\t\tRuido Gaussiano com 0.001 de variancia\n');
printf('Sem filtragem: %d\n', PSNR);

M = 3;
f = fspecial('average', M);
media = filter2(f, im_gaussian_001);
mediana = medfilt2(im_gaussian_001,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 5;
f = fspecial('average', M);
media = filter2(f, im_gaussian_001);
mediana = medfilt2(im_gaussian_001,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 7;
f = fspecial('average', M);
media = filter2(f, im_gaussian_001);
mediana = medfilt2(im_gaussian_001,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

printf('\n\n');

% ------------------------------------- Gaussiano com 0.03 de variancia -------------------------------------
error= im_original - im_gaussian_03; %imagem de erro
MSE= mean(error(:).^2); %error(:) eh um vetor
PSNR = 10*log10(255^2/MSE); %valor em dB

printf('\t\tRuido Gaussiano com 0.03 de variancia\n');
printf('Sem filtragem: %d\n', PSNR);

M = 3;
f = fspecial('average', M);
media = filter2(f, im_gaussian_03);
mediana = medfilt2(im_gaussian_03,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 5;
f = fspecial('average', M);
media = filter2(f, im_gaussian_03);
mediana = medfilt2(im_gaussian_03,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

M = 7;
f = fspecial('average', M);
media = filter2(f, im_gaussian_03);
mediana = medfilt2(im_gaussian_03,[M M]);

error_media= im_original - media; %imagem de erro
MSE_media= mean(error_media(:).^2); %error(:) eh um vetor
PSNR_media = 10*log10(255^2/MSE_media); %valor em dB

error_mediana = im_original - mediana; %imagem de erro
MSE_mediana = mean(error_mediana(:).^2); %error(:) eh um vetor
PSNR_mediana = 10*log10(255^2/MSE_mediana); %valor em dB

printf('M = %d, PSNRs: Media %d, Mediana: %d\n', M,PSNR_media, PSNR_mediana);

imshow(im_original), title('Original Image');
figure, imshow(im_salt_pepper_06), title('Salt & Pepper 0.06 Image');
figure, imshow(im_salt_pepper_005), title('Salt & Pepper 0.005 Image');
figure, imshow(im_gaussian_001), title('Gaussian 0.001 Image');
figure, imshow(im_gaussian_03), title('Gaussian 0.03   Image');

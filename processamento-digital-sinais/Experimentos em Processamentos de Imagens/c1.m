%retirado de http://www.mathworks.com/help/images/filter-images-using-predefined-filters.html
pkg load image

I = imread('moon.tif');
h = fspecial('unsharp')
I2 = imfilter(I,h);
imshow(I), title('Original Image')
figure, imshow(I2), title('Filtered Image')
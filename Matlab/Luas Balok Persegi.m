clear all;
clc;
%------------------------------------
%Program LATIHAN
%Menghitung Luas Permukaan Balok persegi
%------------------------------------
disp(' /--------------------------------------------|');
disp('\   Volume dan Luas Permukaan Balok persegi   ||');
disp(' \--------------------------------------------|');
panjang=input('Masukan Panjangnya :');
lebar=input('Masukan Lebarnya :');
tinggi=input('Masukan Tingginya :');
luas=panjang*lebar*tinggi;
disp(['Luasnya adalah = ' num2str(luas)]);
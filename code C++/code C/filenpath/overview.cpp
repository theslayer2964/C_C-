// c++:
// file: ghi nhung z` sau khi nhan F9, xuat ra monitor va save
// ifstream : lop, funtion: ho tro tu file vao chuong trinh. --> cin
// ofstream : help, ghi du lieu tu chuong trinh vao file. --> cout
// c:
// path : cach 1 : C:\\Users\\Sony Vaio\\Desktop\\vít code\\file n path ("\\")
//        cach 2 : C:/Users/Sony Vaio/Desktop/vít code/file n path  ( / nguoc lại)

// w : open + delete old data ,W+ : open + no delete + ghi de len old data
// r : read only , r+ : read + write
// a, a+ : add vao cui file, no change old data

#include <stdio.h>
#include <stdlib.h>
void getuseriput(FILE *fout) // ghi thong tin trong file
{
    while (1) // = while(true) : lap lai vo han
    {

    }
}

int main ()
{
    FILE *fin;  // doc du lieu tu file
    FILE *fout; // ghi du liu tu file

    fout = fopen("C:/Users/Sony Vaio/Desktop/vít code/file n path/ahihihaha.txt","w");
    if(fout != NULL)
    {
        getuseriput(fin); // ghi file
        fclose(fout);   // close this file
    }
    return 0;
}

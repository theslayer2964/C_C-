#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
struct date
{
    int ngay;
    int thang;
    int nam;
};
struct sinhvien
{
    string hoten;
    string maso;
    date ngaysinh;
    float dim;
};
void docngaythangnam(date &d,ifstream &filein)
{
    filein >> d.ngay;
    filein.seekg(1, ios::cur);
    filein >> d.thang;
    filein.seekg(1, ios::cur);
    filein >> d.nam;
}
void doc1sinhvien(sinhvien &sv,ifstream &filein)
{
    getline(filein,sv.hoten,',');
    getline(filein,sv.maso,',');
    docngaythangnam(sv.ngaysinh,filein);
    filein.seekg(2, ios::cur);
    filein >> sv.dim;
}
void doctatcasinhvien(sinhvien &sv,ifstream &filein)
{

}
struct node
{
    sinhvien data;  // change
    struct node *pnext;
};
struct danhsach
{
    node *phead;
    node *ptail;
};
void input(danhsach &l)
{
    l.phead == NULL;
    l.ptail == NULL;
}
node *tao1node(sinhvien x)
{
    node *ptemp = new node;
    ptemp->data = x;
    ptemp->pnext=NULL;
    return ptemp;
}
void themdau(danhsach &l)
{
    sinhvien x;
    cout << "\nNhap x: ";
    node *ptemp = tao1node(x);
    if(l.phead == NULL)
    {
        l.phead = l.ptail = NULL;
    }
    else
    {
        ptemp->pnext=l.phead;
        l.phead=ptemp;
    }
}
void xuat1sinhvien(sinhvien sv)
{
    cout << "\nHo ten: " << sv.hoten;
    cout << "\nMSSV: " << sv.maso;
    cout << "\nNgay thang nam sinh: " << sv.ngaysinh.ngay << "/" << sv.ngaysinh.ngay << "/" << sv.ngaysinh.nam;
    cout << "\nDim tb: " << sv.dim;
}
int main ()
{
    sinhvien sv;
    ifstream filein;
    filein.open("C://Users//Sony Vaio//Desktop//code C++//danhsachlienket//sinhvien.txt",ios::in);
    doc1sinhvien(sv,filein);
    xuat1sinhvien(sv);
    return 0;
}

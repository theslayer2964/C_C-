// struct lồng trong struct + pointer
#include <iostream>
using namespace std;
struct phanso
{
    int tu;
    int mau;
};
void nhap(phanso &a)
{
    cout <<"\ntu: ";
    cin >> a.tu;
    cout <<"\nmau: ";
    cin >>a.mau;
}
void xuat(phanso a)
{
    cout << "\n"<< a.tu << "/" << a.mau ;
}
//dùng 1 struct nữa (kết hợp vs con trỏ): mảng động
struct danhsach
{
    phanso *p; // mảng động chua phân số
    int b;
};
void input(danhsach &ds)
{
    cout << "\nSo phan tu: ";
    cin >> ds.b;
    for(int i=0;i<ds.b;i++)
    {
        nhap(ds.p[i]);
    }
}
void output(danhsach ds)
{
    cout << "\ndanh sach: ";
    for(int i=0;i<ds.b;i++)
    {
        xuat(ds.p[i]);
    }
}

phanso tong(phanso a,phanso b)
{
    phanso temp;
    temp.tu = a.tu*b.mau + b.tu*a.mau;
    temp.mau = a.mau*b.mau;
    return temp;
}
int ucln(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else b=b-a;
    }
    return a;
}
phanso rutgon(phanso &a)
{
    int k=ucln(a.tu,a.mau);
    a.tu = a.tu /k;
    a.mau = a.mau / k;
    return a;
}
phanso tongmang(danhsach ds)
{
    phanso k;
    k.tu=0;
    k.mau=1;
    for(int i=0;i<ds.b;i++)
    {
        k =tong(k,ds.p[i]);
    }
    rutgon(k);
    return k;
}

int main ()
{
    danhsach ds;
    ds.p = new phanso [ds.b];
    input(ds);
    output(ds);
    phanso k=tongmang(ds);
    cout << "\ntong chinh la: ";
    xuat(k);
    return 0;
}


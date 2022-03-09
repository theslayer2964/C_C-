// Nạp chồng toán tử (OPERATOR LOADING)
// toán tử: + - * / % && ||  << >> ...
// nạp chồng: xây dựng dấu "+", "-" ..... --> wow

#include <iostream>
#include <fstream>
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
// Nạp vào để có thể cin >> lun.
// istream: dữ liệu đi vào
istream &operator >>(istream &is,phanso &a)
{
    cout <<"\ntu: ";
    is >> a.tu;
    cout <<"\nmau: ";
    is >> a.mau;
    return is;
}
// nạp vào để có the cout <<
// ostream : dữ liệu đi ra.
ostream &operator <<(ostream &os,phanso &a)
{
    cout <<"\n" << a.tu <<"/"<< a.mau;
}
// không có "&"
phanso operator +(phanso &a,phanso &b)
{
    phanso temp;
    temp.tu = a.tu*b.mau + b.tu*a.mau;
    temp.mau = a.mau*b.mau;
    return temp;
}

int main ()
{
    phanso a;
    phanso b;
    cin >> a;
    cin >> b;
    cout << a;
    cout << b;
    phanso temp;
    temp = a+b;
    cout << "\n" << a.tu << "/" << a.mau << "+" << b.tu << "/" << b.mau << " = " << temp;
    return 0;
}

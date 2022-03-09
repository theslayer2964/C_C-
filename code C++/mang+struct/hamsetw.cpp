// setw: hiệu chỉnh cách mà chũi xuất hịn
// setw(<int>) : cách ra <int> vị trí

#include <iostream>
using namespace std;
#include <iomanip> // thư vịn
#include <string>
struct hosinh
{
    string hoten[100];
    string mssv[100];
    float diem;
};
void nhap1con(hosinh &a)
{
    fflush(stdin);
    cout << "\nho ten: ";
    getline(cin, a.hoten);
    cout << "\nma so: ";
  //  fflush(stdin);
    getline(cin, a.mssv);
    cout << "\ndiem: ";
    cin >> a.diem;
}
void input(hosinh a,int &n)
{
    cout << "so hs: " ;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        nhap1con(a[i]);
    }
}
void xuat1con(hosinh a)
{
    cout << "\nho ten: " << a.hoten;
    cout << "\nma so: " << a.mssv;
    cout << "\ndiem: " << a.diem;
}
void output(hosinh a,int n)
{
    cout << "\ndanh sach chinh la: "
    for(int i=0;i<n;i++)
    {
        xuat1con(a[i]);
    }
}

int main ()
{
    string s="lalameomeo";
    //cout << setw(20) << s << "."; // phai qua trai
    // trai qua phai:  cout << left << setw(20) <<s <<".";
    hosinh a[100];
    int n;
    input(a,n);
    output(a,n);
    return 0;
}

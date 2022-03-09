#include <iostream>
using namespace std;
#include <fstream>
struct phanso
{
    int tu;
    int mau;
};
struct danhsach
{
    phanso a[100];
    int n;
};
int ucln(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else b=b-a;
    }
    return a;
}
phanso rutgonphanso(phanso &a)
{
    int k=ucln(a.tu,a.mau);
    a.tu=a.tu/k;
    a.mau=a.mau/k;
    return a;
}
void nhap1con(phanso &ps,ifstream &filein)
{
        filein >> ps.tu;
        char x;
        filein >> x;
        filein >> ps.mau;
}
void docfile(danhsach &ds,ifstream &filein)
{
    filein >> ds.n;
    for(int i=0;i<ds.n;i++)
    {
        nhap1con(ds.a[i],filein);
    }
}
void xuatdanhsach(danhsach ds)
{
    cout << "\nDay chinh la: ";
    cout << ds.n <<endl;
    for(int i=0;i<ds.n;i++)
    {
        rutgonphanso(ds.a[i]);
        cout << ds.a[i].tu << "/" << ds.a[i].mau<<endl;
    }
}
void solonnhut(danhsach ds)
{
    phanso l;
    l.tu=0;
    l.mau=1;
    for(int i=0;i<ds.n;i++)
    {
        if(l.tu*ds.a[i].mau < ds.a[i].tu*l.mau)
            l=ds.a[i];
    }
    cout << "\nso lon nhut: " << l.tu << "/" << l.mau;
}

int main ()
{
    ifstream filein;
    int n=0;
    danhsach ds;
    filein.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\123.txt",ios_base::in);
    docfile(ds,filein);
    xuatdanhsach(ds);
    solonnhut(ds);
    return 0;
}

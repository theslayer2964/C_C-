#include <iostream>
using namespace std;
void input(int *a,int &n)
{
    for(int i=0;i<n;i++)
    {
        cout << "\na [ " << i << "] = ";
        cin >> *(a+i);
    }
}
void output(int *a,int n)
{
    cout << "\nday gom: ";
    for(int i=0;i<n;i++)
    {
        cout << *(a+i)<< " ";
    }
}
void gopmang(int *a,int n,int *b,int m,int *&c,int &p)
{
    c=new int[m+n];
    p=0;
    for(int i=0;i<n;i++)
    {
        c[p]=a[i];
        p++;
    }
    delete[] a;
    for(int i=0;i<m;i++)
    {
        c[p]=b[i];
        p++;
    }
    delete[] b;
    output(c,p);
}

int main()
{
    int *a= NULL,*b=NULL,*c=NULL;
    int n,m,p;
    a= new int;
    cout << "\nmang a, n= ";
    cin >> n;
    input(a,n);
    output(a,n);
    b= new int;
    cout << "\nmang b, m= ";
    cin >> m;
    input(b,m);
    output(b,m);
    gopmang(a,n,b,m,c,p);
    return 0;
}

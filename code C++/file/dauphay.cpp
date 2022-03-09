#include <iostream>
using namespace std;
#include <fstream>
#include <string>
void input(int *a,int &n,ifstream &f)
{
    f.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\1phayphayphay.txt",ios_base::in);
    while(f.eof()!= true)
    {
        f >> a[n];
        char x;
        f >> x;
        n++;
    }
}
void output(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] <<" ";
    }
}
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
void uclnchui(int *a,int n,ofstream &fileout)
{
    int k=a[0];
    for(int i=0;i<n;i++)
    {
        k=ucln(k,a[i]);
    }
    //return k;
    cout << "\nucln: " << k;
    fileout.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\2phayphayphay.txt",ios_base::out);
        fileout << k;
}
int bcnn(int a,int b)
{
    return (a*b)/ucln(a,b);
}
void bcnnchui(int *a,int n,ofstream &fileout2)
{
    int k=a[0];
    for(int i=1;i<n;i++)
    {
        k=bcnn(k,a[i]);
    }
    fileout2.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\3phayphayphay.txt",ios_base::out);
    cout << "\nbcnn: "<<k;
    fileout2 <<k;
}

int main ()
{
    ifstream f;
    int n=0;
    int a[100];
    input(a,n,f);
    output(a,n);
    ofstream l,j;
    uclnchui(a,n,l);
    bcnnchui(a,n,j);
    return 0;
}

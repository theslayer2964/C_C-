#include <iostream>
#include <math.h>
using namespace std;
#include <fstream>
void input(int *a,int &n,ifstream &f)
{
    f.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\789.txt",ios_base::in);
    if(f.fail()== true)
    {
        cout << "cannot find this file";
    }
    while(f.eof() == false)
    {
        f >> a[n];
        n++;
    }
}
void output(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}
bool amstrong(int n)
{
    int dem=0;
    int k=n;
    int l=n;
    while(k>0)
    {
        dem++;
        k=k/10;
    }
    int tong=0;
    while(n>0)
    {
        tong=tong + pow(n%10,dem);
        n=n/10;
    }
    if(tong==l)
        return true;
        return false;
}
void ghivaofile(int *a,int n,ofstream &fileout)
{
    for(int i=0;i<n;i++)
    {
        if(amstrong(a[i])== true)
        {
            fileout << a[i] << " ";
        }
    }
}
int main ()
{
    ifstream filein;
    int a[100];
    int n=0;
    input(a,n,filein);
    output(a,n);
    ofstream fileout;
    fileout.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\2012.txt",ios_base::out);
    ghivaofile(a,n,fileout);
    filein.close();
    fileout.close();
    return 0;
}


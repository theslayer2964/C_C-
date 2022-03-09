#include <iostream>
using namespace std;
#include <fstream>
bool testngto(int i)
{
        int dem=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                dem++;
            }
        }
        if(dem==2)
        {
            return true;
        }
        else return false;
}


int main ()
{
    ifstream filein;
    filein.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\123.txt",ios_base::in);
    if(filein.fail()== true)
    {
        cout << "cannot find this file";
        return 0;
    }
    int a[100];
    int n;
    filein >> n; // đọc file trong C++, đơn giản hơn C nhìu
    for(int i=0;i<n;i++)
    {
        filein >> a[i];
    }
    ofstream fileout;
    fileout.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\456.txt",ios_base::out);
    for(int i=0;i<n;i++)
    {
        if(testngto(a[i])== true)
            fileout << a[i] <<" ";
    }
    return 0;
}

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
    if(filein.fail()==true)
    {
        cout << "\ncant find this file";
        return 0;
    }
    int x;
    filein >> x;
    ofstream fileout;
    fileout.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\456.txt",ios_base::out);
    if(testngto(x)==true)
        {fileout << "true";}
    else {fileout << "false";}
    fileout.close();
    filein.close();
    return 0;
}

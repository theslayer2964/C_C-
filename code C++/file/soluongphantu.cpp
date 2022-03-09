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
    filein.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\789.txt",ios_base::in);
    int dem=0,i=0;
    int a[100];
    // EOF: end of file. đọc cho đến cúi file lun. đây là hàm kiu bool
    while(filein.eof()==false) // <==> !filein.eof()== true
    {
        filein >> a[i];
        i++;
        dem++;
    }
    ofstream fileout;
    fileout.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\1011.txt",ios_base::out);
    for(int i=0;i<dem;i++)
    {
        if(testngto(a[i])==true)
        {
            fileout << a[i] << " ";
        }
    }
    fileout.close();
    return 0;
}

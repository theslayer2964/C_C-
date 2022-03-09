#include <iostream>
using namespace std;
#include <fstream>
#include <string>
bool kiemtrasongto(int n)
{
    for(int i=1;i<=n;i++)
    {
        int dem=0;
        if(n%i==0)
        {
            dem++;
        }
        if(dem==2)
            return true;
        else return false;
    }
}

int main ()
{
    ifstream filein;
    filein.open ("C:\\Users\\Sony Vaio\\Desktop\\input.txt",ios_base::in);
    int n;
    filein >> n;
    // mở ra và đọc ---> chưa ghi dô được
    // mở ra và gghi ----> ghi dô
    ofstream fileout;
    fileout.open ("C:\\Users\\Sony Vaio\\Desktop\\ketqua.txt",ios_base::in);
    if(kiemtrasongto(n)== true)
        fileout << "true"  ;
    else fileout << "false"  ;
    fileout.close();
    filein.close();
    // mở 2 file ---> đóng 2
    return 0;
}


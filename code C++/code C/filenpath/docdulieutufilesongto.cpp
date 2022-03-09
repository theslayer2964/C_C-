#include <iostream>
using namesapce std;
#include <fstream>
#include <string>
bool kiemtrasongto(int x)
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
    ifstream Filein;
    filein.open ("C:\\Users\\Sony Vaio\\Desktop\\input.txt",ios_base::in);
    int x;
    Filein >> x;
    // mở ra và đọc ---> chưa ghi dô được
    // mở ra và gghi ----> ghi dô
    ofstream fileout;
    fileout.open ()("C:\\Users\\Sony Vaio\\Desktop\\ketqua.txt",ios_base::in);
    if(kiemtrasongto(x)== true)
    {
        cout << "true" << endl;
    }
    else count << "false"<< endl;
    filein.close;
    return 0;
}

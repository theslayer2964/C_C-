#include <iostream>
using namespace std;
#define max_hang 100
#define max_cot 100
void input( int a[][max_cot],int &hang,int &cot)
{
    cout << "\nhang: ";
    cin >> hang;
    cout << "\ncot: ";
    cin >> cot;
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<cot;j++)
        {
            cout << "\na[ "<< i <<"][ "<<j <<"] = ";
            cin >> a[i][j];
        }
    }
}
void output(int a[][max_cot],int hang,int cot)
{
    cout << "\nDay chinh la: \n";
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<cot;j++)
        {
            cout << a[i][j]<< " ";
        }
            cout << endl;
    }
}
int songto(int n)
{
        int dem=0;
        for(int j=1;j<=n;j++)
        {
            if(n%j==0)
                dem++;
        }
        if(dem==2)
            return 1;
            else return 0;
}
int tongngto(int a[][max_cot],int hang,int cot)
{
    int tong=0;
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<cot;j++)
        {
            if(songto(a[i][j])==1)
                tong+=a[i][j];
        }
    }
    return tong;
}
void tinhtongtunghang(int a[][max_cot],int hang,int cot)
{
    for(int i=0;i<hang;i++)
    {
        int s=0;
        for(int j=0;j<cot;j++)
        {
            s+=a[i][j];
        }
            cout <<"\ntong hang thu " << i << " chinh la: " << s;
    }
}
void tinhtongtungcot(int a[][max_cot],int hang,int cot)
{
    for(int i=0;i<cot;i++)
    {
        int s=0;
        for(int j=0;j<hang;j++)
        {
            s+=a[j][i];
        }
            cout <<"\ntong cot thu " << i << " chinh la: " << s;
    }
}
int duongcheochinh(int a[][max_cot],int hang,int cot)
{
    int s=0;
    for(int i=0;i<cot;i++)
    {
        for(int j=0;j<hang;j++)
        {
            if(i==j)
            {
                s+=a[j][i];
            }
        }
    }
    cout << "\nTong duong cheo chinh la: "<< s;
}
int duongcheophu(int a[][max_cot],int hang,int cot)
{
    int s=0;
    for(int i=0;i<cot;i++)
    {
        for(int j=0;j<hang;j++)
        {
            if((i+j)==(hang-1))
            {
                s+=a[j][i];
            }
        }
    }
    cout << "\nTong duong cheo phu la: "<< s;
}

int main ()
{
    int a[max_hang][max_cot];
    int hang, cot;
    input(a,hang,cot);
    output(a,hang,cot);
    cout <<"\nTong so ngto chinh la: " << tongngto(a,hang,cot);
    tinhtongtunghang(a,hang,cot);
    tinhtongtungcot(a,hang,cot);
    duongcheochinh(a,hang,cot);
    duongcheophu(a,hang,cot);
    return 0;
}


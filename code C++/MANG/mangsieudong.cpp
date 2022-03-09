// mảng động hay mảng tĩnh vẫn phải cấp phát n trước tin
//mảng siu động: o cần nhập n lun--> wow
#include <iostream>
using namespace std;
void input(int *a,int &n)
{
    cout << "\nn= ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "\na[" << i << "] = ";
        cin >> *(a+i);
    }
}
void output(int *a,int n)
{
    cout << "\nday chinh la: ";
    for(int i=0;i<n;i++)
    {
        cout << *(a+i)<<" ";
    }
}
void capphatvungnhomoi(int *&a,int moi,int cu)
{
    int *temp;
    temp=new int [cu];
    for(int i=0;i<cu;i++)
    {
        *(temp+i) = *(a+i);
    }
    delete[] a;
    a=new int [moi];
    for(int i=0;i<moi;i++)
    {
        *(a+i) = *(temp+i);
    }
    delete[] temp;
}
void menu(int *&a,int &n)
{
    while(true) // tương đương vs while(69) , tức là chỉ có 2 loại "==0"(false) và "!=0"(true)
    {
        cout << "\n-----------------------------MENU----------------";
        cout <<"\n1.Nhap do";
        cout <<"\n2.xuat";
        cout <<"\n3.thoat";
        cout <<"\n-----------------------------END----------------";
        int luachon;
        cout <<"\nchon cai deo z: ";
        cin >> luachon;
        switch (luachon)
        {
            case 1:
            {
                int x;
                cout << "x= ";
                cin >> x;
                if(n==0)
                {
                    a=new int ;
                }
                else
                {
                    capphatvungnhomoi(a,n+1,n);
                }
                a[n]=x;
                n++;
            }break;
            case 2:
            {
                output(a,n);
            }break;
            case 3:
                {
                    return ;
                }break;
        }
    }
}

int main ()
{
    int *a=NULL; // cấp phát con trỏ vùng nhớ 0
    int n=0;
    menu(a,n);
    delete[] a;
    return 0;
}

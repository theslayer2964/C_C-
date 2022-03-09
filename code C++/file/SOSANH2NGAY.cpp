#include <stdio.h>
#include <string.h>
#include <math.h>
void kiemtrathang(char a[])
{
    int l=0,muthang=0;
    for(int i=4;i>=3;i--)
    {
        l=l+pow(10,muthang)*(a[i]-48);
        muthang++;
    }
    if (l>=13)
    {
        printf("\nNhap lai: ");
        gets(a);
        kiemtrathang(a);
    }
}
int tinhngay(char a[])
{
    int s=0,munam=0;
    for(int i=9;i>=6;i--)
    {
        s=s+pow(10,munam)*(a[i]-48);
        munam++;
    }
    s=s*365;
    int l=0,muthang=0;

    for(int i=4;i>=3;i--)
    {
        l=l+pow(10,muthang)*(a[i]-48);
        muthang++;
    }
    kiemtrathang(a);
    l=l*30;
    int k=0,mungay=0;
    for(int i=1;i>=0;i--)
    {
        s=s+pow(10,mungay)*(a[i]-48);
        mungay++;
    }
    return s+l+k;
}


int main()
{
    char ngayhetdate[100];
    char ngay_ht[100];
    printf("\nNgay hum nay: ");
    gets(ngay_ht);
    fflush(stdin);
    printf("\nNgay het date: ");
    gets(ngayhetdate);
    printf("\nNgay hum nay: %d",tinhngay(ngay_ht));
    printf("\nngay het date: %d",tinhngay(ngayhetdate));
    if(tinhngay(ngayhetdate)>=tinhngay(ngay_ht))
    {
        printf("\ncon han");
    }
    else printf("\nhet han");
        return 0;

}

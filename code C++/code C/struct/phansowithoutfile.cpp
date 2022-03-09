#include <stdio.h>
#include <stdlib.h>
struct ps
{
    int tu;
    int mau;
};
void nhapPS(ps a[],int &n)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\ntu ");scanf("%d",&a[i].tu);
        printf("\nmau ");scanf("%d",&a[i].mau);
    }
}
void xuatPS(ps a[],int n)
{
    printf("\nMang gom ");
    for(int i=0;i<n;i++)
    {
        int dau;
        if(a[i].tu*a[i].mau <0)
            dau = -1;
        else dau = 1;
        printf("\n%d/%d",abs(a[i].tu)*dau,abs(a[i].mau));
    }
}
ps tinhtong2phanso(ps ps1,ps ps2)
{
    ps kq;
    kq.tu=ps1.tu*ps2.mau+ps2.tu*ps1.mau;
    kq.mau=ps1.mau*ps2.mau;
    return kq;
}
ps tinhtongmangPS(ps a[],int n)
{
    ps kq;
    kq.tu = 0;
    kq.mau =1;
    for(int i=0;i<n;i++)
    {
        kq = tinhtong2phanso(kq,a[i]);
    }
    return kq;
}
int ucln(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
            a=a-b;
            else
            b=b-a;
    }
    return a;
}
void toigian(ps a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\ntoi gian %d/%d",a[i].tu/ucln(a[i].tu,a[i].mau),a[i].mau/ucln(a[i].tu,a[i].mau));
    }
}
ps sosanhmangPS(ps a[],int n)
{
    ps lala;
    lala.tu=0;
    lala.mau=1;
    for(int i=0;i<n;i++)
    {
        if(lala.tu*a[i].mau < a[i].tu*lala.mau)
            lala=a[i];
    }
    return lala;
}
void sapxep(ps a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[j].tu*a[j-1].mau<a[j-1].tu*a[j].mau)
            {
                ps tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
            }
        }
    }
    printf("\nmang sau sap xep");
    xuatPS(a,n);
}


int main ()
{
    ps a[100];
    int n;
    nhapPS(a,n);
    xuatPS(a,n);
    toigian(a,n);
    printf("\nTong phan so %d/%d",tinhtongmangPS(a,n));
    printf("\nPhan so lon nhat cua mang %d/%d",sosanhmangPS(a,n));
    sapxep(a,n);
    return 0;
}

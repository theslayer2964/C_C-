#include <stdio.h>
#include <stdlib.h>
struct PS
{
    int tu;
    int mau;
};
void nhapphanso(FILE* fp,PS m[],int& n)
{
    printf("\nSo phan tu ");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&m[i].tu);
        fscanf(fp,"%d",&m[i].mau);
    }
}
void xuatphanso(PS m[],int n)
{
    printf("%d",n);
    for(int i=0;i<n;i++)
    {
        int dau;
        if(m[i].tu*m[i].mau <0)
            {dau= -1;
        m[i].tu= abs(m[i].tu)*dau;
        m[i].mau=abs(m[i].mau);}
        else dau=1;
        printf("\n%d/%d",m[i].tu,m[i].mau);
    }
}
PS tinhtong2phanso(PS ps1,PS ps2)
{
    PS kq;
    kq.tu=ps1.tu*ps2.mau+ps2.tu*ps1.mau;
    kq.mau=ps1.mau*ps2.mau;
    return kq;
}
PS tinhtongmangPS(PS a[],int n)
{
    PS kq;
    kq.tu = 0;
    kq.mau =1;
    for(int i=0;i<n;i++)
    {
        kq = tinhtong2phanso(kq,a[i]);
    }
    return kq;
}
PS sosanhmangPS(PS a[],int n)
{
    PS meomeo;
    meomeo.tu=0;
    meomeo.mau=1;
    for(int i=0;i<n;i++)
    {
        if( meomeo.tu*a[i].mau<meomeo.mau*a[i].tu )
            meomeo=a[i];
    }
    return meomeo;
}
void sortt(PS a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[j].tu*a[j-1].mau<a[j-1].tu*a[j].mau)
            {
                PS tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
            }
        }
    }
    printf("\nDay sau sap xep: ");
    xuatphanso(a,n);
}

int main()
{
    FILE* fp= fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","r");
    if(fp == NULL)
    {
        printf("\nCan't find this file ");
    }
    else printf("\nfile ton tai");
    PS m[10];
    int n;
    nhapphanso(fp,m,n);
    xuatphanso(m,n);
    printf("\nTong cua file %d/%d",tinhtongmangPS(m,n));
    printf("\nSo lon nhut %d/%d",sosanhmangPS(m,n));
    sortt(m,n);
    fclose(fp);
    return 0;
}


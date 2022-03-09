#include <stdio.h>
#include <string.h>
struct sach
{
    char tensach[50];
    char theloai[50];
    char tacgia[50];
    int masach;
    int soluong;
};
void nhap1quyen(sach &a)
{
        fflush(stdin);
        printf("\nten sach: ");
        gets(a.tensach);
        fflush(stdin);
        printf("\nthe loai: ");
        gets(a.theloai);
        fflush(stdin);
        printf("\ntac gia: ");
        gets(a.tacgia);
        printf("\nma sach: ");
        scanf("%d",&a.masach);
        printf("\nso luong: ");
        scanf("%d",&a.soluong);
}
void nhapsach(sach a[],int &n)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        nhap1quyen(a[i]);
    }
}
void xuat1quyen(sach a)
{
        printf("\nten sach: %s",a.tensach);
        printf("\nthe loai: %s",a.theloai);
        printf("\ntac gia: %s",a.tacgia);
        printf("\nma sach: %d",a.masach);
        printf("\nso luong: %d",a.soluong);
}
void xuatsach(sach a[],int n)
{
    for(int i=0;i<n;i++)
    {
        xuat1quyen(a[i]);
    }
}
int timtacgia(sach a[],int n,char t[])
{
    int i=0;
    int kq,dem=0;
    while (i<n)
    {
        kq = stricmp(t,a[i].tacgia);
        if(kq==0)
        {
            dem=1;
            xuat1quyen(a[i]);
        }
        i++;
    }
        if(dem==0) printf("\nKhong tim thay");
        if(dem==1) printf("\nTim thay tac gia %s",t);
//        if(dem>1) printf("\nTac gia %s, thong tin",t);
}
int tongsosach(sach a[],int n)
{
    int g=0;
    for(int i=0;i<n;i++)
    {
        g=g+a[i].soluong;
    }
    return g;
}
void themsach(sach a[],int n,sach b[],int m,sach c[],int *l)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        c[j]=a[i];
        j++;
    }
    for(int i=0;i<m;i++)
    {
        c[j]=b[i];
        j++;
    }
    *l=j;
    printf("\nSau khi them, tong so sach ta co: ");
}
void themsachc2(sach books[] ,int &n)
{
    sach t[100];
    int u,i=0,kq;
    printf("\nnhapso sach:");
    scanf("%d",&u);
    for(int i=0;i<u;i++)
    {
         fflush(stdin);
        printf("\nten sach: ");
        gets(t[i].tensach);
        fflush(stdin);
        printf("\nthe loai: ");
        gets(t[i].theloai);
        fflush(stdin);
        printf("\ntac gia: ");
        gets(t[i].tacgia);
        printf("\nma sach: ");
        scanf("%d",&t[i].masach);
        printf("\nso luong: ");
        scanf("%d",&t[i].soluong);
    }
    kq=n+u;
    while (n<kq)
    {
        books[n]=t[i];
        i++;
        n++;
    }
    printf("\nda them");
    xuatsach(books,n);
}
void hienthi(sach c[],int l)
{
    int i=0,dem=0;
    while (i<l)
    {
        if(c[i].soluong==0)
        {
            dem++;
            xuat1quyen(c[i]);
        }
        i++;
    }
        if(dem==0) printf("\nKhong tim thay dau sach het hang");
}

int main ()
{
    sach a[50],b[50],c[50];
    int n,m,l;
    char t[50];
    printf("\nSo dau sach hien co: ");
    nhapsach(a,n);
    printf("\nThong tin ve sach hien co: ");
    xuatsach(a,n);
    printf("\nNhap ten tac gia can tim: ");
    fflush(stdin);
    gets(t);
    timtacgia(a,n,t);
    printf("\nTong so quyen sach hien co: %d",tongsosach(a,n));
    printf("\nBan muon them bao nhieu dau sach: ");
    nhapsach(b,m);
    themsach(a,n,b,m,c,&l);
    xuatsach(c,l);
    printf("\nSo luong dau sach da het: ");
    hienthi(c,l);
    return 0;
}

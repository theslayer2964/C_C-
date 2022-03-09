#include <stdio.h>
#include <string.h>
struct thuoc
{
    char ten[100];
    char ngay[100];
    int soluong;
};
void motcon(thuoc &a)
{
    fflush(stdin);
    printf("\nTen thuoc ");gets(a.ten);
    fflush(stdin);
    printf("\nNgay: ");gets(a.ngay);
    fflush(stdin);
    printf("\nSo luong: ");scanf("%d",&a.soluong);
}
void input(thuoc a[],int &n)
{
    printf("\nn= ");scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        motcon(a[i]);
    }
}
void xuatmotcon(thuoc a)
{
    printf("\nTen thuoc ");puts(a.ten);
    printf("\nNgay: ");puts(a.ngay);
    printf("\nSo luong: %d",a.soluong);
}
/*void output(thuoc a[],int n)
{
    for(int i=0;i<n;i++)
    {

    }
}*/
void ngay(thuoc a[],int n, char x[])
{
    fflush(stdin);
    printf("\nNgya hom nay: ");gets(x);
    printf("\nDanh sach thuoc qua han su dung: ");
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].ngay,x));
        {
            xuatmotcon(a[i]);
        }
    }
}

int main ()
{
    thuoc a[100];
    int n;
    char x[100];
    input(a,n);
    ngay(a,n,x);

    return 0;
}

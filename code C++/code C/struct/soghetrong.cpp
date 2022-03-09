#include <stdio.h>
struct danhsach
{
    char ten[50];
    char ngaysinh[50];
    int soghe;
};
void motcon(danhsach &a)
{
    fflush(stdin);
    printf("\nTen khach hang: "); gets(a.ten);
    fflush(stdin);
    printf("\nNgay sinh: ");gets(a.ngaysinh);
    printf("\nSo ghe: ");scanf("%d",&a.soghe);
}
void kiemtra(danhsach a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j].soghe == a[i].soghe)
                {
                    printf("\nGhe da co nguoi ngoi. Xin moi nhap lai.");
                    motcon(a[j]);
                    kiemtra(a,n);
                }
        }
    }
}
void input(danhsach a[],int &n)
{
    printf("\nNhap so khach hang: ");
    scanf("%d",&n);
    while (n<=0 || n>50)
    {
        printf("\nDu lieu khong hop le. Moi nhap lai: ");
        scanf("%d",&n);
    }
    for(int i=0;i<n;i++)
    {
        motcon(a[i]);

    }
    kiemtra(a,n);
}
void inmotcon(danhsach a)
{
    printf("\nTen khach hang: ");puts(a.ten);
    printf("\nNgay sinh: ");puts(a.ngaysinh);
    printf("\nSo ghe: %d",a.soghe);
}
void output(danhsach a[],int n)
{
    for(int i=0;i<n;i++)
    {
        inmotcon(a[i]);
    }
}
void themmotcon(danhsach a[],int &n)
{
    printf("\nThem 1 con nua: ");
    danhsach them;
    motcon(them);
    int k=n+1;
    while(n<k)
    {
        a[n]=them;
        n++;
    }
    kiemtra(a,n);
    printf("\n-------------------------------");
    output(a,n);
}
void soghetrong(danhsach a[],int n)
{
    printf("\nSo ghe trong: %d",50-n);
    printf("\nDanh sach ghe trong: ");
    for(int i=1;i<51;i++)
    {
        int dem=0;
        for(int j=0;j<n;j++)
        {
            if(a[j].soghe==i)
            {
                dem++;
            }
        }
        if(dem==0)
            printf("%d ",i);
    }
}

int main ()
{
    danhsach a[50];
    int n;
    input(a,n);
    printf("\n-------------------------------");
    output(a,n);
    printf("\n-------------------------------");
    themmotcon(a,n);
    printf("\n-------------------------------");
    soghetrong(a,n);
    return 0;
}

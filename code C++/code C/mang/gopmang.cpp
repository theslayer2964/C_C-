#include <stdio.h>
void input(int a[],int &n)
{
    printf("\nN = ");scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\na[%d] = ",i);
        scanf("%d",&a[i]);
    }
}
void output(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void tachmang(int a[],int n,int b[],int m,int c[],int p)
{
    m=0,p=0;
    for(int i=0;i<3;i++)
    {
        b[m]=a[i];
        m++;
    }
    printf("\nday b: ");
    output(b,m);
    for(int i=3;i<n;i++)
    {
        c[p]=a[i];
        p++;
    }
    printf("\nday c: ");
    output(c,p);
}

int main ()
{
    int a[100],b[100],c[100];
    int n,m,p;
    input(a,n);
    output(a,n);
    tachmang(a,n,b,m,c,p);
    return 0;
}

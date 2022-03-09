// dùng đệ quy trong hàm void

#include <stdio.h>
#define sptm 100
void input(int a[],int n)
{
    if(n-1>=0)
    {
        input(a,n-1);
        printf("a[%d] = ",n);
        scanf("%d",&a[n]);
    }
}
void output(int a[],int n)
{
    if(n-1>=0)
        {
        output(a,n-1);
        printf("%d ",a[n]);
        }
}
int tinhtong(int a[],int n)
{
    if(n==0)
        return a[0];
    return a[n] + tinhtong(a,n-1);
}
/*int tinhtongsoam(int a[],int n)
{
    if(n==0)
        return a[0];
     return a[n] + tinhtongsoam(a,n-1);
     return tinhtongsoam(a,n-1);
}*/
void sapxep(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    printf("\nxep lai: ");
    output(a,n);
}
/*void songuyennto(int a[],int n)
{


}*/


int main ()
{
    int a[sptm],n;
    printf("\nNhap n: ");
    scanf("%d",&n);
    input(a,n);
    printf("\nDay gom ");
    output(a,n);
    printf("\nTinh tong mang %d",tinhtong(a,n));
   // printf("\nTinh tong so am mang %d",tinhtongsoam(a,n));
    sapxep(a,n);
    return 0;
}

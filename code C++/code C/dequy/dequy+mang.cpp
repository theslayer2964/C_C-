// xem hàm minn : gán 1 biến cho đệ quy để tít kim bộ nhớ

#include <stdio.h>
#include <stdlib.h>
#define sptm 100
void input(int a[],int &n)
{
    int r;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {

      //  printf("\na[%d] = ",i);
      //  scanf("%d",&a[i]);
      a[i]= rand();
      printf("\na[%d] = %d",i,a[i]);
    }
}
void output(int a[],int n)
{
    printf("\nDay a gom : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
// nếu n==0 return a[0] thì tức là a[n]+...+a[1]+a[0]+a[0]=> còn non lắm =)))
int tongchui(int a[],int n)
{
    if( n ==0 )
        return 0;
    return a[n-1] + tongchui(a,n-1);
}
int maxx(int a[],int n)
{
        if( n == 1)
            return a[0];
        else
            {
                if( a[n-1] > maxx(a,n-1))
                    return a[n-1];
                else return maxx(a,n-1);
            }
}
int minn(int a[],int n)
{
    if( n==1)
        return a[0];
    else
    {
        int tam= minn(a,n-1);
        if( a[n-1] < tam)
            return a[n-1];
        else return tam;
    }
}

int main ()
{
    int a[sptm],n;
    input(a,n);
    output(a,n);
    int s;
    printf("\nsum = %d",tongchui(a,n));
    printf("\nmax cua day %d",maxx(a,n));
    printf("\nmin cua day %d",minn(a,n));
    return 0;
}

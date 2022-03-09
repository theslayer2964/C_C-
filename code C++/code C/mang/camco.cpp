#include <stdio.h>
void input(int *a,int &n)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\na[%d]= ",i);
        scanf("%d",a+i);
    }
}
void output(int *a,int n)
{
    printf("\nDay:");
    for(int i=0;i<n;i++){
        printf("%d",*(a+i));
    }
}
bool kythuatdatcohieu(int *a,int n)
{
    int x;
    printf("\nx=");
    scanf("%d",&x);
    bool dem=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            dem=true;
            break;
        }
    }
    return dem;
}

int main ()
{
    int a[100];
    int n;
    input(a,n);
    output(a,n);
    if(kythuatdatcohieu(a,n)== true) printf("\nCo");
    else printf("\neo co");
    return 0;
}

#include <stdio.h>
int main ()
{
    int n,i,l,k,j;
    printf("nhap tien:");scanf("%d",&n);
    for(i=0;i<=n/50;i++)
    {
        for(l=0;l<=n/100;l++)
        {
            for(j=0;j<=n/200;j++)
            {
                if(i*50+l*100+j*200==n)
                {
                    printf("%d to 50,%d to 100, %d to 200\n",i,l,j);
                }
            }
        }
    }
    return 0;
}

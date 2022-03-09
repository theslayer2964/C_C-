#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
    int n,j,i,dem=0;
    printf("nhap n:");scanf("%d",&n);
    for (i=n;i>=2;i=i-1)
    {
        dem=0;
        for (j=2;j<=sqrt(i);j++)
        {
            if (i%j==0)
            {dem=dem+1;break;}
        }
        if (dem==0) {printf("%d",i);
        break;}
    }
    return 0;
}

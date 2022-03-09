#include <stdio.h>
int tong(int n)
{
    if(n==0)
        return 0;
    return n%10 + tong(n/10);
}

int main ()
{
    int n;
    scanf("%d",&n);
    printf("\ntong %d",tong(n));
    return 0;
}

#include <stdio.h>
int xuatnhiphan(int n)
{
    if(n>=0)
    {
        if(n/2>0)
            xuatnhiphan(n/2);
        printf("%d",n%2);
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    printf("\nnhi phan:");
    xuatnhiphan(n);
    return 0;
}

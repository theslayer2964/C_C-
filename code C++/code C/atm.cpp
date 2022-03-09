#include <stdio.h>
int main ()
{
    int n,i=0,l=0,k=0,j=0;
    scanf("%d",&n);
    while(n>=500)
    {
        i++;
        n=n-500;
    }
    while(n<500 && n>=200)
    {
        l++;
        n=n-200;
    }
    while(n<200 && n>=100)
    {
        k++;
        n=n-100;
}
    while(n>=50 && n<100)
    {
        j++;
        n=n-50;
    }
    printf("\nKet qua : %d to 500,%d to 200,%d to 100,%d to 50",i,l,k,j);
    return 0;
}

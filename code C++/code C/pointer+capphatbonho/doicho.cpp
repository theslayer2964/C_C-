#include <stdio.h>
void doicho(int m, int n)
{
    n=100;
    m=200;
    int tam=m;
    m=n;
    n=tam;
}

int main ()
{
    int n,m;
    //int n=100;
   // int m=200;
    doicho(m,n);
    printf("n= %d\nm=%d",n,m);
    return 0;
}

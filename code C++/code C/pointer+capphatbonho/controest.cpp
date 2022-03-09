#include <stdio.h>
void doicho(int *a,int *b);
void volume(int *i);

int main ()
{
    int a=100,b=599,i=6;
    doicho(&a,&b);
    printf("\na = %d, b = %d",a,b);
    volume(&i);
    printf("\nvolume = %d",i);
    return 0;
}
void doicho(int *a,int *b)
{
    int tam=*a;
    *a=*b;
    *b=tam;
}
void volume(int *i)
{
    *i=(*i)*(*i)*(*i);
}

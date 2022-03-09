#include <stdio.h>
int main ()
{
    long n=0;
    for( n=0;getchar()!= EOF;n++)
        ;
    printf("%ld",n);
    return 0;
}

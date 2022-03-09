#include <stdio.h>
#include <stdlib.h>

int main ()
{

    int *b;
    b=(int *)malloc(sizeof (int *));
    *b=4;
    printf("\n%d",*b);
    free(b);
    return 0;
}

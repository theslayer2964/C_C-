// sau bao nhiu lau cung ve duoc. thanks friend =)))

#include <stdio.h>

int main ()
{
    printf("\nhinh vuong ne\n");
    for( int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    printf("\nhinh tam giac ne\n");
    for(int i=0;i<=3;i++)
    {
        printf("\n");
        for(int j=0;j<=i;j++)
        {
            printf("* ");
        }
    }
    printf("\nhinh tam giac C2 ne\n");
    for(int i=0;i<=4;i++)
    {
        printf("\n");
        for(int j=0;j<=i;j++)
        {
            if(i==2 || i==3)
            {
                if(j!=0 && j!= i)
                    printf("  ");
                    else printf("* ");
            }
            else printf("* ");
        }
    }
}


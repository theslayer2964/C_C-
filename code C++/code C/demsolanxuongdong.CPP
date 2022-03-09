#include <stdio.h>
int main ()
{
    int c,nline=0;
    while((c=getchar()) != EOF)
          {
              if(c=='\n')
                nline++;
          }
    printf(" xuong dong %d lan",nline);
    return 0;
}

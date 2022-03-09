#include <stdio.h>
#define in 1
#define out 0
int main ()
{
    int word=0,charac=0,line=0,state=out,c;
    while((c=getchar()) != EOF)
          {
                ++charac;
              if(c == '\n')
                ++line;
              if(c=='\n' || c==' '||c=='\t')
                    state = out;
              else if(state==out)
              {
                  state=in;
                  word++;
              }
          }
    printf("%d line %d word %d character",line,word,charac);
    return 0;
}

#include <stdio.h>
#include <string.h>
void xoakitu(char s[],int vitrixoa)
{
    for(int i= vitrixoa+1; i<= strlen(s)-1;i++)
    {
        s[i-1]=s[i];
    }
    s[strlen(s)-1]='\0';
}
void xoakitukhoangtrangogiua(char s[])
{
    for(int i=0;i<= strlen(s)-1;i++)
    {
        if(s[i] == ' ' && s[i+1] == ' ')
        {
            xoakitu(s,i+1);
            i--;
        }
    }
}
int demsokitutrongday(char s[])
{
    int dem=1;
    for(int i=0;i<= strlen(s)-1;i++)
    {
        if (s[i] == ' ' && s[i+1] != ' ')
        dem++;
    }
    return dem;
}
int main ()
{
    char s[1000];
    gets(s);
   // xoakitukhoangtrangogiua(s);
    printf("\nFinal chui %s",s);
    printf("\nSo tu %d",demsokitutrongday(s));
    return 0;
}

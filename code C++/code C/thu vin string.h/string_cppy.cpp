#include <stdio.h>
#include <string.h>
void copychui(char s2[],char s1[])
{
    for(int i=0;i<strlen(s1);i++)
    {
        s2[i] = s1[i];
    }
    s2[strlen(s1)] = '\0';
}

int main ()
{
    char s1[60];
    char s2[60];
    //printf("\nNhap chui 1 ");gets(s1);
    //strcpy(s2,s1);
    //printf("\nChui 2 la %s",s2);
    //fflush(stdin);
     printf("\nNhap chui 1 ");gets(s1);
    copychui(s2,s1);
    printf("\nChui 2 cach 2 la %s",s2);
    return 0;
}

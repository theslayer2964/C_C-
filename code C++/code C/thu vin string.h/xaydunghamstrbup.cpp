// char : ham kiu char --> char* --> xau
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* copycach2(char s[])
{
    // cap phat 1 vung nho trong c cho s
     char *c= (char *)malloc(strlen(s)+1);
     for(int i=0;i< strlen(s);i++)
     {
         c[i] = s[i];
     }
     c[strlen(s)] = '\0';
     return c;
     free(c); //giai phong vung nho
}

int main ()
{
    char s[4];
    printf("\nNhap chui s ");gets(s);

    char *c= copycach2(s);
    printf("\nChui C nha,khong phai chui s dau %s",c);
    free(c);

    return 0;
}


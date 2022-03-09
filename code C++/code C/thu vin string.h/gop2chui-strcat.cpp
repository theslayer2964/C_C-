// gop 2 chui strcat(dest, srouce)

#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[200],s2[200];
    char *smoi;
    char s3[]="mot hai ba";
    printf("\ns1 ");gets(s1);
    fflush(stdin);
    printf("\ns2 ");gets(s2);
    strcat(s1,s2);
    printf("\nchui s1 sau khi thay doi %s",s1);
    smoi=strstr(s3,"hai");
    printf("\nChui moi se la %s",smoi);
    return 0;
}

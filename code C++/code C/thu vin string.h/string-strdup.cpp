// strdup : y chang copy, nhung dung con tro --> dung o nho,tiet kim dien tich vung` nho
// strdup = string + con tro + mang dong ?????
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char s[4];
    printf("\nNhap chui s ");gets(s);
    char *c= strdup(s);
    printf("\nChui C nha,khong phai chui s dau %s",c);
    free(c);

    return 0;
}

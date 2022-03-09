// strncat(char dest, const source, int n) : noi n ki tu trong chui source sang chui dest
// strncpy(char dest, const source, int n) : copy n ki tu trong chui source sang chui dest

#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100]="ahihi";
    char a[100]="hahaha";
    strncat(s,a,-2);
    printf("\n%s",s);
    return 0;
}


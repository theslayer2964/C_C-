#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100],x,temp[100];
    int dem=0;
    printf("\nNhap chui ");gets(s);
    printf("\nNhap x ");scanf("%c",&x);
    for(int i=0;i<= strlen(s);i++)
    {
        if(s[i]== x)
        {
            temp[dem] = s[i];
            dem++;
        }
   }
    temp[dem] = '\0';
    // ki tu ket thuc chu. khong hiu tai sao khong co no van khong bi loi.buc minh ghw =(((
    printf("chui la %s",temp);
    return 0;
}

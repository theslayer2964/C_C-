#include <stdio.h>
#include <string.h>
int daucachthu1(char* s)
{
    for(int i=0;i< strlen(s);i++)
    {
        if( s[i] == ' ')
            return i;
    }
    return -1;
}
int daucachthu2(char* s)
{
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if( s[i] == ' ')
            return i;
    }
    return -1;
}
// tìm ra vị trí của 2 dấu cách ở giữa tên
// xuất chữ từ 3 vị trí đó (cách 2,cách 1,0) và xuất hết ra
void hienthichui(char *s)
{
    int dau1= daucachthu1(s);
    int dau2= daucachthu2(s);
    for(int i=dau2+1;i<strlen(s);i++)
        printf("%c",s[i]);
    for(int i=dau1+1;i<dau2;i++)
        printf("%c",s[i]);
    for(int i=0;i<dau1;i++)
        printf("%c",s[i]);
}

int main ()
{
    char s[100];
    gets(s);
    hienthichui(s);
    return 0;
}

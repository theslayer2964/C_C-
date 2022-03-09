#include <stdio.h>
#include <string.h>

void xoakitu(char s[],int vitrixoa)
{
    for(int i= vitrixoa+1;i<strlen(s);i++)
    {
        s[i-1]=s[i];
    }
    s[strlen(s)-1] = '\0';
}
void xoakitudauday(char s[])
{
    while (true)
    {
        if(s[0] == ' ')
        {
            xoakitu(s,0);
        }
        else break;
    }
}
void xoakitucuiday(char s[])
{
    while (true)
    {
        if(s[strlen(s)-1] == ' ')
        {
            xoakitu(s,strlen(s)-1);
        }
        else break;
    }
}
void xoakitukhoangtrangogiua(char s[])
{
    for(int i=0;i<= strlen(s)-1;i++)
    {
        if(s[i] == ' ' && s[i+1] ==' ')
        {
            xoakitu(s,i+1);
            i--;
        }
        // bai nay special khong duoc dung else break,vi neu su dung, moi do s[0] no nhay ra khoi vong lap lun goi.
    }
}
void timrakitudainhattrongchui(char s[])
{
    for(int i=0;i<= strlen(s)-1;i++)
    {
            int dem=0;
            while(s[i] != ' ' && s[i]!= '\0')
            {
                dem++;
                i++;
            }
            if()
    }
}

int main ()
{
    char s[100];
    int i=0;
    printf("\nChui ");gets(s);
    xoakitudauday(s);
    xoakitucuiday(s);
    xoakitukhoangtrangogiua(s);
    printf("\nFinal Chui nhan duoc chinh sua %s.",s);
    //printf("\nKi tu dai nhat la %d",timrakitudainhattrongchui(s));
    timrakitudainhattrongchui(s);
    return 0;
}


#include <stdio.h>
#include <string.h>
void upper(char s[])
{
    for(int i=0;i<= strlen(s);i++)
    {
        if(s[i] >= 65 && s[i] <= 90)
        {
            s[i]=s[i]+32;
        }
    }

}
void inhoakitu(char s[],int i)
{
    if(s[i]>= 97 && s[i] <= 122)
    {
        s[i]=s[i]-32;
    }
}
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
    while (true)    //  dùng for cũng được
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
        if(s[i] == ' '  && s[i+1] ==' ')
        {
            xoakitu(s,i+1);
            i--;
        }
        // bai nay special khong duoc dung else break,vi neu su dung, moi do s[0] no nhay ra khoi vong lap lun goi.
    }
}
void inhoachudau(char s[])
{

    if(s[0]>=97 && s[0] <=122)
        s[0]=s[0]-32;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==' ' && s[i+1]>97 && s[i+1]<=122)
        {
            s[i+1]-=32;
        }
    }
}
void demsotu(char s[])
{
    int dem=1;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i] == ' ')
        {
            dem++;
        }
    }
    printf("\nSo tu trong chui %d",dem);
}
void laykitutrongchui(char s[],int &vitri,int &number)
{
    printf("\nMun lay tu vi tri nao:");scanf("%d",&vitri);
    printf("\nMun lay bao nhiu:");scanf("%d",&number);
    printf("\nLay ki tu trong chui:");
    for(int i=vitri;i<=vitri+number & i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
}


int main ()
{
    char s[100];
    int i=0,vitri,number;
    printf("\nChui ");gets(s);
    upper(s);
    inhoachudau(s);
    xoakitudauday(s);
    xoakitucuiday(s);
    xoakitukhoangtrangogiua(s);
  //  printf("\nFinal Chui nhan duoc .%s.",s);
  //  demsotu(s);
    laykitutrongchui(s,vitri,number);
    return 0;
}

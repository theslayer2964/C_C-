// rule : hoans vi 2 ki tu s[i] va s[dodai -i -1]
// dau can lam het,lam phann nua hoi : lam trong doan (dodai/2 -1)

#include <stdio.h>
#include <string.h>
void shit(char &x,char &y)
{
    char temp=x;
    x=y;
    y=temp;
}
void hoandoic2(char s[])
{
    for(int i=0;i<strlen(s)/2;i++)
    {
        shit(s[i],s[strlen(s)-i-1]);
    }
}

int main ()
{
    int i;
    char s[100];
    printf("\nNhap s : ");gets(s);
    strrev(s);
    printf("\nHoan vi %s",s);
    hoandoic2(s);
    printf("\nHoan vi cach 2 %s",s);
    return 0;
}

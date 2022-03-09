#include <stdio.h>
#include <string.h>
void xuatchuimoi(char s[],char a[],int so,int vt)
{
    for(int i=0;i<=so-1;i++)
    {
        a[i]=s[vt];
        i++;
    }
    a[so-1]='\0';
}


int main ()
{
    char s[100],a[100];
    int so,vt;
    printf("\nChui :");gets(s);
    printf("\nNhap so ki tu :");scanf("%d",&so);
    printf("\nNhap vi tri:");scanf("%d",&vt);
    xuatchuimoi(s,a,so,vt);
    printf("\n%s",a);
    return 0;
}

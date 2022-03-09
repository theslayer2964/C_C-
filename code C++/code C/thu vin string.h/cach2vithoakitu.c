#include <cstring>
#include <stdio.h>
using namespace std;
char Doichudautien(char s[])
   {

    int i;
    if(s[0]!=' ')
    {
        s[0]=s[0]-32;
        for(int i=1;i<= strlen(s);i++)
        {
            if (s[i]==' '&& s[i+1]!=' '&&s[i+1]>='a'&&s[i+1]<='z')
            {
                s[i+1]=s[i+1]-32;
            }
        }
	}
        else
            for (int i=0; i<=strlen(s);i++)
        {
            if(s[i]==' '&& s[i+1]!=' '&&s[i+1]>='a'&&s[i+1]<='z')
                {
                s[i+1]=s[i+1]-32;
            }
        }}
int main()
{
    char xau[200];
    printf("nhap:");
    gets(xau);
    Doichudautien(xau);
    puts(xau);
    return 0;
}


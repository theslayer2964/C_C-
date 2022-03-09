#include <stdio.h>
#include <string.h>
#include <math.h>
int chuyenchuithanhso(char a[])
{
    int s=0,mu=0;
    for(int i=strlen(a)-1;i>=0;i--)
    {
        s=s+pow(10,mu)*(a[i]-48);
        mu++;
    }
    return s;
}

int main ()
{
    char l[10000];
    printf("\nChui ");gets(l);
    printf("\nTong chui la %d",chuyenchuithanhso(l));
    return 0;
}

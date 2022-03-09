#include <stdio.h>
int tinhtong(int n)
{
    if(n==0)
        return 0;
    return n + tinhtong(n-1);
}
int tich(int n)
{
    if(n==1)
        return 1;
    return n*tich(n-1);
}
int lala(int n)
{
    if(n==0)
        return 0;
    return tich(n)+lala(n-1);
}
float tongphannso(int n)
{
    if(n==1)
        return 1;
    return 1.0/n+tongphannso(n-1);
}
float phanso(int n)
{
    if(n==2)
        return 0.5;
    return 1.0/n+ phanso(n-2);
}
float phanso2(int n)
{
    if(n==1)
        return 1/2;
        return 1.0/(n*(n+1)) + phanso2(n-1);
}

int main ()
{
    int n;
    scanf("%d",&n);
  //  printf("\nTong %d",tinhtong(n));
 //   printf("\nTich %d",tich(n));
    printf("\nTong cac tich %d",lala(n));
  //  printf("\nTong phan so: %.2f",tongphannso(n));
 //   printf("\nPhan so %f",phanso2(n));
    return 0;
}

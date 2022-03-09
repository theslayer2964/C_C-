#include <stdio.h>
#include <math.h>
int tongdequy(int n)
{
    if(n==1)
        return 1;
    return n + tongdequy(n-1);
}
float phansovatongdequy(int n)
{
    if(n==1)
        return 1;
    return 1.0/tongdequy(n) + phansovatongdequy(n-1);
}
// 1/2 + 3/4 + ... + (2n+1)/(2n+2)
float phanso(int n)
{
    if(n==1)
        return 0.5;
    return 1.0*(2*n+1)/(2*n+2) + phanso(n-1);
}
// 1/(1*2) + 1/(2*3) + 1/(3*4)... 1/(n*(n+1))
float phanso2(int n)
{
    if(n==1)
        return 0.5;
    return 1.0/(n*(n+1)) + phanso2(n-1);
}
// sqrt(2+sqrt(2+....sqrt(2)))))...  n lần
float canlongcan(int n) // check lai
{
    if(n==0)
        return 0;
    return sqrt(2+canlongcan(n-1));
}
// sqrt(n+sqrt(n-1+sqrt(n-2)....sqrt(1)))))...  n lần
// kq(3)= sqrt(3+ kq(2))--> kq(3)= sqrt(3+ sqrt(2+ sqrt(1+0))
// kq(2)= sqrt(2+ kq(1))--> kq(2)= sqrt(2+ sqrt(1+0))
// kq(1)= sqrt(1+ 0)
float kq(int n)
{
    if(n==1)
        return 1;
    return sqrt(n +kq(n-1));
}


int main ()
{
    int n;
    scanf("%d",&n);
   // printf("\nTong phan so : %f",phanso(n));
  //  printf("\nTong phan so loai 2 : %f",phanso2(n));
    printf("\nTong n %d",tongdequy(n));
    printf("\ntong phan so cua de quy %f",phansovatongdequy(n));

    return 0;
}

// bước 1: đếm  số các số hạng
// bước 2: tính tổng 1 chữ số trong số đó
// ví dụ: n=2 ( số 2 ở vị trí hàng trăm) , k=3 (hàng trăm) ----> tổng 2*100=200
// bước 3: xuất số ngược lại

#include <stdio.h>
int demsocacchuso(int n)
{
    if( n==0)
        return 0;
        return 1 + demsocacchuso(n/10);
}
int tinhtongcua1chuso(int n,int k)
{
    if( k>1)
        return tinhtongcua1chuso(n*10,k-1);
    return n;
}
int sodaonguoc(int n)
{
    if(n==0)
        return 0;
    int d = demsocacchuso(n);
    int v = n%10;
    int t = tinhtongcua1chuso(v,d);
    return sodaonguoc(n/10) + t;
}


int main ()
{
    int n;
    scanf("%d",&n);
    //printf("\nSo cac chu so %d",demsocacchuso(n));
    printf("\nSo dao nguoc %d",sodaonguoc(n));
    return 0;
}

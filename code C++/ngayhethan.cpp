#include<stdio.h>
struct ngay
{
    int ngay;
    int thang;
    int nam;
};
int tinhngaythang(ngay n)
{
    return n.ngay+n.thang*30 + n.nam*360;
}
bool hethan(ngay ngayhientai, ngay ngayhethan)
{
    if(tinhngaythang(ngayhientai)-tinhngaythang(ngayhethan)<=0)
        return false;
    return true;
}
int main()
{
    ngay n,x;
    printf("\nNhap hien tai:");
    scanf("%d %d %d",&n.ngay,&n.thang,&n.nam);
    printf("\nNhap het han:");
    scanf("%d %d %d",&x.ngay,&x.thang,&x.nam);
    bool z=hethan(n,x);
    if(z==false)
        printf("\nChua het han");
    else printf("\nHet");
    return 0;
}

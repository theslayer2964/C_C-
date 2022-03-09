#include <stdio.h>
#include <math.h>
int tong(int n)
{
    if(n==0)
        return 0;
    return pow(-1,n-1)*n + tong(n-1);
}
int giaithua(int n)
{
    if(n==1)
        return 1;
    return n*giaithua(n-1);
}
int tonggiaithua(int n)
{
    if(n==1)
        return 1;
    return giaithua(n) + tonggiaithua(n-1);
}
int demchuso(unsigned int n)  // unsigned : khong nhan so am.
{
    if(n==0)
        return 0;
    return 1+ demchuso(n/10);
}
int tongchuso(int n)
{
    if(n==0)
        return 0;
    return n%10 + tongchuso(n/10);
}
int demchusole(int n)
{
    if(n==0)
        return 0;
        else if(n%2!=0)
        {
                return 1+demchusole(n/10);
        }
        else if(n%2==0)
        {
            return demchusole(n/10);
        }
}
int sodautincuan(int n)
{
    if(n<=10)
        return n;
    return sodautincuan(n/10);
}
int insodaonguoc(int n,int sodaonguoc)
{
    if(n==0)
        return sodaonguoc;
    else
    {
        sodaonguoc=sodaonguoc*10 + n%10;
        return insodaonguoc(n/10,sodaonguoc);
    }
}
int chusolonnhat(int n,int maxx)
{
    if(n==0)
        return maxx;
    else
    {
        int tam=n%10;
        if(tam > maxx)
            maxx=tam;
    }
            return chusolonnhat(n/10,maxx);

}
int chusonhonhat(int n,int minn)
{
    if(n==0)
        return minn;
    else
    {
        int tam=n%10;
        if(tam < minn)
            minn = tam;
    }
    return chusonhonhat(n/10,minn);
}
bool kiemtrasotoanchan(int n)
{
    if(n==0)
        return true;
    else
    {
        int chuso=n%10;
        if(chuso%2!=0)
        return false;
        else return kiemtrasotoanchan(n/10);
    }
}

int main ()
{
    int n,sodaonguoc=0;
    int maxx=0,minn=9;
    scanf("%d",&n);
    //printf("\nTong la %d",tong(n));
    //printf("\nTong giai thua %d",tonggiaithua(n));
    //printf("\nso chu so la %d",demchuso(n));
    //printf("\nTong chu so la %d",tongchuso(n));
    //printf("\nDem chu so le %d",demchusole(n));
    //printf("\nChu so dau tin %d",sodautincuan(n));
    //printf("\nSo dao nguoc %d",insodaonguoc(n,sodaonguoc));
    //printf("\nChu so lon nhut %d",chusolonnhat(n,maxx));
    //printf("\nChu so nho nhut %d",chusonhonhat(n,minn));
    if(kiemtrasotoanchan(n)== true )printf("\ndun goi");
    else printf("\nsai bet");
    return 0;
}

#include <stdio.h>
struct ps
{
    int tu;
    int mau;
};
void input(ps &phanso)
{
    scanf("%d",&phanso.tu);
    scanf("%d",&phanso.mau);
}
/*void output(ps phanso)
{
    printf("\nphan so sau toi gian %d / %d",phanso.tu,phanso.mau);
}*/
int ucln(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
            a=a-b;
            else
            b=b-a;
    }
    return a;
}
void toigian(ps phanso)
{
    printf("\nphan so sau toi gian %d / %d",phanso.tu/ucln(phanso.tu,phanso.mau),phanso.mau/ucln(phanso.tu,phanso.mau));
}
void phansovamang(ps a[],int &n)
{

}

int main ()
{
    ps p;
    int n;
    ps a[100];
    input(p);
    toigian(p);
    return 0;
}

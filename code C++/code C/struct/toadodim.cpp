#include <stdio.h>
#include <math.h>
struct diem
{
    int x;
    int y;
};
void motdim(diem &a)
{
    scanf("%d",&a.x);
    scanf("%d",&a.y);
}
void input(diem a[],int &n)
{
    printf("\nn= ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        motdim(a[i]);
    }
}
void inmotdim(diem a)
{
    printf("\n(%d,%d)",a.x,a.y);
}
void output(diem a[],int n)
{
    for(int i=0;i<n;i++)
    {
        inmotdim(a[i]);
    }
}
int dodai(int a,int b)
{
    int g;
    g=sqrt(pow(a,2)+pow(b,2));
    return g;
}
void sapxepdiem(diem a[],int n)
{
    printf("\nSap xep cac dim tang dan: ");
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(dodai(a[j].x,a[j].y)<dodai(a[j-1].x,a[j-1].y))
            {
                diem tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
            }
        }
    }
    output(a,n);
}

void timdimxanhat(diem a[],int n)
{
    printf("\nDiem xa nhut: ");
    diem them;
    them.x=0;
    them.y=0;
    for(int i=0;i<n;i++)
    {
        if(dodai(them.x,them.y)<dodai(a[i].x,a[i].y))
        {
            them=a[i];
        }
    }
    inmotdim(them);
}

int main ()
{
    diem a[50];
    int n;
    input(a,n);
    output(a,n);
    sapxepdiem(a,n);
    timdimxanhat(a,n);
    return 0;
}

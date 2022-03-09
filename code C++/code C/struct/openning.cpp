#include <stdio.h>
#include <math.h>
int dodai(int x1,int x2,int y1,int y2)
{
    int l;
    l=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    return l;
}

int main ()
{
    struct diem
    {
        int x;
        int y;
    };
    struct hinhchunhut
    {
        struct diem traitren;
        struct diem phaiduoi;
       struct diem traiduoi;
        struct diem phaitren;
    }hcn1;
    hcn1.traitren.x = 2;
    hcn1.traitren.y = 0;
    hcn1.phaiduoi.x = 0;
    hcn1.phaiduoi.y = 4;
    hcn1.phaitren.x = hcn1.traitren.x;
    hcn1.traiduoi.y = hcn1.traitren.y;
    hcn1.traiduoi.x = hcn1.phaiduoi.x;
    hcn1.phaitren.y = hcn1.phaiduoi.y;
    int a1,a2;
    printf("%d %d ",hcn1.traitren.x,hcn1.traitren.y);
    printf("%d %d ",hcn1.traiduoi.x,hcn1.traiduoi.y);
    printf("%d %d ",hcn1.phaiduoi.x,hcn1.phaiduoi.y);
    a1=dodai(hcn1.traitren.x,hcn1.traiduoi.x,hcn1.traitren.y,hcn1.traiduoi.y);
    a2=dodai(hcn1.traiduoi.x,hcn1.phaiduoi.x,hcn1.traiduoi.y,hcn1.phaiduoi.y);
    printf("\na1 = %d ",a1);
    printf("\na2 = %d ",a2);
    printf("\nDien tich %d",a1*a2);
    return 0;
}

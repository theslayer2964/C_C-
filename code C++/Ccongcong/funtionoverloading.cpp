// Ham chong ham : cung 1 ham y chang nhau (khac nhau kiu du lieu) --> may tinh van se tim ra loai ham thichs hop de fix problem
#include <stdio.h>
 int timmax(int x,int y)
{
    if(x<y)
        {x=y;
        return x;}
    else return y;
}
float timmax(float x,float y)
{
    if(x<y)
        {x=y;
        return x;}
    else return y;
}

int main ()
{
    float x=1.1,y=5;
    printf("\nmax la %d",timmax(x,y));
    return 0;
}


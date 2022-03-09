// &: địa chỉ của biến ;
// %x: hiển thị địa chỉ của biến.
// *: trỏ đến địa chỉ của biến
#include <stdio.h>
int main ()
{
    int a=2,b=4;
    int *p=&a;
    printf("\nDia chi cua a %x",&a);
    printf("\ngia tri chua trong con tro *p la %x",p);
    printf("\nGia tri cua a %d",*p);
    p=&b;
    printf("\nGia tri cua b %d",*p);
    int arr[5]={6,7,8,9,10};
    int *l= arr;
    printf("\n dia chi cua a %x",arr);
    printf("\n dia chi phan tu a[0] = %x",&l[0]);
    printf("\n gia tri cua l %x \n",l);
    for(int i=0;i<5;i++)
    {
        printf("%5d",arr[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%5d",*(l+i));
    }
    printf("\n");
    for(;l<=&arr[4];l++)
    {
        printf("%5d",*l);
    }
    return 0;
}


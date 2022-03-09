#include <stdio.h>
#include <stdlib.h>
void input(float *a,int &n)
{
    do{printf("\nSo sinh vien: ");scanf("%d",&n);}
    while(n<=0);
    for(int i=0;i<n;i++)
    {
        printf("\n[%d] = ",i);
        scanf("%f",(a+i));
    }
}
void output(float *a,int n)
{
    printf("\nDiem hoc sinh");
    for(int i=0;i<n;i++)
    {
        printf("%.1f ",*(a+i));
    }
}
float dtb(float *a,int n)
{
    float s=0;
    float b;
    for(int i=0;i<n;i++)
    {
        s=s+*(a+i);
    }
    b=s/n;
    return b;
}
int main()
{
    float *a;
    int n;
    a = (float *)malloc(n*sizeof(float));
    input(a,n);
    output(a,n);
    printf("\nDiem trung binh lop A: %.1f",dtb(a,n));
    float *b;
    int m;
    b = (float *)malloc(m*sizeof(float));
    input(b,m);
    output(b,m);
    printf("\nDiem trung binh lop B: %.1f",dtb(b,m));
    if(dtb(a,n)>dtb(b,m))
        printf("\nLop A tot hon");
    else printf("\nLop B tot hon");
    return 0;
}

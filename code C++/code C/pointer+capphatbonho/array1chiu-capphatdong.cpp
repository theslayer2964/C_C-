// mảng động: mảng có thể thay đổi số lượng phần tử của mảng trong quá trinh chạy
// hạn chế tình trạng dư thừa bộ nhớ
// Mảng động được quản lí nởi 1 con trỏ.
#include <stdio.h>
#include <stdlib.h>
#define sptm 100
void input(int *a,int &n)
{
    for(int i=0;i<n;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",(a+i));
    }
}
void output(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}
void tong(int *a,int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        s=s+ *(a+i);
    }
    printf("\ntong chinh la %d",s);
}
void them(int *a,int &n,int vt,int x)
{
 //   a=(int *)realloc(a,(n+1)*sizeof(int));
    for(int i=n-1;i>=vt;i--)
    {
        a[i+1]=a[i];
    }
    a[vt]=x;
    n++;
    output(a,n);
}
void themc2(int *a,int &n,int x)
{
    int k,i;
    k=n+1;
    while(n<k)
    {
        *(a+n)=x;
        i++;
        n++;
    }
    printf("\nda them: ");
    output(a,n);
}

void sapxep(int *a,int &n)
{
    a=(int *)realloc(a,(n+1)*sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    printf("\nsap xep");output(a,n);
}

int main ()
{

    int *a;
    int n,vt,x;
    scanf("%d",&n);
// phải vít nó trong int main
// bước 1: tạo vùng nhớ cho con trỏ
    a=(int *) malloc(n* sizeof(int *));
  // a = (int *)realloc(NULL,n*sizeof(int *));
  // a=(int *)calloc(1,sizeof(int *));
    input(a,n);
    output(a,n);
    tong(a,n);
   // printf("\nvi tri them: ");scanf("%d",&vt);
    printf("\ngia tei them: ");scanf("%d",&x);
   // a=(int *)realloc(a,(n+1)*sizeof(int));
   // them(a,n,vt,x);
    themc2(a,n,x);
    sapxep(a,n);
    free(a);
    return 0;
}

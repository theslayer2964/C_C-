#include <stdio.h>

int main()
{
    int a[3][4];
    int *p= (int *)a;
    for(int i=0;i< 3*4;i++)
    {
        printf("Nhap a[%d][%d] = ",i/4,i%4);
        scanf("%d",p + i);
    }
    for(int d=0;d<3;d++)
    {
        for(int c=0;c<4;c++)
        {
            printf("%d ",*(p+d*4+c));
        }
        printf("\n");
    }
    int s=0;
    for(int d=0;d<3;d++)
      {
          for(int c=0;c<4;c++)
          {
              if(a[d][c]%2==0)
              {
                  s=s+a[d][c];
              }
          }
      }
    printf("\n tong chinh la %d\n",s);
    int b[100];
    for (int d=0;d<3;d++)
    {
        for(int c=0;c<4;c++)
        {
            b[d*4+c] = a[d][c];
            printf("%d ",b[d*4+c]);
        }
    }
    for(int i=0;i<3*4;i++)
      {
          for(int j=3*4-1;j>i;j--)
          {
              if(b[j]< b[j-1])
              {
                  int tam=b[j];
                  b[j]= b[j-1];
                  b[j-1]=tam;
              }
          }
      }
    for(int i=0;i<3*4;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\nda ss\n");
    for (int d=0;d<3;d++)
    {
        for(int c=0;c<4;c++)
        {
            a[d][c]=b[d*4+c] ;
            printf("%d ",a[d][c]);
        }
        printf("\n");
    }
    return 0;
}

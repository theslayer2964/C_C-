#include <stdio.h>

int main()
{
    int a[100];
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    // n: số hàng, m: số cột
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i*m+j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",a[i*m+j]); // công thức này lấy ra vị trí a[] thứ mấy trong dãy, xong phải công thức để xếp nó trong cái ma trận
        }
        printf("\n");
    }
    return 0;
}

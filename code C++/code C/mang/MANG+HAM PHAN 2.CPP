#include <stdio.h>
#define sptm 100
void input(int A[],int &n);
void output(int A[],int n);
void chencuiayy(int A[],int &n,int h);
void chendauday(int A[],int &n,int h);
void gopmang(int A[],int &n,int B[],int m);
void insert(int B[],int &m,int vt,int h);
void sortf(int C[],int d);

int main ()
{

	int A[sptm],vt,n,B[sptm],m,C[sptm],d,h;
	input(A,n);
	output(A,n);
	chencuiayy(A,n,h);
	chendauday(A,n,h);
	input(B,m);
	output(B,m);
	insert(B,m,vt,h);
	gopmang(A,n,B,m);
	sortf(C,d);
	sortf(A,n);
	return 0;
}


void input(int A[],int &n)
{
	printf("\nSo phan tu ");scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf(" A[%d} = ",i);
		scanf("%d",&A[i]);
	}
}
void output(int A[],int n)
{
	printf("\nDay gom ");
	for(int i=0;i<n;i++)
	printf("%d ",A[i]);
}
void chencuiayy(int A[],int &n,int h)
{
	printf("\nNhap so chen cui day ");scanf("%d",&h);
	A[n]=h;
	n++;
	output(A,n);
}
void chendauday(int A[],int &n,int h)
{
	printf("\nNhap so chen dau day ");scanf("%d",&h);
	for(int i=n;i>=0;i--)
	{
		A[i]=A[i-1];
	}
	A[0]=h;
	n++;
	output(A,n);
}
void gopmang(int A[],int &n,int B[],int m)
{
    int C[sptm];
    int d=0;
	for(int i=0;i<n;i++)
	{
		C[d]=A[i];
		d++;
	}
	for(int i=0;i<m;i++)
	{
		C[d]=B[i];
		d++;
	}
	output(C,d);
}
void insert(int B[],int &m,int vt,int h)
{
	printf("\nNhap so chen giua day ");scanf("%d",&h);
	printf("\nNhap vi tri chen trong day ");scanf("%d",&vt);
	for(int i=m;i>vt;i--)
	{
		B[i]=B[i-1];
	}
	B[vt]=h;
	m++;
	output(B,m);
}
void sortf(int C[],int d)
{
	for(int i=0;i<d-1;i++)
	{
		for(int j=d-1;j>i;j--)
		if(C[j]<C[j-1])
		{
		int tam=C[j];
		C[j]=C[j-1];
		C[j-1]=tam;
		}
	}
	printf("\nDay sau khi sap xep ");
	output(C,d);
}


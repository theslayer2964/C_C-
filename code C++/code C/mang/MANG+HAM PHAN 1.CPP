 #include <stdio.h>
#define sptm 100
void inputf(int A[],int &n);
void output(int A[],int n);
void tongvatrb(int A[],int n);
void timmax(int A[],int n);
void songto(int A[],int n);
int timso(int A[],int n,int h);
void chenso(int A[],int &n,int vt,int so); // xem lai nha bitch for(int i=n-1;i>=vt;i--)  A[i+1]=A[i];
void deletef(int A[],int &n,int so);
void sortf(int A[],int n);

int main ()
{
	int n,A[sptm],h,vt,so;
	printf("\nNhap so phan tu cua day A ");scanf("%d",&n);
	inputf(A,n);
	output(A,n);
	tongvatrb(A,n);
	timmax(A,n);
	songto(A,n);
	printf("\nNhap so can tim ");scanf("%d",&h);
	if(timso(A,n,h)==1) printf("\nkhong tim thay");
	else printf("\ntim thay %d o vi tri %d",h,timso(A,n,h));
	chenso(A,n,vt,so);
	deletef(A,n,vt);
	sortf(A,n);
	return 0;
}
void inputf(int A[],int &n)
{
	printf("\ngia tri cua day ");
	for(int i=0;i<n;i++)
	{
		printf("\nA[%d] = ",i);
		scanf("%d",&A[i]);
	}
}
void output(int A[],int n)
{
	printf("\nDay A gom ");
	for(int i=0;i<n;i++)
	printf("%d ",A[i]);
}
void tongvatrb(int A[],int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	s=s+A[i];
	printf("\ntong cua day %d ",s);
	printf("\ntrb cua day %f",s*1.0/n);
}
void timmax(int A[],int n)
{
	int tam=A[0];
	for(int i=0;i<n;i++)
	{
		if(tam<A[i])
		tam=A[i];
	}
	printf("\nmax cua day %d",tam);
}
void songto(int A[],int n)
{
	int demsongto=0,tongsongto=0;
	for(int i=0;i<n;i++)
	{
		int dem=0;
		for(int k=1;k<=A[i];k++)
		{
			if(A[i]%k==0)
			dem++;
		}
		if(dem==2)
		{
		demsongto++;
		printf("\n %d la so ngto ",A[i]);
		tongsongto=tongsongto+A[i];
		}
	}
	printf("\ntong so ngto %d",tongsongto);
	printf("\n co %d so ngto ",demsongto);
	printf("\ntrb so ngto %f",tongsongto*1.0/demsongto);
}
int timso(int A[],int n,int h)
{
	int i=0;
	while(A[i]!=h && i<n)
	{
		i++;
	}
	if(i==n) return 1;
	else return i;
}
void chenso(int A[],int &n,int vt,int so)
{
	printf("\nNhap vi tri can chen ");scanf("%d",&vt);
	printf("\nNhap giatri can chen ");scanf("%d",&so);

	for(int i=n;i>vt;i--)
	{A[i]=A[i-1];}
	A[vt]=so;
	n++;
	output(A,n);
}
void deletef(int A[],int &n,int vt)
{
	printf("\nNhap vi tri can xoa ");scanf("%d",&vt);
	for(int i=vt;i<n;i++)
{
	A[i]=A[i+1];
}
	n--;
	output(A,n);

}
void sortf(int A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
			if(A[j]<A[j-1])
			{
				int tam=A[j];
				A[j]=A[j-1];
				A[j-1]=tam;
			}
	}
	printf("\nDay sau khi sap xep ");
	output(A,n);
}

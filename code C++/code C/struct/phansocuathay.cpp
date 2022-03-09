#include <stdio.h>
#include <stdlib.h>
struct PS
{
	int tu;
	int mau;
};

void NhapPS(PS& x);
void XuatPS(PS x);
void NhapMangPS(PS m[], int& n);
void NhapMangPS(FILE* fp, PS m[], int& n);
void XuatMangPS(PS m[], int n);
PS TongPS(PS ps1, PS ps2);
PS TongMangPS(PS m[], int n);

int main()
{
	FILE* fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt", "r");
	if (fp==NULL)
	{
		printf("File khong ton tai!!!\n");
		return 0;
	}
	PS a[10];
	int n;
	//NhapMangPS(a, n);
	NhapMangPS(fp, a, n);
	XuatMangPS(a, n);

	PS tong = TongMangPS(a, n);
	printf("\nTong cac phan so la: ");
	XuatPS(tong);

	printf("\n\n");
	fclose(fp);
	return 0;
}
void NhapPS(PS& x)
{
	printf("\tNhap tu: ");
	scanf("%d", &x.tu);
	printf("\tNhap mau: ");
	scanf("%d", &x.mau);
}
void XuatPS(PS x)
{
	int dau;
	if (x.tu*x.mau < 0)
		dau = -1;
	else
		dau = 1;

	printf("   %d/%d", abs(x.tu)*dau, abs(x.mau));
}
void NhapMangPS(PS m[], int& n)
{
	printf("\nNhap so luong phan tu: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		NhapPS(m[i]);
	}
}
void NhapMangPS(FILE* fp, PS m[], int& n)
{
	fscanf(fp, "%d", &n);
	for (int i=0; i<n; i++)
	{
		//NhapPS(m[i]);
		fscanf(fp, "%d", &m[i].tu);
		fscanf(fp, "%d", &m[i].mau);
	}
}
void XuatMangPS(PS m[], int n)
{
	printf("\nMang cac phan so: ");
	for (int i = 0; i<n; i++)
	{
		XuatPS(m[i]);
	}
}
PS TongPS(PS ps1, PS ps2)
{
	PS kq;
	kq.tu = ps1.mau*ps2.tu + ps1.tu*ps2.mau;
	kq.mau= ps1.mau*ps2.mau;
	return kq;
}
PS TongMangPS(PS m[], int n)
{
	PS kq;
	kq.tu= 0;
	kq.mau = 1;

	for (int i = 0; i<n; i++)
	{
		kq = TongPS(kq, m[i]);
	}
	return kq;
}

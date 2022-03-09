#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct CLB {
	char tenCLB	[32];
	int sotran;
	int hieuso;
	int diem;
};

void DocFile1(char* filename, CLB ds[], int& n);
void DocFile2(char* filename, CLB ds[], int& n);
void Xuat(CLB ds[], int n);
void TimDoiCoHieuSoCaoNhat(CLB ds[], int n);
void SapXepGiam(CLB ds[], int n);

int main()
{
	CLB dsCLB[20];
	int soluongCLB;

	DocFile1("ngoaihanganh_data2.txt", dsCLB, soluongCLB);
	Xuat(dsCLB, soluongCLB);

	TimDoiCoHieuSoCaoNhat(dsCLB, soluongCLB);
	printf("\n\nBang Xep Hang: ");
	SapXepGiam(dsCLB, soluongCLB);
	Xuat(dsCLB, soluongCLB);
	printf("\n\n");
	return 0;
}

void DocFile1(char* filename, CLB ds[], int& n)
{
	FILE* fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\code C\\filenpath\\bongxuongdong.txt", "rt");
	if (fp == NULL)
	{
		printf("\nCannot open file!!!\n\n");
		return;
	}

	char dong[50];
	//C1: fscanf(fp, "%d", &n);
	fgets(dong, 50, fp);
	n = atoi(dong);
	// Atoi: chuyển đổi hàm dong thành kiu số nguyên (int)
	for (int i=0; i<n; i++)
	{
		fgets(dong, 50, fp);
		dong[strlen(dong)-1] = '\0';
		strcpy(ds[i].tenCLB, dong);
		fscanf(fp, "%d", &ds[i].sotran);
		fscanf(fp, "%d", &ds[i].hieuso);
		fscanf(fp, "%d", &ds[i].diem);
		fgets(dong, 50, fp);
	}
	fclose(fp);
}
void DocFile2(char* filename, CLB ds[], int& n)
{
	FILE* fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\bongphay.txt", "rt");
	if (fp == NULL)
	{
		printf("\nCannot open file!!!\n\n");
		return;
	}

	char dong[50];
	fgets(dong, 50, fp);
	n = atoi(dong);
	for (int i=0; i<n; i++)
	{
	    // dunhgf hàm conn tror đó nha
		fgets(dong, 50, fp);
		char* chuoicon = strtok(dong, ",");
		strcpy(ds[i].tenCLB, chuoicon);
		chuoicon = strtok(NULL, ",");
		ds[i].sotran = atoi(chuoicon);
		chuoicon = strtok(NULL, ",");
		ds[i].hieuso = atoi(chuoicon);
		chuoicon = strtok(NULL, ",");
		ds[i].diem = atoi(chuoicon);
	}
	fclose(fp);
}
void Xuat(CLB ds[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf("\n%d, %s, %d, %d, %d", i+1, ds[i].tenCLB, ds[i].sotran, ds[i].hieuso, ds[i].diem);
	}
}
void TimDoiCoHieuSoCaoNhat(CLB ds[], int n)
{
	//Tim vitri
	int vitri = 0;
	for (int i=1; i<n; i++)
	{
		if (ds[i].hieuso > ds[vitri].hieuso)
			vitri = i;
	}
	//Xuat
	printf("\n\nDoi co hieu so cao nhat la: %s", ds[vitri].tenCLB);
}
void SapXepGiam(CLB ds[], int n)
{
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (ds[i].diem < ds[j].diem)
			{
				CLB tam = ds[i];
				ds[i] = ds[j];
				ds[j] = tam;
			}
}

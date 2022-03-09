#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct sinhvien
{
    char hoten[100];
    int ngay;
    int thang;
    int nam;
};
void docduliu(FILE *fp,sinhvien s[],int &n)
{
    fp= fopen("C:\\Users\\Sony Vaio\\Desktop\\code C++\\danhsachlienket\\sinhvien.txt","rt");
    if(fp == NULL)
    {
        printf("\nCouldn't find this file");
    }
    else printf("\nco\n");
    char dong[50];
    fgets(dong,50,fp);
    n=atoi(dong);
    for(int i=0;i<n;i++)
    {
    fgets(dong,50,fp);
    char *chuicon= strtok(dong,",");
    strcpy(s[i].hoten,chuicon);
    chuicon=strtok(NULL,",");
    s[i].ngay=atoi(chuicon);
    chuicon=strtok(NULL,",");
    s[i].thang=atoi(chuicon);
    chuicon=strtok(NULL,",");
    s[i].nam=atoi(chuicon);
}
}
void output(sinhvien s[],int n)
{
    printf("\n%d\n",n);
    for(int i=0;i<n;i++)
    {
        printf("\n%s",s[i].hoten);
        //printf("\n%s",s.mssv);
        printf("\n%d",s[i].ngay);
        printf("\n%d",s[i].thang);
        printf("\n%d",s[i].nam);
    }
}
int main ()
{
    FILE *fp;
    fp= fopen("C:\\Users\\Sony Vaio\\Desktop\\code C++\\danhsachlienket\\sinhvien.txt","rt");
    sinhvien s[100];
    int n;
    docduliu(fp,s,n);
    output(s,n);
    return 0;
}

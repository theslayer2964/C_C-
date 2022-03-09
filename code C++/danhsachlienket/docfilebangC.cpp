#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct clb
{
    char ten[100];
    int sotran;
    int hieuso;
    int diem;
};
void DocFile1(FILE *fp,clb s[],int &n)
{
    fp= fopen("C:\\Users\\Sony Vaio\\Desktop\\code C\\filenpath\\bongnangcao.txt","rt");
    char dong[50];
    fgets(dong,50,fp);
    n=atoi(dong);
    for(int i=0;i<n;i++)
    {
        fgets(dong,50,fp);
        dong[strlen(dong)-1] = '\0';
        strcpy(s[i].ten,dong);
        fscanf(fp,"%d",&s[i].sotran);
        fscanf(fp,"%d",&s[i].hieuso);
        fscanf(fp,"%d",&s[i].diem);
        fgets(dong,50,fp);
    }
}
void DocFile2(FILE *fp,clb s[],int &n)
{
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\code C++\\danhsachlienket\\sinhvien.txt","rt");
    if(fp == NULL)
    {
        printf("\nCouldn't find this file");
    }
    char dong[50];
    //fscanf(fp,"%d",&n);
    //nếu dùng fscanf sẽ có lỗi --> làm sao????
    fgets(dong,50,fp);
    n=atoi(dong);
    for(int i=0;i<n;i++)
    {
        fgets(dong,50,fp);
        char *chuicon= strtok(dong,",");
        strcpy(s[i].ten,chuicon);
        chuicon=strtok(NULL,",");
        s[i].diem=atoi(chuicon);
        chuicon=strtok(NULL,",");
        s[i].hieuso=atoi(chuicon);
        chuicon=strtok(NULL,",");
        s[i].sotran=atoi(chuicon);
    }
}
void output(clb s[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n%s,%d,%d,%d",s[i].ten,s[i].hieuso,s[i].sotran,s[i].diem);
    }
}
int main ()
{
    FILE *fp;
    clb s[100];
    int n;
    DocFile2(fp,s,n);
    output(s,n);
    return 0;
}

// hàm nào dùng để đọc là đọc , hàm nào dùng để vit là vít ---> đéo được nhầm lẫn

#include <stdio.h>
#define MAXCHAR 100

int main ()
{
    FILE *fp;
    int k;
    char s[100];
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","wt");
    if(fp == NULL)
    {
        printf("\nCould find this file");
    }
    else printf("\nFound this file");
    int i=1;char c='a';float l=1.4;
    fprintf(fp,"%d %c %f",i,c,l); //ghi dô file
    fputs("\nahihihaha",fp);
    rewind(fp);

    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","r");
    fscanf(fp,"%d",&k);
    printf("\nki tu trong file la %d",k);


    fclose(fp);
    return 0;
}


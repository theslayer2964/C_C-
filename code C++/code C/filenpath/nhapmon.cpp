#include <stdio.h>
#define MAXChAR 1000

int main ()
{
    FILE *fp;
    char str[MAXChAR];
    char* filename = "C:/Users/Sony Vaio/Desktop/vít code/file n path/ahihihaha.txt";
    fp= fopen(filename,"r");
    if(fp == NULL)
    {
        printf("\nCould not find this file %s",filename);
        return 1;
    }
    while (fgets(str, MAXChAR, fp) != NULL)
    {
        printf("%s",str);
    }
        fclose(fp);

        return 0;
}

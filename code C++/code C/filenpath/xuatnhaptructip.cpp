#include <stdio.h>

int main ()
{
    FILE *fp;
    //char a[15]="hoang minh tri" ;
    //fp= fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","a");
    //fwrite(a,sizeof(char),15,fp);
    fp= fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","r");
    char b[15];
    fread(b,sizeof(char),15,fp);
    printf("\nKi tu trong day la %s",b);
    fclose(fp);
    return 0;
}

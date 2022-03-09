#include <stdio.h>
#define MAXCHAR 100

int main ()
{
    FILE *fp;
    char str[MAXCHAR];
    char *FILENAME = "C:\\Users\\Sony Vaio\\Desktop\\789.txt";
    fp= fopen(FILENAME,"rt");
    //int i=1;char c='t';float l=1.3;
    //fprintf(fp,"%d %c %f",i,c,l);

    char ch;
    ch= fgetc(fp); // Lấy kí tự đầu tin trong file ra
    printf("%c",ch);  // in ra
    fp= fopen(FILENAME,"rt");
    int i=0;
    fprintf(fp,"ahihi %d ",i);
    fclose(fp);
    return 0;
}

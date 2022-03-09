#include <stdio.h>
#define MAXCHAR 1000

int main ()
{
    FILE *fp;
    char str[MAXCHAR];
   // char *filename = "C:\\Users\\Sony Vaio\\Desktop\\input.txt";
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","r");
    if ( fp== NULL)
    {
        printf("\nCould find this file");
        return 1;
    }
    int i=30;char c='t';float l=1.5;
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","wt");
    fprintf(fp,"%d %c %f",i,c,l);
    fclose(fp);
    return 0;
}

// không thể đồng thời vừa nhập chũi (fgets) vừa nhập kí tự (fgetc) được ???? ---> tại sao vậy ???

#include <stdio.h>
int main ()
{
    FILE *fp;
    char s[100];
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","w");
    fputs("em oi ha noi pho",fp);
    rewind(fp);              // lun lun phải đem con trỏ về
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","rt");
    fgets(s,100,fp);
    printf("%s",s);
    fclose(fp);
    return 0;
}


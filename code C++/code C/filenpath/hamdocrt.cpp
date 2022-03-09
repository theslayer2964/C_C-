#include <stdio.h>
int main ()
{
    FILE *fp;
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","w");
    fputs("em oi ha noi pho",fp);
    rewind(fp);              // lun lun phải đem con trỏ về
    fp = fopen("C:\\Users\\Sony Vaio\\Desktop\\input.txt","rt");
    char ch;
    ch = fgetc(fp);
    printf("%c",ch);        // đọc ONLY 1 kí tự duy nhất
    fclose(fp);
    return 0;
}

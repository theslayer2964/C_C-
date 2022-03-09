// Ham strchr(chuicantim,char) strstr(chuicantim,"chuicantim");

#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
    char str1[28];
    strcpy(str1,"mot hai ba bon nam sau bay");
    char *p=strchr(str1,'k');
    if(p!=NULL)
        cout << "tim thay ki tu tai vi tri " << p -str1 << endl;
    else
        cout << "khong tim thay ki tu trong chui" << endl;
    char  *u=strstr(str1,"hai");
    if(u!= NULL)
        cout << "Tim thay ki tu tai vi tri " << u-str1<< endl;
    else
        cout <<"Khong tim thay ki tu trong day" << endl;
            return 0;
}

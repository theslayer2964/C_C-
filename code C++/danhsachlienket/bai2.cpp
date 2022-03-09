#include <stdio.h>
#include <stdlib.h>
typedef struct SV{
        int data;
        struct SV* next;
} nut;
nut* dau,* cuoi;
void ThemDau(int giatri){
     nut *p;
     p=(nut* )malloc(sizeof(nut));
     p->data=giatri;
     p->next=dau;
     dau=p;
}
void ThemCuoi(int giatri)
{
    nut *p = (nut *)malloc(sizeof(nut));
    p->data = giatri;
    p->next = NULL;
    if (dau == NULL)
        dau = p;
    else
        cuoi->next = p;
    cuoi = p;
}
void HienThi(){
     nut *p;
     p=dau;
     while(p != NULL){
          printf("%d",p->data);
          p=p->next;
     }
}

int main(int argc, char *argv[])
{
   int n,i,s;
    printf("Nhap vao tong so: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
         printf("Nhap vao so %d: ",i+1);
         scanf("%d",&s);
         ThemCuoi(s);
    }
    HienThi();

  system("PAUSE");
  return 0;
}

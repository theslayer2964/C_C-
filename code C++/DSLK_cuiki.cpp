#include<stdio.h>
#include<string.h>
struct THONGTIN
{
    char maSV[20];
    char tenSV[20];
    float diemCK;
};
struct node
{
    THONGTIN data;
    node *link;
   /// int tong;
};
struct list
{
    node *pfirst;
    node *plast;
    int soLuongSV=0;
    float tong;
};
void khoitao(list &l)
{
    l.pfirst=NULL;
    l.plast=NULL;

}
node *get1node(THONGTIN t)
{
    node *p= new node;
    p->data=t;
    p->link=NULL;
    return p;
}
void addfirst(list &l,node *p)
{
    if(l.pfirst==NULL)
    {
       l.pfirst=l.plast=p;
       l.soLuongSV++;
        l.tong+=p->data.diemCK;
    }
    else
    {
        p->link=l.pfirst;
        l.pfirst=p;
        l.soLuongSV++;
        l.tong+=p->data.diemCK;
    }
}
void insert(list &l,THONGTIN t)
{
    node *p= get1node(t);
    if(p==NULL)
        return;
    else
    {
        addfirst(l,p);
    }
}
int nhap1sv(THONGTIN &t)
{
    printf("\nNhap ms (Nhap 0 de dung CT): ");
    fflush(stdin);
    gets(t.maSV);
    if(strcmp(t.maSV,"0")==0)
        return 0;
    printf("\nNhap ho ten:");
    fflush(stdin);
    gets(t.tenSV);
    printf("\nNhap diem:");
    scanf("%f",&t.diemCK);
    return 1;
}
void nhapdssv(list &l)
{
    printf("\nBat dau nhap");
    THONGTIN t;
    int flag=nhap1sv(t);
    while(flag)
    {
        insert(l,t);
        flag=nhap1sv(t);
    }
    printf("\nKet thuc nhap");
}
void xuat1sv(THONGTIN t)
{
    printf("\nMa: %s,Ten: %s, Diem: %.2f",t.maSV,t.tenSV,t.diemCK);
}
void xuatdssv(list l)
{
    for(node *k=l.pfirst;k!=NULL;k=k->link)
    {
        xuat1sv(k->data);
    }
}
void tachDS(list &l,list &l2)
{
    for(node *k=l.pfirst;k!=NULL;k=k->link)
    {
        if(k->data.diemCK>5)
        {
            insert(l2,k->data);
        }
    }
}
void xoatoanbo(list &l) /// ???????
{
    for(node *k=l.pfirst;l.pfirst!=NULL;k=k->link)
        {
            l.pfirst=k->link;
            delete k;
        }
}
void gopDS(list &l,list &l2)
{
    if(l.pfirst==NULL)
        l=l2;
    if(l2.pfirst==NULL)
        return;
    else
    {
        l.plast->link=l2.pfirst;
        l.plast=l2.plast;
    }
    khoitao(l2);
}
void swap(THONGTIN &a,THONGTIN &b)
{
    THONGTIN c= a;
    a=b;
    b=c;
}
void interChangeSort(list l)
{
    for(node *k=l.pfirst;k!=l.plast;k=k->link)
    {
        for(node *j=k->link;j!=NULL;j=j->link)
        {
            if(strcmp(k->data.maSV,j->data.maSV)<0)
                swap(k->data,j->data);
        }
    }
}
void selectionSort(list l)
{
    node *min= new node;
    for(node *k=l.pfirst;k!=l.plast;k=k->link)
    {
        min=k;
        for(node *j=k->link;j!=NULL;j=j->link)
        {
            if(strcmp(min->data.maSV,j->data.maSV)>0)
                min=j;
        }
        if(min!=k)
            swap(min->data,k->data);
    }
}
void xoaDau(list &l)
{
    if(l.pfirst==NULL)
        return;
    else
    {
        node *p= new node;
        p=l.pfirst;
        l.pfirst=p->link;
        delete p;
    }
}
void xoaGiua(list &l,char s[])
{
    node *truoc= new node;
    for(node *k=l.pfirst;k!=NULL;k=k->link)
    {
        if(strcmp(k->data.maSV,s)==0)
        {
            truoc->link=k->link;
            delete k;
            break;
        }
        truoc=k;
    }
}
void xoaXXX(list &l,char s[])
{
    node *truoc= new node;
    for(node *k=l.pfirst;k!=NULL;k=k->link)
    {
        if(strcmp(l.pfirst->data.maSV,s)==0)
            xoaDau(l);
        if(strcmp(k->data.maSV,s)==0)
            xoaGiua(l,s);
    }
}
float tinhTongTB(list l)
{
    return l.tong/l.soLuongSV;

}
int main ()
{
    list l,l2;
    khoitao(l);
    nhapdssv(l);
    printf("\nDS:");
//    printf("\nDanh sach sv tren 5d:");
//    tachDS(l,l2);
//    xuatdssv(l2);
//    printf("\nDanh sach l sau khi xoa:");
//    xoatoanbo(l);
//    xuatdssv(l);
//    khoitao(l2);
//    printf("\nNhap ds 2:");
//    nhapdssv(l2);
//    printf("\nDS 2:");
//    xuatdssv(l2);
//    printf("\nGop 2 ds:");
//    gopDS(l,l2);
    //interChangeSort(l);
   // selectionSort(l);
//    char s[100];
//    fflush(stdin);
//    gets(s);
//    xoaXXX(l,s);
//    printf("\nDanh sach chinh la:\n");
//    xuatdssv(l);
    printf("\n%d",l.soLuongSV);
    printf("\n%.2f",l.tong);
    printf("\n%.2f",tinhTongTB(l));
    return 0;
}

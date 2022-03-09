
#include <stdio.h>
#include <string.h>
struct ngay
{
    int ngay;
    int thang;
    int nam;
};
struct sinhvien
{
    char masv[8];
    char hoten[50];
    int gioitinh;
    ngay ngaysinh;
    char diachi[50];
};
struct node
{
    sinhvien data;
    node *pnext;
};
struct list
{
    node *phead;
    node *ptail;
};
void khoitao(list &l)
{
    l.phead=NULL;
    l.ptail=NULL;
}
node *tao1node(sinhvien x)
{
    node *ptemp= new node;
    ptemp->data=x;
    ptemp->pnext=NULL;
    return ptemp;
}
void addlast(list &l,node *p)
{
    if(l.phead==NULL)
    {
        l.phead=l.ptail=p;
    }
    else
    {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}
void addfirst(list &l,node *p)
{
    if(l.phead==NULL)
        l.phead=l.ptail=p;
    else
    {
        p->pnext=l.phead;
        l.phead=p;
    }
}
void insertlast(list &l,sinhvien x)
{
    node *p= tao1node(x);
    if(p==NULL)
    {
        return;
    }
    else addlast(l,p);
}
void insertfirst(list &l,sinhvien x)
{
    node *p= tao1node(x);
    if(p==NULL)
    {
        return;
    }
    else addfirst(l,p);
}
int nhap1sinhvien(sinhvien &x) // int int int
{
    printf("\nNhap ma so(Nhap 0 de dung):");
    fflush(stdin);
    gets(x.masv);
    if(strcmp(x.masv,"0")==0) // dk de dung vic nhap
        return 0;
    printf("\nNhap ho ten: ");
    fflush(stdin);
    gets(x.hoten);
    printf("\nNhap gioi tinh(nhap 1: nam,2: nu): ");
    scanf("%d",&x.gioitinh);
    printf("\nNhap ngay thang nam sinh: ");
    scanf("%d %d %d",&x.ngaysinh.ngay,&x.ngaysinh.thang,&x.ngaysinh.nam);
    printf("\nNhap dia chi: ");
    fflush(stdin);
    gets(x.diachi);
    return 1;   // return
}
bool search(list l,sinhvien x)
{
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        if(strcmp(k->data.masv,x.masv)==0)
            return true;
    }
    return false;
}
int insert_khongtrung(list &l,sinhvien x) // thay vì gọi hàm insert.ta goi hàm insert o trùng
{
    if(search(l,x)==true)
        {
            printf("\nMa trung");
            return 0;
        }
    else
        {
            insertlast(l,x);
            return 1;
        }
}
void nhapDSsinnhvien(list &l)
{
    printf("\nBat dau nhap:");
    sinhvien x;
    int flag= nhap1sinhvien(x);
    while(flag!=0)
    {
        insertlast(l,x);
        flag=nhap1sinhvien(x);
    }
    printf("\nNhap xong");
}
void nhapDSsinnhvien_khongtrung(list &l)
{
    printf("\nBat dau nhap:");
    sinhvien x;
    int flag= nhap1sinhvien(x);
    while(flag!=0)
    {
        //insertlast(l,x);
        insert_khongtrung(l,x);
        flag=nhap1sinhvien(x);
    }
    printf("\nNhap xong");
}
void xuat1sinhvien(sinhvien x)
{
    char gt[4];     // doi lai gioi tinh
    if(x.gioitinh==1)       // x.gioitinh la int goi.ko copy do dc.phai xai bien khac
        strcpy(gt,"nam");
    else strcpy(gt,"nu");
    printf("\n%10s|%10s|%4s|%d/%d/%d|%10s",x.masv,x.hoten,gt,
           x.ngaysinh.ngay,x.ngaysinh.thang,x.ngaysinh.nam,x.diachi);
}
void sort(list &l)
{
    printf("\nDay sau sap xep");
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        for(node *j=k->pnext;j!=NULL;j=j->pnext)
        {
            if(strcmp(k->data.masv,j->data.masv)>0)
            {
                node *ptemp=new node;
                ptemp->data=k->data;
                k->data=j->data;
                j->data=ptemp->data;
            }
        }
    }
}
void xuatdssinhvien(list l)
{
    sinhvien x;
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        xuat1sinhvien(k->data);
    }
}
void xoadau(list &l)
{
    if(l.phead==NULL)
        return;
    else
    {
        node *p=l.phead;
        l.phead=l.phead->pnext;
        delete p;
    }
}
void xoacui(list &l)
{
    if(l.phead==NULL)
        return;
    else
    {
        for(node *k=l.phead;k!=NULL;k=k->pnext)
        {
            if(k->pnext==l.ptail)
            {
                delete l.ptail;
                k->pnext=NULL;
                l.ptail=k;
            }
        }
    }
}
void xoagiua(list &l,char s[])
{
    int flag=1;
    node *truoc=new node;
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        if(strcmp(k->data.masv,s)==0)
        {
            truoc->pnext=k->pnext;
            delete k;
            flag=0;
        }
        truoc=k;
    }
    if(flag==1)
        printf("\nKhong co sv %s trong lop",s);
}
void xoasinhviencomax(list &l,char s[])
{
    printf("\nNhap mssv can xoa:");
    fflush(stdin);
    gets(s);
    if(strcmp(l.phead->data.masv,s)==0)
    {
        xoadau(l);
    }
  //  else if(strcmp(l.ptail->data.masv,s)==0)
  //  {
  //      xoacui(l);
  //  }
    else
    {
        xoagiua(l,s);
    }

}
void noi2mang(list &l,list &l2)
{
    if(l2.phead==NULL)
        return;
    if(l.phead==NULL)
        l=l2;
    else
    {
        l.ptail->pnext=l2.phead;
        l.ptail=l2.ptail;
    }
    khoitao(l2);
}
node *timvitrithem(list l,char s[])
{
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        if(strcmp(k->pnext->data.masv,s)>0)
        {
            return k;
        }
    }
}
void insertafter(list &l,node *p,sinhvien x)
{
    node *them=tao1node(x);
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        if(strcmp(k->data.masv,p->data.masv)==0)
        {
            them->pnext=k->pnext;
            p->pnext=them;
        }
    }
}
void themcothutu(list &l)
{
    sinhvien x;
    int flag=nhap1sinhvien(x);
    if(strcmp(l.phead->data.masv,x.masv)>0)
        insertfirst(l,x);
        else
        {
            node *p=timvitrithem(l,x.masv);
            insertafter(l,p,x);
        }
}
int main()
{
    list l,l2;
    khoitao(l);
    khoitao(l2);
    nhapDSsinnhvien(l);
    xuatdssinhvien(l);
    printf("\nMang 2:");
    nhapDSsinnhvien(l2);
    xuatdssinhvien(l2);
    printf("\nMang sau khi nhap:");
    noi2mang(l,l2);
    xuatdssinhvien(l);
    return 0;
}

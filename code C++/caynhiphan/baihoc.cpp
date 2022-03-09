#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *pleft;
    struct node *pright;
};
node *tao1node(int x)
{
    node *ptemp= new node;
    ptemp->data=x;
    ptemp->pnext=NULL;
    return ptemp;
}
// không cần khởi tạo cái danh sách 2 cái node lun
// input cái cây lun
void input(node* &t,int x)
{
    t=NULL;
}
// cây có 1 hàm thim hôi
// cây tự tìm
void themnodevaocay(node* &t,node *p)
{
    if(t=NULL) // if cây rỗng
    {
        node *p=new node;
        p->data=x;
        p->pleft=NULL;
        p->pright=NULL;
        t=p // ủa làm zay chi, cần hôn
    }
    else  // cây có phần tử
    {
        if(t->data<x)
        {
            themnodevaocay(t->pright,p)
        }
        else if(t->data>x) // CÂY CHỈ LƯU PHẦN TỬ O TRÙNG NHAU HÔI--> CÒN 1 TRƯỜNG HỢP "="
        {
            themnodevaocay(t->pleft,p);
        }
    }
}
}
void output(list l)
{
    for(node *k=l.phead;k!= NULL;k = k->pnext)
    {
        cout << k->data << " ";
    }
}

int main()
{
    list l;
    input(l);
    int luachon;
    do
    {
        int x;
        cout <<"\nNhap x:";
        cin >> x;
        node *p = new node;
        p= tao1node(x);
        themdau(l,p);
        cout << "\nmun nhap tip o (0: thoat): ";
        cin >> luachon;
    }
    while(luachon!=0);
    output(l);
    return 0;
}

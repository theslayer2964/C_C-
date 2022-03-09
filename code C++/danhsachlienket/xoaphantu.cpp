#include <iostream>
using namespace std;
struct node
{
    int data;
    node *pnext;
};
struct danhsach
{
    node *phead;
    node *ptail;
};
node *khoitao1nodecogiatri(int d)
{
    node *pnode= new node;
    if(pnode != NULL)
    {
        pnode->data=d;
        pnode->pnext=NULL;
    }
    return pnode;
}
void khoitao1danhsach(danhsach &l)
{
    l.phead=NULL;
    l.ptail=NULL;
}
void output(danhsach l)
{
    for(node *k=l.phead;k!= NULL;k = k->pnext)
    {
        cout << k->data << " ";
    }
}
void them1nodedau(danhsach &l,node *ptemp)
{
    if(l.phead == NULL)
    {
        l.phead=l.ptail=ptemp;
    }
    else
    {
        ptemp->pnext=l.phead;
        l.phead=ptemp;
    }
}
/*void them1nodecui(danhsach &l,node *ptemp)
{
    if(l.phead == NULL)
    {
        l.phead=l.ptail=ptemp;
    }
    else
    {
        l.ptail->pnext=ptemp;
        l.ptail=ptemp;
    }
}*/
void xoadau(danhsach &l)
{
    if(l.phead==NULL)
    {
        cout << "\ncon z de xoa";
    }
    else
    {
        // tạo 1 node temp nối vs l.head (xóa ptemp sẽ xóa l.head lun)
        node *ptemp= l.phead; // tức là lúc này có 2 con trỏ cùng trỏ dô phần tử thứ 1
        l.phead=l.phead->pnext; // cập nhật lại l.phead -> phead trỏ tới phần tử pnext(thu 2), ptemp trỏ tới 1
        delete ptemp;
    }
}
void xoacui(danhsach &l)
{
    if(l.phead==NULL)
    {
        cout << "\ncon z de xoa";
    }
    else
    {
        for(node *k=l.phead;k!=NULL;k=k->pnext)
        {
            if(k->pnext==l.ptail) // tìm ra node cúi (node cúi trỏ tới l.ptail)
            {
                delete l.ptail;
                k->pnext=NULL;  // con trỏ của node kế cúi trỏ tới vùng nhớ null
                l.ptail=k;    // cập nhật lại con trỏ l.ptail
            }
        }
    }
}
void xoanodenamsaugt(danhsach &l)
{
    int gt;
    cout << "\nXoa sau so: ";
    cin >> gt;
    node *ptemp= khoitao1nodecogiatri(gt);
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        if(k->data== ptemp->data)
        {
            node *g=k->pnext;
            k->pnext=g->pnext;
            delete g;
        }
    }
}
void xoanodebatki(danhsach &l)
{
    int gt;
    cout << "\nXoa so may: ";
    cin >> gt;
    node *ptemp= khoitao1nodecogiatri(gt);
    node *truoc = new node;
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        /*if(l.phead->data == ptemp->data)
        {
            xoadau(l);
        }
        if(l.ptail->data == ptemp->data)
        {
            xoacui(l);
        }*/
        if(ptemp->data == k->data)
        {
            truoc->pnext=k->pnext;
            delete ptemp;
        }
        truoc=k; // sau khi nó quay lai nó sẽ trỏ dến node trước node cần xóa
    }
}
void deletel(danhsach &l)
{
    /*for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        delete k;
    }*/
    // cách này sai bét nhé.
    node *k=NULL;
    while(l.phead!=NULL)
    {
        k=l.phead;
        l.phead=l.phead->pnext;
        delete k;
    }
}
int main ()
{
    danhsach l;
    khoitao1danhsach(l);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin >> d;
        node *p=khoitao1nodecogiatri(d);
        them1nodedau(l,p);
    }
    cout << "\nDay chinh la: ";
    output(l);
   /* xoadau(l);
    cout << "\nXoa node dau:" ;
    output(l);
    xoacui(l);
    cout << "\nXoa node cui:" ;
    output(l);*/
    xoanodebatki(l);
    output(l);
    deletel(l);
    cout << "\nGia phong";
    output(l);
    return 0;
}


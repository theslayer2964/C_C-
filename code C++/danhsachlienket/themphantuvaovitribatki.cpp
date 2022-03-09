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
void them1nodecui(danhsach &l,node *ptemp)
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
}
void themnode_p_vaosaunode_q(danhsach &l,node *p)
{
    int x;
    cout << "\n mun them sau so may: ";
    cin >> x;
    node *q= khoitao1nodecogiatri(x);
    if( q ->data == l.phead->data && l.phead->pnext==NULL)
    {
        them1nodecui(l,p);
    }
    else
    {
        for(node *k=l.phead;k!=NULL;k=k->pnext)
        {
            if(q->data == k->data)
            {
                node *h= khoitao1nodecogiatri(p->data); // khởi tạo 1 node mới để thêm.
                node *ptemp = k->pnext; // node temp sẽ trỏ tới vị trí sau q
                h->pnext=ptemp; // p trỏ tới ptemp
                k->pnext=h;
            }
        }
    }
}
void themvaotruoc(danhsach &l)
{
    // ghê ghê. g=k
    cout << "\nThem vao truoc: ";
    int vt;
    cout << "\nTruoc so may: ";
    cin >> vt;
    node *nodevt=khoitao1nodecogiatri(vt);
    int gt;
    cout << "\nGia tri thim: ";
    cin >> gt;
    node *nodegt=khoitao1nodecogiatri(gt);
    if(nodevt->data == l.phead->data)
    {
        them1nodedau(l,nodegt);
    }
    else
    {
        node *hay= new node;
        for(node *k=l.phead;k!=NULL;k=k->pnext)
        {
            if(k->data == nodevt->data)
            {
                node *h= khoitao1nodecogiatri(nodegt->data);
                node *g=hay->pnext;
                h->pnext=g;
                hay->pnext=h;
            }
            hay=k; // giữ lại node phía trước ----> hay hay hay
        }
    }
}
int demsophantu(danhsach &l)
{
    int dem=0;
    for(node *k= l.phead;k!=NULL;k=k->pnext)
    {
        dem++;
    }
    return dem;
}
int main ()
{
    danhsach l;
    khoitao1danhsach(l);
    int n;
    do
    {
        int d;
        cin >> d;
        node *p= khoitao1nodecogiatri(d);
        them1nodedau(l,p);
        cout << "\nMun nhap tip ko.(Mun thi nhap n = 1): ";
        cin >> n;
    }
    while(n==1);
    cout << "\nDay chinh la: ";
    output(l);
    cout << "\nSo phan tu cua day: " << demsophantu(l);
    cout << "\nMun them vao vi tri thu may ";
    int vitri;
    cin >> vitri;
    if(vitri==1)
    {
        cout << "\nThem so may: ";
        int d;
        cin >> d;
        node *ptemp= khoitao1nodecogiatri(d);
        them1nodedau(l,ptemp);
        output(l);
    }
    if(vitri== demsophantu(l))
    {
        cout << "\nThem so may: ";
        int d;
        cin >> d;
        node *ptemp= khoitao1nodecogiatri(d);
        them1nodecui(l,ptemp);
        output(l);
    }
    if(vitri > demsophantu(l))
    {
        cout << "\ndeo co phan tu do";
    }
    else
    {
        cout << "\nThem so may: ";
        int d;
        cin >> d;
        node *ptemp= khoitao1nodecogiatri(d);
        themnode_p_vaosaunode_q(l,ptemp);
        output(l);
    }
    return 0;
}

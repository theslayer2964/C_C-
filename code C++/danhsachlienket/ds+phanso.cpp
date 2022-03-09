#include <iostream>
using namespace std;
struct phanso
{
    int tu;
    int mau;
};
struct node
{
    phanso p;
    struct node *pnext;
};
struct list
{
    node *phead;
    node *ptail;
};
void khoitaolish(list &l)
{
    l.phead=NULL;
}
node *tao1node(int x,int y)
{
    node *ptemp = new node;
    ptemp->p.tu=x;
    ptemp->p.mau=y;
    ptemp->pnext =NULL;
    return ptemp;
}
void them1nodedau(list &l,node *p)
{
    if(l.phead == NULL)
    {
        l.phead = p;
    }
    else
    {
        p->pnext = l.phead;
        l.phead=p;
    }
}
void them1nodecui(list &l,node *p)
{
    if(l.phead == NULL)
    {
        l.phead = p;
    }
    else
    {
        for(node *k = l.phead; ;k=k->pnext)
        {
            if(k->pnext == NULL)
            {
                k->pnext= p;
                //k->pnext= null
// lưu y: không đún.ko bít tại sao nnữa
                break;
            }
        }
    }
}
void xoadau(list &l)
{
    node *ptemp = new node;
    ptemp = l.phead;
    l.phead=l.phead->pnext;
    delete ptemp;
}
void xoacui(list &l)
{
    if(l.phead == NULL)
    {
        cout << "\nhet";
    }
    if(l.phead->pnext == NULL)
    {
        xoadau(l);
    }
    else
    {
    for(node *k=l.phead; ;k=k->pnext)
    {
        if(k->pnext->pnext==NULL)
        {
            delete k->pnext;
            k->pnext = NULL;
            //k->pnext->pnext=k;
            break;
        }
        }
    }
// sẽ bị lỗi nếu như chiỉ có 1 phần tử trong danh sách
// vì đìu kin đc tạo ra là k trỏ pnext trỏ pnext--> sai "if"
}
void themsauvitri(list &l)
{
    phanso vt;
    cout << "\nThem sau so.tu : ";
    cin >> vt.tu;
    cout << "\nThem sau so.mau : ";
    cin >> vt.mau;
    node *vitri= tao1node(vt.tu,vt.mau);
    phanso gt;
    cout << "\nMun so.tu : ";
    cin >> gt.tu;
    cout << "\nMun so.mau : ";
    cin >> gt.mau;
    node *giatri= tao1node(gt.tu,gt.mau);
    for(node *k=l.phead; ;k=k->pnext)
    {
        if( k->p.tu * vitri->p.mau == vitri->p.tu*k->p.mau)
        {
            node *h=tao1node(vt.tu,vt.mau);
            h->pnext=k->pnext;
            h->pnext=giatri;

            break;
        }
    }

}

void output(list l)
{
    for(node *k=l.phead;k!=NULL;k=k->pnext)
    {
        cout << k->p.tu << "/" << k->p.mau << " " ;
    }
}
int main ()
{
    list l;
    khoitaolish(l);
    int n;
    cout << "\nSo phan tu: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "\na[" << i <<"] = ";
        int x;
        cout << "\nx = ";
        cin >> x;
        int y;
        cout << "\ny= ";
        cin >> y;
        node *p= tao1node(x,y);
        //them1nodedau(l,p);
        them1nodecui(l,p);
    }
    cout << "\nDanh sach: ";
    output(l);
   // xoadau(l);
  //  xoacui(l);
    themsauvitri(l);
    cout << "\nDanh sach sau xoa: ";
    output(l);
    return 0;
}

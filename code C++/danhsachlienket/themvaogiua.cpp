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
void outputds(danhsach l)
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
// bài tập mảng: thêm số tại vị trí
// bài này là: thêm 1 số vào kế số cho trước
// nó ngược lại--> bình tĩnh mà làm, đún gòi
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
// 2 trường hợp:
// TH 1: danh sách chỉ có 1 phần tử -> thêm đầu
    int x;
    cout << "\n mun them sau so may: ";
    cin >> x;
    node *q= khoitao1nodecogiatri(x);
    // nếu danh sách chỉ có 1 phần tử thì thì bbài toán trỏ thành thêm 1 phàn tử vào đầu dnah sách
    if( q ->data == l.phead->data && l.phead->pnext==NULL)
    {
        them1nodecui(l,p);
    }
// TH 2: nhìu phần tử
    else
    {
        // duyệt từ đầu đến cui, tìm k
        for(node *k=l.phead;k!=NULL;k=k->pnext)
        {
            if(q->data == k->data)
            {
                /* Cách 2:
                node *g=k->pnext; // tạo 1 node trung gian giu lin kết giữa 2 node cần chèn giữa
                        nodegt->pnext=g; // lấy node kia thế dô cái ndoe mới tạo ra
                        k->pnext=nodegt; // thay đổi lin kết đa có
                */
                node *h= khoitao1nodecogiatri(p->data); // khởi tạo 1 node mới để thêm.
                node *ptemp = k->pnext; // node temp sẽ trỏ tới vị trí sau q
                h->pnext=ptemp; // p trỏ tới ptemp
                k->pnext=h;
// cần để ý giá trị phia sau của q vì nếu ko làm đúng thứ tự này nó sẽ ko giữ đc các giá trị phía sau-> mất
// LỖI: NẾU CÓ 2 GIÁ TRỊ TRÙNG NHAU TRONG MÃNG THÌ NÓ SẼ KHÔNG GIỮ ĐC CÁC GIA TRỊ (  GIỐNG BÀI UCLN)-- > CẦN TẠO RA NODE MỚI LƯU GIÁ TRỊ.

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
        /*   Cấp 1: mảng ko có phần tuwr bị trùng
        node *hay= new node;
        for(node *k=l.phead;k!=NULL;k=k->pnext)
        {
            if(k->data == nodevt->data)
            {
                node *g=hay->pnext;
                nodegt->pnext=g;
                hay->pnext=nodegt;
            }
            hay=k; // giữ lại node phía trước ----> hay hay hay
        }*/
        // cấp 2: Mảng có phân tuwr bị trùng
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

int main ()
{
    danhsach l;
    khoitao1danhsach(l);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int d;
        cout << "\na[" << i << "] = ";
        cin >> d;
        node *q= khoitao1nodecogiatri(d);
        //them1nodedau(l,q);
        them1nodecui(l,q);
    }
    cout << "\nmang chinh la: ";
    outputds(l);
    /*int a;
    cout << "\nGia tri can thim: ";
    cin >> a;
    node *p= khoitao1nodecogiatri(a);
    themnode_p_vaosaunode_q(l,p);*/
    themvaotruoc(l);
    outputds(l);
    return 0;
}

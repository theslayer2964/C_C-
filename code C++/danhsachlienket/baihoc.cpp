// ---------Mảng 1 chìu-------------
// Ưu đỉm:
// + Truy xuất đến từng phần tử của mảng thông qua toán tử chỉ số
// + Ít tốn bộ nhớ
// Khuyết đỉm:
// + các phần tử trong mảng 1 chìu phải nằm lin típ trong mảng bộ nhớ -> phân mảng bộ nhớ
// + thêm, xóa khó khăn
// + cần bít trước số lượng phần tử
// ---------danh sách liên kết------
// Ưu đỉm:
// + thêm, xóa dễ bằng cách change lin kết giữa 2 note
// + o cần bít trước số lượng phần tử
// + không cần nằm lin típ trong mảng bộ nhớ
// Khuyết đỉm:
// + Không thể truy xuất đến từng phần tử của mảng thông qua toán tử chỉ số
// + Tốn bộ nhớ do lưu pointer
// mỗi note gồm có data (chứa dữ lịu) & pointer(lin kết các phàn tử vs nhau)
// List lin kết có 3 loại : đơn, phòng, kép.
// Phead: note đầu
// Ptall: note cúi
#include <iostream>
using namespace std;
#include <stdio.h>
// khái báo cấu trúc của 1 node
struct node
{
    int data;
    struct node *pnext; // con trỏ lin kết giữa các node vs nhau
};
// khái báo cấu trúc của 1 danh sách lin kết
struct list
{
    // đây là 2 cái con trỏ đầu cúi, không có data
    node *phead;
    node *ptail;
};
void khoitaodanhsachlinket(list &l)
{
    l.phead=NULL; // firstly, danh sách lket: gồm 2 cái node trỏ đến NULL
    l.ptail=NULL;
}
node *khoitao1node(int x)
{
    node *p= new node; //cấp vùng nhớ cho node p
    p->data=x; // truyền giá trị x cho data
    p->pnext=NULL;
    return p;
}
// List chỉ đi theo 1 chìu nhất định. So, head --> next và next -> tail.
void them1nodedau(list &l,node *p) // p: 1 caid node mới vừa tạo ra mới
{
    if(l.phead==NULL) // danh sách đang rỗng
    {
        l.phead=l.ptail=p;
    }
    else // danh sách đã có, thêm 1 vào
    {
        // 2 buoc lam:
    p->pnext = l.phead; //B1: node vừa tao ra gán vào đầu list
    l.phead = p; // B2: cap nhat lai gia tri cua head, là p
    }
}
void them1nodecui(list &l,node *p)
{
    if(l.phead==NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
    l.ptail->pnext=p;
    l.ptail=p;        // cập nhật lại
    }
}
void xuatdanhsahlk(list l)
{
    cout << "\ndanh sach chinh la: ";
    for(node *k = l.phead; k != NULL; k=k->pnext)//for(int i=0;i<n;i++)
    {
        cout << k->data << " ";
    }
}
int timmax(list l)
{
    int max=l.phead->data;
    for(node *k=l.phead->pnext;k!=NULL;k=k->pnext)
    {
        if(max < k->data)
        {
            max=k->data;
        }
    }
    return max;
}
// thêm 1 node vào danh sách khi bít trước phần tử phía trước
// phá bỏ lin kết đã có và chèn nó vào giữa
int main ()
{
    list l;
    khoitaodanhsachlinket(l);
    int n;
    cout << "\nSo phan tu: " ;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cout << "\na[" << i << "] = ";
        cin >> x;
        node *p = khoitao1node(x); // lưu x vào cái node vùa khởi tạo ra
        //them1nodedau(l,p);
        them1nodecui(l,p);
    }
    xuatdanhsahlk(l);
    cout << "\nmax chinh la: " << timmax(l);
    return 0;
}

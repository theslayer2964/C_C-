//--------------------------- QUEUE (hầng đợi) -------------------------------------
// - là 1 cấu trúc trừu tượng mà các đối tương hoạt dộng theo cơ chế FIFO(First In First Out)
// IsEmpty: check queue có rỗng hay ko
// Push: add 1 đối tượng vào cuối queue ( cơ chế FIFO)
// Pop: lấy đối tượng đầu của queue + xóa
// Top: xem thông tin của queue first, ko xoá
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *pnext;
};
struct queue
{
    node *phead;
    node *ptail;
};
void khoitaoqueue(queue &q)
{
    q.phead=NULL;
    q.ptail=NULL;
}
node *khoitao1node(int x)
{
    node *ptemp = new node;
    ptemp ->data =x;
    ptemp->pnext =NULL;
    return ptemp;
}
// IsEmpty: check queue có rỗng hay ko
bool IsEmpty(queue q)
{
    if (q.phead == NULL)
    {
        return true;
    }
    return false;
}
// Push: add 1 đối tượng vào cuối queue ( cơ chế FIFO)
// thêm cúi
bool push(queue &q,node *p)
{
    if( p == NULL)
    {
        return false;
    }
    if( IsEmpty(q) == true)
    {
        q.ptail = q.phead = p;
    }
    else
    {
        q.ptail->pnext = p;
        q.ptail = p;
    }
    return true;
}
// Pop: lấy đối tượng đầu của queue + xóa
bool pop(queue &q,int &x)
{
    if(IsEmpty(q) == true)
    {
        return false;
    }
    else
    {
       node *p= q.phead;
       x = p->data;
       q.phead = q.phead->pnext;
       delete p;
    }
    return true;
}
// Top: xem thông tin của queue first, ko xoá
bool top(queue q,int &x)
{
    if(IsEmpty(q) == true)
    {
        return false;
    }
    else
    {
        x= q.phead->data;
        cout << x;
    }
    return true;
}
void output(queue q)
{
    while(IsEmpty(q) == false)
    {
        int x;
        pop(q,x);
        cout << x << " ";
    }
    if(IsEmpty(q) == true)
    {
        cout << "\nrong";
    }
    else cout << "\nCon ms";
}
int main ()
{
    queue q;
    khoitaoqueue(q);
    int chon;
    do
    {
        int x;
        cout << "\nNhap gia tri: ";
        cin >> x;
        node *p=khoitao1node(x);
        push(q,p);
        cout <<  "\nMun nhap o(chon 1 de nhap): ";
        cin >> chon;
    }
    while ( chon == 1);
    int a;
    cout << "\nPhan tu dau tin cua queue: ";
    top(q,a);
    cout << "\nNgan xep: ";
    output(q);
    cout << "\nPhan tu dau tin cua queue: ";
    top(q,a);
    return 0;
}



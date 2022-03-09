
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *pnext;
};
struct stack
{
    node *ptop;
};
// dùng 1 con trỏ quản lí (ptop) -> vì nó chỉ quan tâm đến cái đầu
void khoitaostack(stack &s)
{
    s.ptop=NULL;
}
// khởi tạo 1 cái stack + IsEmpty: check stack có rỗng hay ko
bool IsEmpty(stack s)
{
    if(s.ptop == NULL)
    {
        return true;
    }
    return false;
}
// Push: add 1 đối tượng vào  đầu stack ( cơ chế LIFO )
// bước 1: khởi tạo node
node *khoitaonode(int x)
{
    node *p =  new node;
    p->data =x;
    p->pnext=NULL;
    return p;
}
// bước 2: thêm dô
bool push(stack &s,node *p)
{
    if( p == NULL)
    {
        return false;
    }
    if(IsEmpty(s)== true)
    {
        s.ptop = p;
    }
    else
    {
        p->pnext = s.ptop;
        s.ptop = p;
    }
    return true;
}
// Pop: lấy đối tượng đầu của stack và xóa nó lun
bool pop(stack &s,int &x)
{
    if(IsEmpty(s) == true) // tương đương với == true
    {
        return false;
    }
    else
    {
// tạo thêm node *p trỏ tới x; có 2 node sẽ trỏ tới x, cập nhật lại ptop
// xóa p đi sẽ xóa đc giá trị
        node *p = s.ptop;
        x=p->data;
        s.ptop = s.ptop->pnext;
        delete p;
    }
    return true;
}
// Top: xem thông tin của stack first, ko xoá
bool top(stack s,int &x)
{
    if(IsEmpty(s) == true)
    {
        return false;
    }
    else
    {
        x = s.ptop->data;
        cout << x;
    }
    return true;
}
void chuyendoi(stack &s,int &x,int &coso)
{
    do
    {
        int k;
        k=x%coso;
        node *ptemp= khoitaonode(k);
        push(s,ptemp);
        x=x/coso;
    }
    while ( x>0);
}

void output(stack s)
{
    while(IsEmpty(s)== false)
    {
        int x;
        pop(s,x);
        if(x == 10)
            cout << "A";
            else if(x == 11)
            cout << "B";
            else if(x == 12)
            cout << "C";
            else if(x == 13)
            cout << "D";
            else if(x == 14)
            cout << "E";
            else if(x == 15)
            cout << "F";
            else
            cout << x;
    }
}

int main ()
{
    stack s;
    khoitaostack(s);
    int x;
    cout << "\nNhap gia tri can them:";
    cin >> x;
    int coso;
    cout << "\nNhap co so (2 8 16)mun doi:";
    cin >> coso;
    cout << "\nChuyen doi co so: ";
    chuyendoi(s,x,coso);
    output(s);
    return 0;
}


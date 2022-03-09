#include <iostream>
using namespace std;
struct node
{
    int data;
    node *pnext;
};
struct singlelist
{
    node *phead;
};
// taoj ra list đầu tin chưa có phần tử nào nên cần tham chíu
// list này là 1 struct bình thường, ko phảo pointer nên '.'
void initialize(singlelist &l)
{
    l.phead=NULL;
}
node *createnote(int d)
{
    node *pnode = new node;
    if(pnode!=NULL)
    {
        pnode->data=d; // node là pointer nên phải dùng toán tử trỏ '->'
        pnode->pnext=NULL;
    }
    else cout << "\ncap phat thua";
    return pnode;
}
 void printlist(singlelist l)
 {
     node *ptemp=l.phead;
     while (ptemp !=NULL)
     {
         cout << ptemp->data;
         ptemp=ptemp->pnext;
     }
 }
 int sizeoflist(singlelist l)
 {
     node *ptemp = l.phead;
     int nsize=0;
     while (ptemp!=NULL)
     {
         ptemp=ptemp->pnext;
         nsize++;
     }
     return nsize;
 }
 void insertnode(singlelist &l,int d)
 {
     node *pnote= createnote(d);
     if(l.phead==NULL)
     {
         l.phead=pnote;
     }
     else
     {
         pnote->pnext=l.phead;
         l.phead=pnote;
     }
 }
int main ()
{
    singlelist l;
    initialize(l);
    int x;
    cin >> x;
    for(int i=0;i<x;i++)
    {
        int a;
        cin >> a;
        //node *p = createnote(a);
        insertnode(l,a);

    }
    printlist(l);
    return 0;
}

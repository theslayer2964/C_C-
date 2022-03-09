#include <stdio.h>
struct node
{
	float heSo;
	int soMu;
	node *pnext;
};
struct list
{
	node *phead,*ptail;
};

void khoitao(list &l)
{
	l.phead= NULL;
	l.ptail= NULL;
}
node *tao1node(float heSo,int soMu){
	node *p ;
	p =  new node;
	if(p==NULL){
		return NULL;
	}
	p->heSo=heSo;
	p->soMu=soMu;
	p->pnext=NULL;
	return p;
}
void swap1(float &a,float &b)
{
    float temp=a;
    a=b;
    b=temp;
}
void swap2(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
void interchangeSort(list &l)
{
	for(node *p=l.phead;p!=l.ptail;p=p->pnext)
		for(node *q=p->pnext;q!=NULL;q=q->pnext)
	{
		if(q->soMu > p->soMu)
		{
			swap1(p->heSo,q->heSo);
			swap2(p->soMu,q->soMu);
		}
	}
}
void addlast(list &l,node *p){
	if(l.phead==NULL){
		l.phead=l.ptail=p;
	}
	else {
		l.ptail->pnext=p;
		l.ptail=p;
	}
}
void insert(list &l,float heSo,int soMu){
	node *p=tao1node(heSo,soMu);
	if(p==NULL){
		return;
	}
	addlast(l,p);
}
void nhapdathuc(list &l){
	float heSo;
	int soMu;
	printf("\nBat dau nhap da thuc (nhap so 0 de ket thuc): \n");
	do{
		printf("\nNhap he so: ");
		scanf("%f",&heSo);
		if(heSo==0)
			break;
		printf("\nNhap so mu: ");
		scanf("%d",&soMu);
		insert(l,heSo,soMu);
	}
	while(heSo!=0);
	printf("\nDa nhap da thuc xong.\n");
	interchangeSort(l);
}
void xuatDanhSach(list l)
{
	for(node *k=l.phead;k!=NULL;k=k->pnext)
	{
		printf("%.0fx^%d",k->heSo,k->soMu);
            if(k==l.ptail)
            {
                printf("");
            }
            else
                {
                    if(k->pnext->heSo>0)
                        printf("+");
                    else
                        printf("");
            }
	}
}
void trudathuc(list l1,list l2,list &l3){
	khoitao(l3);
	node *p=l1.phead;
	node *q=l2.phead;
	float tongHeSo=0;
	while(p&&q)
	{
		if(p->soMu == q->soMu)
		{
			tongHeSo=p->heSo-q->heSo;
			if(tongHeSo!=0)
				insert(l3,tongHeSo,p->soMu);
				p=p->pnext;
				q=q->pnext;
		}
			else
			{
				if(p->soMu > q->soMu)
				{
					insert(l3,p->heSo,p->soMu);
					p=p->pnext;
				}
				else
				{
					if(p->soMu < q->soMu)
					{
						insert(l3,q->heSo,q->soMu);
						q=q->pnext;
					}
				}
		}
	}
	while(q)
	{
		insert(l3,q->heSo,q->soMu);
		q=q->pnext;
	}
	while(p)
	{
		insert(l3,p->heSo,p->soMu);
		p=p->pnext;
	}
}
int main()
	{
	list l1,l2,l3;
	khoitao(l1);
	khoitao(l2);
	khoitao(l3);
	nhapdathuc(l1);
	printf("\nDanh sach bieu thuc da thuc d1: ");
	xuatDanhSach(l1);
	nhapdathuc(l2);
	printf("\nDanh sach bieu thuc da thuc d2: ");
	xuatDanhSach(l2);
	printf("\nDanh sach bieu dien da thuc tong: ");
	trudathuc(l1,l2,l3);
	xuatDanhSach(l3);
	return 0;
}

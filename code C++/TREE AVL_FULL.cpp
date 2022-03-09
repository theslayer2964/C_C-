#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

#define LH -1
#define EH 0
#define RH 1

struct AVLNode
{
    int x;
    char CSCB;
    AVLNode *pLeft;
    AVLNode *pRight;
};

typedef AVLNode * AVLTree;

void Initine(AVLTree &Root)
{
    Root = NULL;
}

AVLNode *CreateAVLNode(int x)
{
    AVLNode *p = new AVLNode;

    if (!p) exit(1);

    p->CSCB = EH;
    p->x = x;
    p->pLeft = NULL;
    p->pRight = NULL;

    return p;
}

//cay con trai lech trai
void Rotate_Left_Left(AVLTree &Root)
{
    AVLNode *p;

    p = Root->pLeft;
    Root->pLeft = p->pRight;
    p->pRight = Root;

    switch (p->CSCB)
    {
    case LH:
        Root->CSCB = EH;
        p->CSCB = EH;
        break;
    case EH:
        p->CSCB = RH;
        Root->CSCB = LH;
        break;
    }

    Root = p;
}

//cay con phai lech phai
void Rotate_Right_Right(AVLTree &Root)
{
    AVLNode *p;

    p = Root->pRight;
    Root->pRight = p->pLeft;
    p->pLeft = Root;

    switch (p->CSCB)
    {
    case EH:
        Root->CSCB = RH;
        p->CSCB = EH;
        break;
    case RH:
        p->CSCB = EH;
        Root->CSCB = EH;
        break;
    }

    Root = p;
}

//cay con phai lech trai
void Rotate_Right_Left(AVLTree &Root)
{
    AVLNode *p1, *p2;

    p1 = Root->pRight;
    p2 = p1->pLeft;
    Root->pRight = p2->pLeft;
    p1->pLeft = p2->pRight;
    p2->pLeft = Root;
    p2->pRight = p1;

    switch (p2->CSCB)
    {
    case LH:
        Root->CSCB = EH;
        p1->CSCB = RH;
        break;
    case EH:
        Root->CSCB = EH;
        p1->CSCB = EH;
        break;
    case RH:
        Root->CSCB = LH;
        p1->CSCB = EH;
        break;
    }

    p2->CSCB = EH;
    Root = p2;
}

//cay con trai lech phai
void Rotate_Left_Right(AVLTree &Root)
{
    AVLNode *p1, *p2;

    p1 = Root->pLeft;
    p2 = p1->pRight;
    Root->pLeft = p2->pRight;
    p1->pRight = p2->pLeft;
    p2->pRight = Root;
    p2->pLeft = p1;

    switch (p2->CSCB)
    {
    case LH:
        p1->CSCB = EH;
        Root->CSCB = RH;
        break;
    case EH:
        Root->CSCB = EH;
        p1->CSCB = EH;
        break;
    case RH:
        Root->CSCB = EH;
        p1->CSCB = LH;
        break;
    }

    p2->CSCB = EH;
    Root = p2;
}

//Can bang khi cay lech trai
int BalanceLeft(AVLTree &Root)
{
    AVLNode *p;

    p = Root->pLeft;

    switch (p->CSCB)
    {
    case LH:
        Rotate_Left_Left(Root);
        return 2;
    case EH:
        Rotate_Left_Left(Root);
        return 1;
    case RH:
        Rotate_Left_Right(Root);
        return 2;
    }
}

//can bang cay lech phai
int BalanceRight(AVLTree &Root)
{
    AVLNode *p;

    p = Root->pRight;

    switch (p->CSCB)
    {
    case RH:
        Rotate_Right_Right(Root);
        return 2;
    case EH:
        Rotate_Right_Right(Root);
        return 1;
    case LH:
        Rotate_Right_Left(Root);
        return 2;
    }
}

//Chen 1 node vao cay AVL
int InsertNode(AVLTree &Root, int x)
{
    int Res;
    if (Root)
    {
        //gia tri da co trong cay
        if (Root->x == x) return 0;

        //Root->x > x
        //chen vao ben trai
        if (Root->x > x)
        {
            Res = InsertNode(Root->pLeft, x);
            if (Res < 2) return Res;

            //Res >= 2
            switch (Root->CSCB)
            {
            case RH:
                Root->CSCB = EH;
                return 1;
            case EH:
                Root->CSCB = LH;
                return 2;
            case LH:
                BalanceLeft(Root);
                return 1;
            }
        }

        //Root->x < x
        //chen vao ben phai
        else
        {
            Res = InsertNode(Root->pRight, x);

            if (Res < 2) return Res;

            //Res >= 2
            switch (Root->CSCB)
            {
            case LH:
                Root->CSCB = EH;
                return 1;
            case EH:
                Root->CSCB = RH;
                return 2;
            case RH:
                BalanceRight(Root);
                return 1;
            }
        }
    }

    Root = CreateAVLNode(x);
    return 2;
}

//Tim node the mang
int SearchStandFor(AVLTree &Root, AVLNode *&p)
{
    int Res;

    if (p->pLeft)
    {
        Res = SearchStandFor(Root, p->pLeft);

        if (Res < 2) return Res;

        switch (p->CSCB)
        {
        case LH:
            p->CSCB = EH;
            return 1;
        case EH:
            p->CSCB = RH;
            return 2;
        case RH:
            return BalanceRight(Root);
        }
    }

    Root->x = p->x;
    Root = p;
    p = p->pRight;
    return 2;
}

//Xoa 1 node tren cay
int DelNode(AVLTree &Root, int x)
{
    int Res;

    //Khong ton tai node nay tren cay
    if (!Root) return 0;

    //Qua duoc if tren tuc la ton tai
    //Root->x > x => Sang ben trai tim xoa
    if (Root->x > x)
    {
        Res = DelNode(Root->pLeft, x);

        //Neu co xoa thi Res = 1 hoac 2. 2 tuc thay doi chieu cao cay
        if (Res < 2) return Res;

        //Chieu cao bi thay doi
        switch (Root->CSCB)
        {
        case LH:
            Root->CSCB = EH;
            return 2;
        case EH:
            Root->CSCB = RH;
            return 1;
        case RH:
            return BalanceRight(Root);
        }
    }

    if (Root->x < x)
    {
        Res = DelNode(Root->pRight, x);

        if (Res < 2) return Res;

        switch (Root->CSCB)
        {
        case LH:
            return BalanceLeft(Root);
        case EH:
            Root->CSCB = LH;
            return 1;
        case RH:
            Root->CSCB = EH;
            return 2;
        }
    }
    else
    {
        //Root->x = x
        AVLNode *p1 = Root;

        if (Root->pLeft == NULL)
        {
            Root = Root->pRight;
            Res = 2;
        }
        else
        {
            if (Root->pRight == NULL)
            {
                Root = Root->pLeft;
                Res = 2;
            }
            else
            {
                Res = SearchStandFor(p1, Root->pRight);

                if (Res < 2) return Res;
                switch (Root->CSCB)
                {
                case RH:
                    Root->CSCB = EH;
                    return 2;
                case EH:
                    Root->CSCB = LH;
                    return 1;
                case LH:
                    return BalanceRight(Root);
                }
            }
            delete p1;
            return Res;
        }
    }

}
//Duyet theo muc
void LNR(AVLTree Root)
{
    if (Root == NULL) return;

//cout<<Root->x<<"  ";
    LNR(Root->pLeft);
    cout<<Root->x<<"  ";
    LNR(Root->pRight);
 //   cout<<Root->x<<"  ";
}
void CreateTree(AVLTree &Root)
{
    int x;
    do
    {
        cout << "x = 0 de thoat: x = ";
        cin >> x;
        if (x == 0) break;
        InsertNode(Root, x);
    } while (1);
}
int sum(AVLTree Root)   /// tính tổng tất cả node
{
    if(Root)
    {
        return sum(Root->pLeft)+ sum(Root->pRight) + Root->x;
    }
}
int sumLeaf(AVLTree Root)
{
    if(Root)
    {
        if(Root->pLeft==NULL && Root->pRight==NULL)
            return Root->x;
        else return sumLeaf(Root->pLeft)+sumLeaf(Root->pRight);
    }
}
int count(AVLTree Root) /// đếm số node
{
    if(Root)
    {
        if(Root->pLeft==NULL && Root->pRight==NULL)
            return 1;
        return 1 + count(Root->pRight) + count(Root->pLeft);
    }
}
int countLeaf(AVLTree Root) /// đếm số node lá trên cây
{
    if(Root)
    {
        if(Root->pLeft==NULL && Root->pRight==NULL)
            return 1;
        return countLeaf(Root->pLeft)+countLeaf(Root->pRight);
    }
}
int height(AVLTree Root) /// tính chiều cao cây
{
    if(Root)
    {
        if(Root->pLeft==NULL && Root->pRight==NULL)
            return 1;
        return 1+ ((height(Root->pLeft)> height(Root->pRight))? height(Root->pLeft)
                   : height(Root->pRight));
    }
}
int max(AVLTree Root)/// node MAX
{
    if(Root)
    {
        if(Root->pRight==NULL)
            return Root->x;
        return max(Root->pRight);
    }
}
int mucCuaMax(AVLTree Root)   /// mức node MAX
{
    if(Root)
    {
        if(Root->pRight==NULL)
            return 0;
        return 1 + mucCuaMax(Root->pRight);
    }
}
int min(AVLTree Root)   /// node MIN
{
    if(Root)
    {
        if(Root->pLeft==NULL)
            return Root->x;
        return min(Root->pLeft);
    }
}
int mucCuaMin(AVLTree Root) /// Mức node MIN
{
    if(Root)
    {
        if(Root->pLeft==NULL)
            return 0;
        return 1 + mucCuaMin(Root->pLeft);
    }
}
int mucCuaNodeBatKi(AVLTree Root,int a)
{
    if(Root)
    {
        if(Root->x==a)
            return 0;
        if(Root->x>a)

            return 1 + mucCuaNodeBatKi(Root->pLeft, a);
       else
            return 1 + mucCuaNodeBatKi(Root->pRight, a);
    }
}
int main()
{
	int chieucao;
	int x;
    AVLTree Root;
    Initine(Root);
    CreateTree(Root);
    LNR(Root);
    printf("--\n");
    chieucao= height(Root);
    printf("Chieu Cao: %d", chieucao);
    printf("\nMax chinh la: %d",max(Root));
    printf("\nMuc cua Node Max chinh la: %d",mucCuaMax(Root));
    printf("\nMin chinh la: %d",min(Root));
    printf("\nMuc cua Node Min chinh la: %d",mucCuaMin(Root));
    printf("\nTong: %d",sum(Root));
    printf("\nDem so node: %d",count(Root));
    printf("\nDem so node la: %d",countLeaf(Root));
    printf("\nNhap x:");
    int a;
    scanf("%d",&a);
    printf("\nMuc cua node bat ki: %d",mucCuaNodeBatKi(Root,a));
    printf("\nTong la: %d",sumLeaf(Root));
    return 0;
}


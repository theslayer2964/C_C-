#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;
struct tudien
{
    string anh;
    string viet;
};
void doc1dong(ifstream &filein,tudien &l)
{
    getline(filein,l.anh,':');
    getline(filein,l.viet);
}
void docfile(ifstream &filein,tudien *l,int &n)
{
    filein.open("C:\\Users\\Sony Vaio\\Desktop\\vitcode\\tudien.txt",ios_base::in);
    int i=0;
    while(filein.eof()==false)
    {
    fflush(stdin);
    getline(filein,l[i].anh,':');
    cout << l[i].anh;
    fflush(stdin);
    getline(filein,l[i].viet,'\n');
    cout << l[i].viet;
    fflush(stdin);
    i++;
    }
    n=i;
    filein.close();
}
void inramanhinh(ifstream &filein,tudien *l,int n)
{
    docfile(filein,l,n);
    for(int i=0;i<n;i++)
    {
        cout << "lala";
        cout << l[i].anh <<":"<< l[i].viet;
    }
    filein.close();
}
void ghivaofile(ofstream &fileout,tudien *l,int &n)
{
    fileout.open("C:\\Users\\Sony Vaio\\Desktop\\vitcode\\tudien.txt",ios_base::app);
    if(fopen==NULL)
    {
        cout << "khong ton tai";
    }
        n=1;
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            cout << "\nNhap tu tieng anh:";
            getline(std::cin,l[i].anh);
            fileout << l[i].anh;
            cout << "\nNhap tu tieng viet:";
            getline(std::cin,l[i].viet);
            fileout << ":" << l[i].viet << "\n";
        }

    fileout.close();
}
void tracuutudien(ifstream &filein,tudien *l,int n)
{
    docfile(filein,l,n);
    string x;
    printf("\nNhap tu can tra:");
    cin >> x;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(x==l[i].anh || x==l[i].viet)
        {
            cout << l[i].anh << ":" << l[i].viet;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout <<"\nChua co du lieu";
    }
}
void xoatudien(ifstream &filein,tudien *l,int &n)
{
    docfile(filein,l,n);
    string x;
    cout <<"\nNhap tu can xoa:";
    cin >> x;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(x==l[i].anh || x==l[i].viet)
        {
            for(int j=i+1;j<n;j++)
            {
                cout << "lalalala";
                l[j-1]=l[j];
                flag++;
            }
            //flag==1;
            n--;
        }
    }
    if(flag==0)
    {
        cout <<"\nChua co du lieu";
    }
   // ghivaofile(file,l,n);

}
int main()
{
int n,KT=1, chon;
string *a;
ifstream filein;
ofstream fileout;
tudien *l;
printf("------------TU DIEN ANH-VIET-----");
	while(KT)
	{
	    system("cls");
		printf("\nChon chuc nang");
		printf("\n 1. Them 1 tu");
		printf("\n 2. Sua tu");
		printf("\n 3. Xoa tu");
		printf("\n 4. Tra cuu");
		printf("\n 5. Hien thi toan bo");
		printf("\n 6. Thoat");
		printf("\nGo so tuong ung chuc nang can chon chon=");
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
                    ghivaofile(fileout,l,n);
					break;
			case 2:

					break;
			case 3:
                    xoatudien(filein,l,n);
                    getch();
					break;
			case 4:
					tracuutudien(filein,l,n);
					getch();
					break;
            case 5:
                    inramanhinh(filein,l,n);
                    getch();
					break;
			case 6: KT=0;
		}
	}
}

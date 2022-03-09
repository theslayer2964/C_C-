#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h>
struct tudien
{
    char anh[30];
    char viet[30];
};
void doc1dong(FILE *fp,tudien &l)
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
    doc1dong(filein,l[i]);
    i++;
    }
    n=i;
}
void inramanhinh(ifstream &filein,tudien *l,int n)
{
    docfile(filein,l,n);
    for(int i=0;i<n;i++)
    {
        cout << l[i].anh <<":"<< l[i].viet << "\n";
    }
    //fclose();
}
void ghivaofile(FILE *fp,tudien *l,int &n)
{
    fp=fopen("C:\\Users\\Sony Vaio\\Desktop\\vitcode\\tudien.txt","a");
    if(fopen==NULL)
        cout << "\nKo ton tai";
        n=1;
        for(int i=0;i<n;i++)
    {
        printf("\nNhap tu tieng anh:");
        scanf("%s",&l[i].anh);
        fscanf(fp,"%s",&l[i].anh);
        fflush(stdin);
        printf("\nNhap tu tieng viet:");
        scanf("%s",&l[i].viet);
        fscanf(fp,"%s",&l[i].viet);
    }
    n++;
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
tudien l[100];
FILE *fp;
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
                    ghivaofile(fp,l,n);
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


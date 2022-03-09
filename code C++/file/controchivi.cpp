// HÀM DỊCH CHUYỂN CON TRỎ CHỈ VỊ TRONG FILE:
// seekg(x,y)
//      + x: số byte cần dịch chuyển (lun lun là số nguyên)
//          - x<0: dịch về trái
//          - x>0: dịch về phải
//      + y: vị trí bắt đầu của con trỏ
//          - ios::beg  : vị trí đầu file (begin) <==> seek_set
//          - ios::cur  : vị trí now              <==> seek_cur
//          - ios::end  : vị trí cúi file         <==> seek_end
#include <iostream>
using namespace std;
#include <fstream>
struct data
{
    int ngay;
    int thang;
    int nam;
};
void docchu(string &x,ifstream &filein)
{
    getline(filein,x,' ');
}
void docfile(data &d,ifstream &filein)
{
    filein >> d.ngay;
    filein.seekg(1,ios::cur);
    filein >> d.thang;
    filein.seekg(1,ios::cur);
    filein >> d.nam;
}
void xuatfile(data d,string x)
{
 //   cout << x << endl;
    cout << d.ngay ;
    cout << d.thang ;
    cout << d.nam ;
}

int main()
{
    data date;
    string x;
    ifstream filein;
    filein.open("C:\\Users\\Sony Vaio\\Desktop\\code C++\\789.txt",ios_base::in);
  //  docchu(x,filein);
    docfile(date,filein);
    xuatfile(date,x);
    filein.close();
    return 0;
}

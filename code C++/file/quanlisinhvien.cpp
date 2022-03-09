#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
struct monhoc
{
    string tenmonhoc;
    float diem;
};
struct sinhvien
{
    string hoten; // string này khai báo khác vs string bên C
    string mssv;
    string ngaysinh;
    vector <monhoc> ds_monhoc; // khai báo mảng  chìu của 1 sinh vien
};
void docthongtin1sinhvien(ifstream &filein,sinhvien &sv)
{
    getline(filein,sv.hoten,','); // getline: đọc thông tin trong C++ tất cả thông tin của dòng, phẩy chấm cách lun.....
    getline(filein,sv.mssv,',');
    getline(filein,sv.ngaysinh);
    // có 2 cách để vít hàm này, cắt tới dấu ' ' hoặc không cắt nữa (đọc đến cúi dòng)
}
void docthongtin1monhoc(ifstream &filein,monhoc &mon)
{
    getline(filein,mon.tenmonhoc,'-');
    filein >> mon.diem;
}
int main ()
{
    return 0;
}

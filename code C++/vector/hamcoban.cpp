// vector: mảng 1 chìu - mảng động - siu mảng động
//---------------- ưu đỉm
// có hết tất cả tính chất của tĩnh và động.
// siu mảng động: o cần khai báo kích thước của mảng cần thao tác - cơ chế tự động thêm phần tử push_back()
// tự động giải phóng vùng nhớ khi chương trình kết thúc
// thao tác thêm, xóa, sủa, tìm kím, sắp xếp : có sẵn
// ----------- khuyết đỉm
// tốn bộ nhớ(container): buộc phải tạo ra thêm vùng nhớ để quản lí chặt chẽ.
// Vector, string, list, quene, stack :thuộc thư vịn chuẩn của c++ : STL (Standard Template Library)
#include <iostream>
using namespace std;
#include <vector>
void outputvector(vector <int> a)
{
    cout << "\nMang gom: " ;
    for(int i=0;i<a.size();i++) // a.size == strlen(a) --> ngược
    {
        cout << a.at(i) << " "; // a.at(i) == a[i]
    }
}
int main ()
{
    // khai bao
    // vector <phanso> a  mảng struct
    vector <int> a;
    // hàm resize(số lượng): cấp phát mảng vs số lượng phần tử cho trước. các phần tử đều mang giá trị 0(giống hàm calloc)
    // nếu đã có rồi thì hàm sẽ thay đổi kích thước vector(mất phần tử nếu thíu, dư: giữ lại)
    a.resize(5,10);
    outputvector(a);
    // resize(<so luong><gia tri mỗi a[i]>)
    a.resize(10);
    outputvector(a);
    return 0;
}

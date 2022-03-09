#include <iostream>
using namespace std;
#include <vector>
void outputvector(vector <int> a)
{
    cout << "\nMang:" ;
    for(int i=0;i<a.size();i++)
    {
        cout <<a.at(i) << " ";
    }
}
void hamxoavector(vector <int> a)
{
    a.erase(a.begin() + 2); // xóa phần tử
    // xóa những phần tử trong khoảng
    cout << "\nXoa: ";
    outputvector(a);
}
void hamthimvector(vector <int> a)
{
    a.insert(a.begin() + 2,99); // vị trí phần tử, giía trị thim
    // thêm những phần tử trong khoảng
    cout << "\nthim: ";
    outputvector(a);
}

int main ()
{
    vector <int> a;
    for(int i=0;i<5;i++)
    {
        a.push_back(i); // thêm phần tử có giá trị "i" vào cúi mảng
    }
    outputvector(a);
    cout << "\nSo phan tu thuc su: " <<a.capacity(); // khuyết đỉm của vector: tốn ô nhớ
    cout << "\nSo phan tu toi da: " <<a.max_size();
    a.pop_back(); // xóa phần tử cúi cùng trong mảng, pop_back() =/= push_back(i)
    outputvector(a);
    //cout << "\nXuat phan tu dau tin cua mang: " << a.front();
    //cout << "\nXuat phan tu cui cung cua mang: " << a.back();
    //hamxoavector(a);
    //hamthimvector(a);
    //a.clear() ;// xóa hết phần tử trong mảng
    vector <int> x;
    for(int i=0;i<15;i++)
    {
        x.push_back(i);
    }
    cout << "\nMang x: ";
    outputvector(x);
    a.swap(x); // hoán đổi 2 vector a và x
    // nó không quan tâm đến số lượng khác nhau giữa 2 cái mảng lun --> ghê ghê
    return 0;
}

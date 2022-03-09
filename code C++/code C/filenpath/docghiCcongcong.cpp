// ios_base ::in,  ---> khac C
// ios_base ::out
#include <iostream>
using namespace std;
#include <fstream> // thư vịn
#include <string>

int main ()
{
    ifstream filein;   //ifstream: đọc dữ lịu từ File
    filein.open ("C:\\Users\\Sony Vaio\\Desktop\\code C++\\123.txt",ios_base::in);//bước 2 : mở file.open("đuongan",mun lamm z)
    if(filein.fail() == true) //Kiểm tra file có tồn tai???
    {
        cout << "\ncouldn't find this file" << endl;
        return 0;   // kết thúc chương trình
    }
    //đọc dữ liệu từ file
    // dữ lịu khác sẽ bị xóa đi trong file
    int x;
    int y;
    filein >> x;      // thay vì dùng cin ---> ta dùng findin (hoặc con trỏ C), đọc số nguyên đầu tin ko cần bít nó owr đâu
    filein >> y;      // đọc số nguyên thứ 2 , không quan tâm đên ' ' 'enter '...
    cout << "tong cua 2 so " << x+y;
    filein.close();
    ofstream fileout; // ghi dữ lịu vào File
    fileout.open ("C:\\Users\\Sony Vaio\\Desktop\\code C++\\123.txt",ios_base::out);// nếu chưa tồn tại, câu lệnh này sẽ tạo file lun
    fileout << x+y; // nếu file ko tồn tại, sau khi tạo file mới, nó sẽ cộng qua
    fileout << "\n" << 100; // ghi thẳng vào file
    fileout.close();
    return 0;
}

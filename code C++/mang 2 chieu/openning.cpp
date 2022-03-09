// mảng 2 chiều: mảng chưa nhìu mảng 1 chìu, đc xác định dựa vào chỉ số dòng và cột
// hàng - cột
// Ma trận vuông:
// + đường chéo chính:\ .Các phần tử nằm trên đường chéo chính : a[0][0]...a[n][n];
// + đường chéo phụ:/ . Các phần tử nằm trên : a[0][3],a[1][2],a[2][1],a[][3]

#include <iostream>
using namespace std;
#define max_dong 100
#define max_cot 100
int main ()
{
    // Những cách khởi tạo:
    int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    //cách 2: int a[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};// mảng số nguyên 4 hàng 5 cột
    // cách 3: a[][4], ko cần số dòng, chỉ cần bít số cột thui --> hay ghê
  /*  for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << "\na[ "<< i <<"][ "<<j <<"] = ";
            cin >> a[i][j];
        }
    }*/
    cout << "\nDay chinh la: \n";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << a[i][j]<< " ";
        }
            cout << endl;
    }
    return 0;
}

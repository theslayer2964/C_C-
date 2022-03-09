#include <iostream>
using namespace std;
#include <time.h> // thư vịn này gọi hàm time, thời gian tính từ năm 1990 đến bây h --> lun thay đổi
#include <stdlib.h>
int main ()
{
    // hàm rand hoạt động xoay quanh  giá trị tủng tâm, so trung tâm thay đổi thì nó thay đổi.
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        cout << rand()%10 <<endl;
        // cout << 20 + rand()%10 << endl; // rand từ 20 đến 29;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main ()
{
    int *a= new int;
    *a=5;
    cout << "\nGia tri cua a: " << *a;
    delete a; // giải phóng vunngf nhớ con trỏ a
    return 0;
}

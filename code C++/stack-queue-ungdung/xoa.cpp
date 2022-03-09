#include <iostream>
using namespace std;
int main ()
{

    int x;
    cout << "\nNhap gia tri can them:";
    cin >> x;
    do
    {
        cout << x%2 << " ";
        x=x/2;
    }
    while (x>0);
    return 0;
}


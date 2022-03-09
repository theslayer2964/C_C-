#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
    cout << "hello world " << endl; // endl = \n
    int a(5);
    int b{7};
    cout << "a chinh la " << b << endl;
    cout << "a chinh la " << (float *)b;
    printf("\na= %d",(int *)a);
}

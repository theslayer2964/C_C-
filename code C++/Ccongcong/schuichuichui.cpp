//lớp : là cái z` không bít s. ...()
// lưu ý s.insert(vi tri,'kí tự')
// còn 2 hàm : lấy chũi con, finding --> chưa làm ,làm biếng =))


#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string s="lap trinh";
    for(int i=0;i<= s.length();i++)
    {
        cout << s[i] << endl;
    }
    s.erase(s.begin() + 3); // xoa ki tu tai vi tri thu 3
    cout <<"\nChui sau khi xoa la " << s;
    s.insert(s.begin()+3,'*'); // them ki tu tai vi tri
    cout <<"\nChui sau khi thim " << s;
    s.push_back('#'); // them 1 ki tu tai vi tri cuoi cung cua chui
    cout <<"\nChui sau khi thim " << s;
    cout <<"\nDo dai sau khi thim bot "  << s.length();
    return 0;
}



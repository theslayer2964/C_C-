// class: tập hợp những cái hàm

#include <iostream>
using namespace std;
class lala
{
    public: // ai cũng zài được
    // private : o phải ai cũng đc xài
    void meomeo()
    {
            cout << "\nahihihahaha";
    }
};
class mothaiba
{
    // hàm dựng, nhảy dô hàm lun, không bít làm z`. không cần truyền tham số
public: // nếu không ghi pubic thì máy tự mặc định là private
    mothaiba (){
    cout << "\nham dung - constructor" << endl;
    }// hàm dựng không có tham số
    mohaiba ( string minhthuong ){
        name = minhthuong;
        }// hàm dựng có tham số
public:
        void setname( string abc ){
            name = abc;
            }
        string getname(){
            return name;
            }

private: // riêng
        string name;
};


int main ()
{
   // mothaiba bonnam; // chạy hàm dựng lun
    mothaiba bonnam("\nlop lop lop");
    cout << bonnam.getname;
    mothaiba bonnamsau("\ncho minh thuong");
    bonnam.setname("\nMinh thuong");
    cout << bonnam.getname();
    return 0;
}

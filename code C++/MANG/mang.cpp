#include <iostream>
using namespace std;
void input(int *a,int &n)
{
    cout <<"\nn = ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout <<"a[ " << i << " ] = ";
        cin >> *(a+i);
    }
}
void output(int *a,int n)
{
    cout <<"\nday gom: " ;
    for(int i=0;i<n;i++)
    {
        cout << *(a+i) <<" " ;
    }
}
// KHI ĐỔI VÙNG NHỚ CỦA CON TRỎ, CŨNG PHẢI ĐỂ "&" DÔ Y NHƯ THAM CHIẾU
void xaydunghamrealloc(int *&a,int &n,int *temp)
{
    // đổ a qua b
    temp= new int[n];
    for(int i=0;i<n;i++)
    {
        *(temp+i)= *(a+i);
    }
    // bước 2: delete vùng nhớ a cũ
    delete[] a;
    // bước 3: tạo lại a, đổ ngược lại b qua a tăng lên 1
    a=new int [n+1];
    // bước 4: đổ ngược lại
    for(int i=0;i<n;i++)
    {
        *(a+i)= *(temp+i);
    }
    // bước 5: giải phóng temp
    delete[] temp;
}
void them(int *a,int &n, int *temp,int vt,int gt)
// Bước 1: mở rộng vùng nhớ -- thực hiện bằng thủ công
// Nếu dùng a = new[n+1], nó sẽ xóa tất cả các phần tử đã có trong mảng cũ --> sai
{
    cout <<"\nVi tri them: ";
    cin >> vt;
    cout <<"\nGia tri thim: ";
    cin >> gt;
    xaydunghamrealloc(a,n,temp);
    for(int i=n-1;i>=vt;i--)
    {
        a[i+1]=a[i];
    }
    a[vt]=gt;
    n++;
    output(a,n);
}
// xóa: xóa rồi mới bỏ đi ô trống dư
// thêm: xây dựng vùng nhớ mới rộng hơn rồi mới bỏ cái mới dô
void xoa(int *&a,int &n,int *temp,int vitri)
{
    cout <<"\nVi tri xoa: :";
    cin >> vitri;
    for(int i=vitri+1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    // n--;
    // output(a,n);
    // vít tới đây mà không cấp lại vùng nhớ mới thì vẫn cout ra đún, nhưng máy sẽ báo lỗi vùng nhớ, chưa tối ưu.
    temp= new int[n-1];
    for(int i=0;i<n;i++)
    {
        *(temp+i) = *(a+i);
    }
    delete[] a;
    a=new int[n-1];
    for(int i=0;i<n;i++)
    {
        *(a+i)=*(temp+i);
    }
    n--;
    delete[] temp;
    output(a,n);
}
int main()
{
    int *a,*temp;
    int n,vt,gt,vitri;
    a= new int;
    input(a,n);
    output(a,n);
    //them(a,n,temp,vt,gt);
    xoa(a,n,temp,vitri);
    return 0;
}

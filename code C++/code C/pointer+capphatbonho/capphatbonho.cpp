// tất cả các vùng nhớ cấp phát cho con trỏ đều nằm trên vùng nhớ HEAP SEGMENT
// vì vậy, cấp phát bộ nhớ cho con trỏ thì phải giải phóng, nếu không bị tràn bộ nhớ( MEMORY LEAK)

// C: malloc, Calloc, realloc  --> giải phóng: free
// C++: new --> giải phóng: delete

#include <stdio.h> // thư vịn nhập xuất
#include <conio.h> // dừng màn hìn -->   getch();
#include <stdlib.h> // thư vịn hỗ trợ cấp phát cho con trỏ

int main ()
{
    int *a;
    // BIẾN CON TRỎ: địa chỉ + giá trị (miền giá trị)
// khi khởi tạo, nó chỉ có địa chỉ, chưa có miền giá trị.
// Có 2 cách tạo ra giá trị cho con trỏ:
// Cách 1: b=&a;( int *b; int a=6)
// Cách 2: tự mìn cấp phát
// hàm này nó mặc định cho nó xài void, nên ghi a = ....lloc(sizeof(int *)) không được, vì 1 bên int,1 bên void
// công thức: malloc(kích thước) : cấp 1 ô nhớ
    a=(int *) malloc(sizeof(int *));
    *a=9; // nếu không có giá trị được gán, con trỏ mang giá trị rác
    printf("\nGia tri con tro a: %d",*a);
    free(a); // phải giải phóng
    int *b;
// công thức: calloc(mún cấp vùng nhớ gồm bao nhiu ô nhớ,kích thước ô nhớ bao nhiu) : cấp vùng nhớ nhìu ô
    b=(int *)calloc(1,sizeof(int *)); // nó cấp 1 mảng tất cả phần tử đều là 0
    *b=5; // nếu không có giá trị được gán, con trỏ mang giá trị 0
    printf("\nGia tri con tro b: %d",*b);
// công thức: realloc(0,kích thước) = Realloc(NULL, kích thước)  : nếu chưa có vùng nhớ, cấp 1 vùng nhớ. (0: chưa có vùng nhớ)
//            Realloc(a,kích thước) : Nếu có gòi, mở rộng hoạc thu hẹp vùng nhớ đó (a: vùng nhớ đã có)
    a= (int *) realloc(a,sizeof(int *)*5);
    int *c;
    c= (int *) realloc(0,sizeof(int *)*5 );
    *c=7;
    printf("\nGia tri con tro c: %d",*c);
    return 0;
}

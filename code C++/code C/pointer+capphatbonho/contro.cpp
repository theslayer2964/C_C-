// INT, FLOAT: 4 BYTE --> DOUBLE 8 BYTE
// kiểu dữ liêu con trỏ: o phải kiểu dữ lịu của con trỏ, mà là kiủ dữ liêu của bín mà con trỏ trỏ tới.
// int *a -> khai báo bín con trỏ a
#include <stdio.h>
int main ()
{
    int *b;
    int a=6;
    b=&a;
// that mean: con trỏ b chỉ có thể trỏ tới bín có kiu dữ lịu int mà hôi
// b=&a -> cho con trỏ b trỏ đến địa chỉ của bín a. Con trỏ b giữ địa chỉ của bín a
// a change b change, b change a change
    printf("\nLay gia tri con tro b: %d",*b);
    printf("\nDia chi cua bin b: %d",&b);  // 2 địa chỉ khác nhau hoàn toàn nhưng cùng giá trị
    printf("\nDia chi cua bin a: %d",&a);
    printf("\nMien gia tri cua bien b: %d",b); // địa chỉ khác nhưng cùng giá trị
// *b++ -> "+" thực hiện trước, do nó đc ưu tiên trước. con trỏ trỏ tới địa chỉ ô nhớ a tăng lên 1
// (*b)++ -> con trỏ trỏ tới giá trị  rồi tăng giá trị đó lên 1
// con trỏ trỏ vào con trỏ
    int *c;
    c = b; // đây là 2 con trỏ, ngang bằng nhau. c trỏ đến con trỏ b
    printf("\nLay gia tri con tro c: %d",*c);
    printf("\nDia chi cua bin c: %d",&c);
    printf("\nMien gia tri cua bien c: %d",c);
// int f=3;
// int *d=6 -> không đc, vì CPU chỉ cấp cho  con trỏ 1 cái địa chỉ chứ không cấp ccho nó 1 vùng nhớ
// phải ghi típ
// d=&f --> xaì ké miền giá trị của bín f
// thì mới ghi đc
// d=6;
    printf("\nkich thuoc con tro %d",sizeof(b)); // hàm xuất kích thước con trỏ,lunlun 4


// void * : con trỏ vô kiểu, trỏ đến mọi kỉu
    int g=9;
    void *j;
    j=&g;
    //printf("\nGia tri j =%d",*j) -->SAI.trỏ thì trỏ đến mọi kiu được, NHƯNG ĐỂ IN NÓ RA THÌ PHẢI ĐỊNH DẠNG CHO NÓ ĐÚN
    printf("\nGia tri j =%d",*(int *)j);
    free(b); // nói vs hệ điều hành, chương trình không dùng ô nhớ này nữa, chứ hệ đìu hành không hề thu hồi cái vùng nhớ này.
    return 0;
}

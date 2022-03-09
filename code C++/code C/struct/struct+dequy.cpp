#include <stdio.h>

int main ()
{
    struct person
    {
        char hoten[30];
        struct person *father, *mother;
    };
    struct node
    {
        int value;
        struct node *pnext;
    };
    return 0;
}

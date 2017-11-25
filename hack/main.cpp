#include <stdio.h>
#include "ai.h"

int main()
{
    matrix a(2,1);
    a[0][0] = 1;
    a[1][0] = 2;
    matrix b(2,2);
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    matrix_mult(b,a).print();
    return 0;
}

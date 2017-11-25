#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ai.h"

matrix::matrix()
{
    rows = -1; columns = -1; m = NULL;
}
matrix::matrix(int r, int c)
{
    rows = r; columns = c;
    m = new double[r*c];
    memset(m, 0, r*c*sizeof(double));
}
matrix::~matrix()
{
    if (m != NULL)
        delete[] m;
}

double* matrix::operator[](int i)
{
    return m + i * columns;
}

matrix matrix_mult(matrix &a, matrix &b)
{
    matrix m(a.rows, b.columns);
    for (int i = 0; i < a.rows; ++i)
        for (int j = 0; j < b.columns; ++j)
            for (int k = 0; k < a.columns; ++k)
                m[i][j] += a[i][k] * b[k][j];
    return m;
}

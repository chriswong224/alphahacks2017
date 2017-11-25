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

void matrix::print()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
            printf("%5.2f", (*this)[i][j]);
        printf("\n");
    }
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

matrix transpose(matrix &m)
{
    matrix r(m.columns, m.rows);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.columns; ++j)
            r[j][i] = m[j][i];
    return r;
}

nn::nn()
{
    num_inputs = 0;
    hidden_neurons = 0;
    num_outputs = 0;
    in = NULL;
    out = NULL;
    hidden = NULL;
    weights_in = NULL;
    weights_out = NULL;
}
nn::nn(int inputs, int hiddens, int outputs)
{
    num_inputs = inputs;
    hidden_neurons = hiddens;
    num_outputs = outputs;
    in = NULL;
    out = new matrix(outputs, 1);
    hidden = new matrix(hiddens, 1);
    weights_in = new matrix(hiddens, inputs);
    weights_out = new matrix(outputs, hiddens);
}
nn::~nn()
{
    delete out;
    delete hidden;
    delete weights_in;
    delete weights_out;
}

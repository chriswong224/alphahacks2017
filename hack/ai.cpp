#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ai.h"

matrix::matrix()
{
    rows = -1; columns = -1; m = NULL;
    original = true;
}
matrix::matrix(int r, int c)
{
    rows = r; columns = c;
    m = new double[r*c];
    memset(m, 0, r*c*sizeof(double));
    original = true;
}
matrix::matrix(int r, int c, double low, double high)
{
    rows = r; columns = c;
    m = new double[r*c];
    for (int i=0; i < r; ++i)
        for (int j=0; j < c; ++j)
            (*this)[i][j] = rand()*rand_mult*(high-low)+low;
    original = true;
}
matrix::~matrix()
{
    if (m != NULL && original)
        delete[] m;
}

double* matrix::operator[](int i)
{
    return m + i * columns;
}

matrix matrix::operator=(matrix r)
{
    rows=r.rows;
    columns =r.columns;
    m=r.m;
    original = false;
    return *this;
}

void matrix::originalize()
{
    if (!original)
    {
        double *d = new double[rows*columns];
        memcpy(d, m, sizeof(double)*rows*columns);
        m = d;
        original = true;
    }
}

void matrix::randomize(double low, double high)
{
    for (int i=0; i < rows; ++i)
        for (int j=0; j < columns; ++j)
            (*this)[i][j] = rand()*rand_mult*(high-low)+low;
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
    //hidden_neurons = 0;
    num_outputs = 0;
    in = NULL;
    out = NULL;
    //hidden = NULL;
    //weights_in = NULL;
    weights_out = NULL;
}
nn::nn(int inputs, /*int hiddens, */int outputs)
{
    num_inputs = inputs;
    //hidden_neurons = hiddens;
    num_outputs = outputs;
    in = NULL;
    out = new matrix(outputs, 1);
   // hidden = new matrix(hiddens, 1);
    //weights_in = new matrix(hiddens, inputs);
    weights_out = new matrix(outputs, inputs);//hiddens);
}
nn::~nn()
{
    delete out;
    //delete hidden;
    //delete weights_in;
    delete weights_out;
}

void nn::randomize()
{
    //weights_in->randomize(-1.0,1.0);
    weights_out->randomize(-1.0,1.0);
}
void nn::load(const char* path)
{
    FILE * f;
    fopen(path,"r");
    /*for (int i = 0; i < hidden_neurons; ++i)
        for (int j = 0; j < num_inputs; ++j)
            fscanf(f, "%f", (*weights_in)[i]+j);*/
    for (int i = 0; i < num_outputs; ++i)
        for (int j = 0; j < num_inputs/*hidden_neurons*/; ++j)
            fscanf(f, "%lf", (*weights_out)[i]+j);
    fclose(f);
}

void nn::save(const char* path)
{
    FILE * f;
    fopen(path,"w");
    /*for (int i = 0; i < hidden_neurons; ++i)
        for (int j = 0; j < num_inputs; ++j)
            fprintf(f, "%f ", (*weights_in)[i]+j);*/
    for (int i = 0; i < num_outputs; ++i)
        for (int j = 0; j < num_inputs/*hidden_neurons*/; ++j)
            fprintf(f, "%f ", (*weights_out)[i][j]);
    fclose(f);
}

void nn::run(matrix* input)
{
    *in = *input;
    in->originalize();
    //*hidden = matrix_mult(*weights_in, *in);
    *out = matrix_mult(*weights_out, *in);//*hidden);
}

#define HASTE 0.01
void nn::backprop(matrix* desired)
{
    for (int i = 0; i < num_outputs; ++i)
    {
        double intended_change = HASTE*((*desired)[0][i]-(*out)[0][i]);
        for (int j = 0; j < num_inputs/*hidden_neurons*/; ++j)
        {
            (*weights_out)[j][i] -= intended_change*(*in)/*hidden*/[0][j];
        }
    }
    //i don't know how to do the second layer in this simplification :(
}

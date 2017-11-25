#ifndef AI_H
#define AI_H

class matrix
{
public:
    int rows, columns;
    double * m;

    matrix();
    matrix(int r, int c);
    ~matrix();

    double* operator[](int i);
    matrix operator=(matrix &r);

    void print();
};

matrix matrix_mult(matrix &a, matrix &b);
matrix transpose(matrix &m);

class nn
{
public:
    int num_inputs;
    int hidden_neurons;
    int num_outputs;
    matrix* in;
    matrix* out;
    matrix* hidden;
    matrix* weights_in;
    matrix* weights_out;

    nn();
    nn(int inputs, int hiddens, int outputs);
    ~nn();
};

#endif


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

    void print();
};

matrix matrix_mult(matrix &a, matrix &b);

#endif


#ifndef AI_H
#define AI_H

#include <string>

extern const double rand_mult;

class matrix
{
public:
    int rows, columns;
    double m[1024];
    bool original;

    matrix();
    matrix(int r, int c);
    matrix(int r, int c, double, double);
    ~matrix();

    double* operator[](int i);
    matrix operator=(matrix r);

    void randomize(double, double);
    void originalize();

    void print();
};

matrix matrix_mult(matrix &a, matrix &b);
matrix transpose(matrix &m);

class nn
{
public:
    int num_inputs;
    //int hidden_neurons;
    int num_outputs;
    matrix* in;
    matrix* out;
    //matrix* hidden;
    //matrix* weights_in;
    matrix* weights_out;

    nn();
    nn(int inputs, /*int hiddens, */int outputs);
    ~nn();

    void randomize();
    void load(const char*);
    void save(const char*);

    void run(matrix* input);
    void backprop(matrix* desired);
};

struct KeyWords{
    int weight;
    std::string word;
};

int weight(std::string s, KeyWords a[],int numWords);

int article(int articleNum);

#endif


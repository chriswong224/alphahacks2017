#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ai.h"

const double rand_mult = 1.0/RAND_MAX;

int main()
{
    nn net(2,7);
    net.randomize();

    matrix ins[4];
    for (int i = 0; i < 4; ++i)
    {
        ins[i] = matrix(2,1);
        ins[i][0][0] = article(i+1);
    }
    matrix des_out[4];
    for (int i = 0; i < 4; ++i)
    {
        des_out[i] = matrix(7,1);
        FILE * f;
        std::string name = "stock";
        char asdf[100] = "";
        sprintf(asdf,"%d",i+1);
        name += asdf;
        name += ".txt";
        f=fopen(name.c_str(),"r");
        fscanf(f, "%lf", ins[i][1]);
        for (int j = 0; j < 7; ++j)
        {
            fscanf(f, "%lf", des_out[i][j]);
        }
        printf("qwer");
        fclose(f);
    }
    net.weights_out->print();
    for (int i = 0; i < 1000000; ++i)
        for (int j = 0; j < 4; ++j)
        {
            net.run(ins+i);
            net.backprop(des_out+i);
        }

    //train network

    return 0;
}

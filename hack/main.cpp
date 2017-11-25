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
        ins[i] = matrix(1,2);
        ins[i][0][0] = article(i+1);
    }
    matrix des_out[4];
    for (int i = 0; i < 4; ++i)
    {
        des_out[i] = matrix(1,7);
        FILE * f;
        std::string name = "stock";
        char asdf[100] = "";
        sprintf(asdf,"%d",i+1);
        name += asdf;
        name += ".txt";
        f=fopen(name.c_str(),"r");

        fscanf(f, "%lf", ins[i][0]+1);
        for (int j = 0; j < 7; ++j)
        {
            fscanf(f, "%lf", des_out[i][0]+j);
        }

        fclose(f);
    }
    //infrastucture and read data


    //train network

    return 0;
}

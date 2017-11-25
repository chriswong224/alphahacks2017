#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ai.h"

const double rand_mult = 1.0/RAND_MAX;

int main()
{
    nn net(2,7);
    net.load("net.txt");

    matrix ins;

    int n;
    scanf("%d", &n);
    ins[0][0] = article(n);
    double d;
    scanf("%lf", ins[1]);

    printf("%f\n\n", ins[0][0]);

//    net.run(&ins);
    net.out[0][0][0] = -ins[0][0]*0.9723;
    for (int i = 1; i < 7; ++i)
        net.out[0][i][0] = net.out[0][i-1][0]*0.98432;
    net.out->print();

    return 0;
}
    /*[4];
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
            des_out[i][j][0] /= ins[i][1][0];
        }
        printf("qwer");
        fclose(f);
    }
    net.weights_out->print();
    for (int i = 0; i < 4; ++i)
 {

   des_out[i].print();
    ins[i].print();
}
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            net.run(ins+j);
            net.backprop(des_out+j);
        }
        if (i%1000==0)
        printf("done it %d\n", i);
        net.save("net.txt");
    }

    //train network

    return 0;
}
*/

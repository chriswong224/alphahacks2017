#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ai.h"

const double rand_mult = 1.0/RAND_MAX;

int main()
{
    nn net(2,7);
    net.randomize();

    printf("%d", article(1));
    //infrastucture and read data


    //train network

    return 0;
}

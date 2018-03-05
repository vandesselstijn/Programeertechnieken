//
// Created by stijn on 3/5/18.
//

#include <stdio.h>
#include <math.h>
#define EXT extern
#include "gvar.h"

static int p = 0;

int routine()
{
    static int q =1;
    int i;
    i = g + p++ + q++;
    printf("\t p%d q%d\n", p,q);
    return i;
}

double reken(double c)
{
    double f;
    f = (++p) + sqrt(c);
    printf("\t p%d", p);
    printf(" c%lf f%lf\n",c,f);
}


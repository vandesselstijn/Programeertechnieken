//
// Created by stijn on 3/5/18.
//

#include <stdio.h>
#define EXT

#include "gvar.h"

int main(int argc, char *argv[])
{
    float a =4.0;

    a = functie(a);
    printf("main: g%d a%f\n", g,a);
    a = functie(a);
    printf("main: g%d a%f\n", g,a);
}

float functie(float b)
{
    double z;
    g = routine();
    z = reken((double)b);
    return  (float)g +b+z;
}



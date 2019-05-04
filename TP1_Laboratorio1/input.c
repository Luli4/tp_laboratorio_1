#include <stdio.h>
#include "input.h"

float getFloat (char mensaje [50])
{
    float num;

    printf("%s", mensaje);
    scanf("%f", &num);

    return num;
}


int esInt (float num)
{
    int entero=num;
    int esEntero=0;

    if (num-entero==0)
     {
         esEntero=1;
     }
     return esEntero;
}

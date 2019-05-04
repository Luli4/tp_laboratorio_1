#include "functionsMath.h"

float sumarFloat (float num1, float num2)
{
    return num1 + num2;;
}


float restarFloat (float num1, float num2)
{
    return num1 - num2;;
}


float dividirFloat (float num1, float num2)
{
    return (float) num1 / num2;
}


float multiplicarFloat (float num1, float num2)
{
    return num1 * num2;
}


int sacarFactorial (float num1)
{
    int factorial;

    if (num1==0 || num1==1)
    {
        factorial = 1;
    }
    else
    {
        factorial = num1 * (sacarFactorial (num1-1));
    }
    return factorial;
}

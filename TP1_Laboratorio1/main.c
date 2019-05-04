#include <stdlib.h>
#include <stdio.h>
#include "functionsMath.h"
#include "input.h"

int main()
{
    int opcion;
    char seguir = 's';

    float numA;
    float numB;

    float suma;
    float resta;
    float division;
    float multiplicacion;
    int factorialA;
    int factorialB;

    int flagA=0;
    int flagB=0;

    do
    {
        printf("Ingrese el numero de la opcion correspondiente:\n");
        if (flagA==1)
        {
        printf("1. Ingresar 1er operando (A=%.2f)\n", numA);
        }
        else
        {
        printf("1. Ingresar 1er operando (A=x)\n");
        }


        if (flagB==1)
        {
        printf("2. Ingresar 2do operando (B=%.2f)\n", numB);
        }
        else
        {
        printf("2. Ingresar 2do operando (B=y)\n");
        }


        printf("3. Calcular operaciones: suma, resta, division, multiplicacion, factorial\n");
        printf("4. Informar resultados\n");
        printf("5. Salir del programa\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
            numA= getFloat("Ingrese el numero A: ");
            flagA=1;
            break;

            case 2:
            numB= getFloat("Ingrese el numero B: ");
            flagB=1;
            break;

            case 3:
            printf("Procesando resultados\n");

            if (flagA==1 && flagB==1)
            {
            suma = sumarFloat(numA, numB);
            resta = restarFloat(numA, numB);

            if (numB!=0)
            {
                 division = dividirFloat(numA, numB);
            }

            multiplicacion = multiplicarFloat(numA, numB);

            if (numA>=0 && esInt(numA))
            {
                 factorialA = sacarFactorial(numA);
            }

            if (numB>=0 && esInt (numB))
            {
                factorialB= sacarFactorial(numB);
            }

            printf("Resultados listos!\n");
             }
             else
             {
                printf("Falta uno o mas operandos, intentelo nuevamente.\n");
             }
            break;

            case 4:
                if (flagA==1 && flagB==1)
            {
            printf("Los resultados son:\n");
            printf("Suma: %.2f\n", suma);
            printf("Resta (%.2f-%.2f): %.2f\n",numA, numB, resta);


            if (numB!=0)
            {
                printf("Division (%.2f/%.2f): %.2f\n",numA, numB, division);
            }


            printf("Multiplicacion: %.2f\n", multiplicacion);


            if (numA>=0 && esInt(numA))
            {
                printf("El factorial de %.2f es: %d\n", numA, factorialA);
            }
            else
            {
                printf("No puede factorizarse el numero %.2f, verifique que sea un entero positivo.\n", numA);
            }


            if (numB>=0 && esInt(numB))
            {
                printf("El factorial de %.2f es: %d\n", numB, factorialB);
            }
             else
            {
                printf("No puede factorizarse el numero %.2f, verifique que sea un entero positivo.\n", numB);
            }

            }
            else
            {
                printf("No es posible mostrar los resultados: falta uno o mas operandos.\n");
            }
            break;

            case 5:
            printf("El programa se cerrara\n");
            seguir='n';
            break;

            default:
                printf("No ingreso una opcion valida\n");
                break;
        }

        system("pause");
        system("cls");

    }while (seguir=='s');

    return 0;
}

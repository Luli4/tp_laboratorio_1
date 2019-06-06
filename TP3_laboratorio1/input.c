#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "input.h"
#include "validations.h"

int getInt(char* message)
{
    int number; //guarda un int
    printf("Ingrese %s: ", message);
    scanf("%d", &number);
    return number;
}

void getFloat(char* message, float* number)
{
    printf("Ingrese %s: ", message);
    scanf("%f", number);
    return;
}

void getChar(char* message, char* letter)
{
    printf("Ingrese %s: ", message);
    fflush(stdin);
    scanf("%c", letter);
}

void getString(char* message, char* myString)
{
    char buffer[200]; //guarda un string
    printf("\nIngrese %s: ", message);
    fflush(stdin);
    scanf("%[^\n]", buffer);
    strcpy(myString, buffer);

}

void getRandomNumber(int from, int to, int initialize, int* randomNumber)
{
    if (initialize)
    {
        srand (time(NULL));
    }

    *randomNumber = from + (rand() % (to + 1 - from));

    return;
}

int getStringJustLetters(char* message, char* input)
{
    char auxString[200]; //guarda un string
    int state = -1; //bandera que permite saber si el string contiene solo letras
    getString(message, auxString);
    if (itsStringJustLetters(auxString)==1)
    {
        strcpy(input, auxString);
        state=1;
    }
return state;
}


void getSex(char* input)
{
    printf("Ingrese sexo (F/M) : ");
    fflush(stdin);
    scanf("%c", input);
    *input=toupper(*input);
}

int getStringNumbers(char* message, char* input)
{
    char auxInt[200]; //guardara un string de numeros
    int state = -1; //bandera que permite saber si el string es solo de numeros
    getString(message, auxInt);
    if (itsNumber(auxInt))
    {
        strcpy(input,auxInt);
        state=1;
    }
return state;
}


void getValidInt(int* finalInt, char* message, int lowLimit, int hiLimit)
{
    char auxStr[200]; //guardara un string de numeros

    getStringNumbers(message, auxStr);
    *finalInt = atoi(auxStr);

    while (*finalInt < lowLimit || *finalInt > hiLimit)
    {
        printf("Recuerde que solo puede ingresar un numero entre %d y %d\n\n", lowLimit, hiLimit);
        getStringNumbers(message, auxStr);
        *finalInt = atoi(auxStr);
    }

return;
}

int getStringFloatNumber(char* message, char* input)
{
    char auxString[200]; //guardara un string de flotantes
    int state = -1; //bandera que permite saber si el string es un numero flotante
    getString(message, auxString);
    if (itsFloatNumber(auxString)==1)
    {
        strcpy(input, auxString);
        state=1;
    }
return state;
}

void getValidFloat(float* finalFloat, char* message, float lowLimit, float hiLimit)
{
    char auxStr[200]; //guardara un string de floats

    getStringFloatNumber(message, auxStr);
    *finalFloat = atof(auxStr);

    while (*finalFloat <= lowLimit || *finalFloat > hiLimit)
    {
        printf("Recuerde que solo puede ingresar un numero entre %.2f y %.2f\n\n", lowLimit, hiLimit);
        getStringFloatNumber(message, auxStr);
        *finalFloat = atof(auxStr);
    }
    return;

}

void getValidString (char* message, char* input, int ssize)
{
   while (getStringJustLetters(message, input)==-1 || (strlen(input)>ssize) || input[0]==' ')
    {
        printf("Por favor, ingrese solo %s. \n\n", message);
    }
}

void getValidSex(char* letter)
{
    getSex(letter);

    while (*letter!='F' && *letter!='M')
    {
        printf("Error, el sexo ingresado es incorrecto. \n\n");
        getSex(letter);
    }
}



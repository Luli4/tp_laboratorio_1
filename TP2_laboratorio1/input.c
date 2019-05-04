#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "input.h"
#include "validations.h"

int getInt(char message[])
{
    int number; //guarda un int
    printf("Ingrese %s: ", message);
    scanf("%d", &number);
    return number;
}

float getFloat(char message[])
{
    float number; //guarda un flotante
    printf("Ingrese %s: ", message);
    scanf("%f", &number);
    return number;
}

char getChar(char message[])
{
    char letter; //guarda un char
    printf("Ingrese %s: ", message);
    fflush(stdin);
    scanf("%c", &letter);
    return letter;
}

void getString(char message[], char myString[])
{
    char buffer[200]; //guarda un string
    printf("Ingrese %s: ", message);
    fflush(stdin);
    scanf("%[^\n]", buffer);
    strcpy(myString, buffer);

}

int getRandomNumber(int from, int to, int initialize)
{
    int randomNumber; //guarda un numero aleatorio

    if (initialize)
    {
        srand (time(NULL));
    }

    randomNumber = from + (rand() % (to + 1 - from));

return randomNumber;
}

int getStringJustLetters(char message[], char input[])
{
    char auxString[200]; //guarda un string
    int flag; //bandera que permite saber si el string contiene solo letras
    flag=-1;
    getString(message, auxString);
    if (itsStringJustLetters(auxString)==1)
    {
        strcpy(input, auxString);
        flag=1;
    }
return flag;
}





void getSex(char input)
{
    char letter; //guardara el sexo
    printf("Ingrese sexo (F/M) : ");
    fflush(stdin);
    scanf("%c", &letter);
    letter=toupper(letter);
    input= letter;
}

int getStringNumbers(char message[], char input[])
{
    char auxInt[200]; //guardara un string de numeros
    int flag; //bandera que permite saber si el string es solo de numeros
    flag=-1;
    getString(message, auxInt);
    if (itsNumber(auxInt))
    {
        strcpy(input,auxInt);
        flag=1;
    }
return flag;
}


int getValidInt(char message[], int lowLimit, int hiLimit)
{
    char auxStr[200]; //guardara un string de numeros
    int auxInt; //permite pasar el string de numeros a int para poder compararlo con maximos y minimos
    int finalInt; //int en caso de validarse

    getStringNumbers(message, auxStr);
    auxInt = atoi(auxStr);

    while (auxInt < lowLimit || auxInt > hiLimit)
    {
        printf("Recuerde que solo puede ingresar un numero entre %d y %d\n\n", lowLimit, hiLimit);
        getStringNumbers(message, auxStr);
        auxInt = atoi(auxStr);
    }
    finalInt = auxInt;

return finalInt;
}

int getStringFloatNumber(char message[], char input[])
{
    char auxString[200]; //guardara un string de flotantes
    int flag; //bandera que permite saber si el string es un numero flotante
    flag=-1;
    getString(message, auxString);
    if (itsFloatNumber(auxString)==1)
    {
        strcpy(input, auxString);
        flag=1;
    }
return flag;
}

float getValidFloat(char message[], float lowLimit, float hiLimit)
{
    char auxStr[200]; //guardara un string de floats
    float auxFloat; //permite pasar el string de floats a float para poder compararlo con maximos y minimos
    float finalFloat;

    getStringFloatNumber(message, auxStr);
    auxFloat = atof(auxStr);

    while (auxFloat <= lowLimit || auxFloat > hiLimit)
    {
        printf("Recuerde que solo puede ingresar un numero entre %.2f y %.2f\n\n", lowLimit, hiLimit);
        getStringFloatNumber(message, auxStr);
        auxFloat = atof(auxStr);
    }
    finalFloat = auxFloat;

return finalFloat;

}

void getValidString (char message[], char input[], int ssize)
{
   while (getStringJustLetters(message, input)==-1 || (strlen(input)>ssize) || input[0]==' ')
    {
        printf("Por favor, ingrese solo %s. \n\n", message);
    }
}

void getValidSex(char letter)
{
    char auxSex='z'; //guardara el sexo

    getSex(auxSex);

    while (auxSex!='F' && auxSex!='M')
    {
        printf("Error, el sexo ingresado es incorrecto. \n\n");
        getSex(auxSex);
    }
    letter=auxSex;
}



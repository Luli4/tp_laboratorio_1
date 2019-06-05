#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int itsFloatNumber(char str[])
{
    int i; //indice que permite revisar el string de floats
    int state=1; //bandera que permite saber si tiene solo numeros y puntos
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]<'0'||str[i]>'9') && str[i]!='.')
        {
            state=-1;
        }
    i++;
    }
return state;
}

int itsNumber(char str[])
{
    int i; //indice para revisar el string
    int state=1; //bandera que permite saber si solo posee numeros
    i=0;
    while (str[i]!='\0')
    {
        if (str[i]<'0'||str[i]>'9')
        {
            state=-1;
        }
    i++;
    }
return state;
}

int itsStringJustLetters(char str[])
{
    int i; //indice para revisar el string
    int state=1; //bandera que permite saber si solo posee letras y espacios
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]<'a' || str[i]>'z') && (str[i]<'A'||str[i]>'Z') && str[i]!=' ')
        {
            state=-1;
        }
    i++;
    }
return state;
}

int itsPhoneNumber(char str[])
{
    int i; //indice para revisar el string
    int hyphenCounter; //contador de guiones
    int state=0; // bandera que permite saber si solo posee numeros y guiones
    hyphenCounter=0;
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]!=' ') && str[i]!='-' && (str[i]<'0' || str[i]>'9'))
        {
            state=-1;
        }
        if (str[i]=='-')
        {
            hyphenCounter++;
        }
    }
if (state==0 && hyphenCounter!=0)
{
    state=1;
}
return state;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"
#include "input.h"

int itsFloatNumber(char str[])
{
    int i; //indice que permite revisar el string de floats
    int flag=1; //bandera que permite saber si tiene solo numeros y puntos
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]<'0'||str[i]>'9') && str[i]!='.')
        {
            flag=-1;
        }
    i++;
    }
return flag;
}

int itsNumber(char str[])
{
    int i; //indice para revisar el string
    int flag=1; //bandera que permite saber si solo posee numeros
    i=0;
    while (str[i]!='\0')
    {
        if (str[i]<'0'||str[i]>'9')
        {
            flag=-1;
        }
    i++;
    }
return flag;
}

int itsStringJustLetters(char str[])
{
    int i; //indice para revisar el string
    int flag=1; //bandera que permite saber si solo posee letras y espacios
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]<'a' || str[i]>'z') && (str[i]<'A'||str[i]>'Z') && str[i]!=' ')
        {
            flag=-1;
        }
    i++;
    }
return flag;
}

int itsPhoneNumber(char str[])
{
    int i; //indice para revisar el string
    int hyphenCounter; //contador de guiones
    int flag=0; // bandera que permite saber si solo posee numeros y guiones
    hyphenCounter=0;
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]!=' ') && str[i]!='-' && (str[i]<'0' || str[i]>'9'))
        {
            flag=-1;
        }
        if (str[i]=='-')
        {
            hyphenCounter++;
        }
    }
if (flag==0 && hyphenCounter!=0)
{
    flag=1;
}
return flag;
}


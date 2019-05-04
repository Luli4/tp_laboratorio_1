#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strings.h"

void firstToUpper(char name[])
{
strlwr(name);

name[0] = toupper(name[0]);
int j=0;

while(name[j]!='\0')
{

    if(name[j]==' ')
    {
        name[j+1]= toupper (name[j+1]);

    }
    j++;
}
}
void stringToUpper (char letters[])
{
    int i; //variable de control que permite revisar el string

    for (i=0; letters[i] != '\0'; i++)
    {
    letters[i] = toupper(letters[i]);
    }
}

void stringToLower (char letters[])
{
    int i; // variable de control que permite revisar el string

    for (i=0; letters[i] != '\0'; i++)
    {
    letters[i] = tolower(letters[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "windows.h"

void employees_optionsMenu(int* option, char* message, int lowMenu, int hiMenu)
{
    system("cls");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Elija la opcion correspondiente:\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("%s", message);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    getValidInt(option, "su opcion", lowMenu, hiMenu);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}

void welcome (char* message, int mSize)
{
    int i;

    for (i=0; i<mSize; i++)
    {
        Sleep(100);
        printf("%c", *(message+i));
    }
    printf("\n\n");
}

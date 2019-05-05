#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "strings.h"
#include "input.h"
#include "validations.h"

int employees_optionsMenu(char message[], int lowMenu, int hiMenu)
{
    int option; //opcion que se vera reflejada en el menu
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Elija la opcion correspondiente:\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("%s", message);
    option = getValidInt("su opcion", lowMenu, hiMenu);
    return option;
}

void employees_initEmployees (eEmployee listE[], int SEMP)
{
    int i; // variable de control para sectores
    for(i=0; i<SEMP; i++)
    {
        listE[i].isEmpty = EMPTY;
    }
}

void employees_showOne (eEmployee oneEmployee, eSector sectors[], int SSEC)
{
    char sectorDescription[20]; //tiene el string que describe al sector
    int i;// variable de control para empleados

    for(i=0; i<SSEC; i++)
    {
        if(oneEmployee.sector==sectors[i].id)
        {
            strcpy(sectorDescription, sectors[i].description);
            break;
        }
    }
    printf("%3d %18s %18s %18s %17.2f\n", oneEmployee.id, sectorDescription, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary);
}

int employees_addEmployees (eEmployee listE[], int SEMP, eSector sectors[], int SSEC, int id)
{
    int i; // indice con el lugar vacio en caso de que exista
    i = employees_emptyPlace(listE, SEMP);
    eEmployee auxEmployee;
    eSector auxSector;
    int saved=-1;
    if(i!=-1)
    {
        system("cls");
        auxEmployee.id = id+1;

        employees_inputName(auxEmployee.name, 50, "su nombre");
        system("cls");

        employees_inputName(auxEmployee.lastName, 50, "su apellido");
        system("cls");

        auxSector= sectors_getSector(sectors, SSEC, listE);
        system("cls");

        auxEmployee.sector = auxSector.id;

        auxEmployee.salary=getValidFloat("su salario", 0, 50000);
        system("cls");

        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("%3s %18s %18s %18s %17s\n", "ID", "Sector", "Nombre", "Apellido", "Salario");
        employees_showOne(auxEmployee, sectors, SSEC);
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

        if (employees_verifyConformity("El empleado", "El empleado no sera dado de alta.")==1)
        {
            saved=1;
            strcpy(listE[i].name, auxEmployee.name);
            strcpy(listE[i].lastName, auxEmployee.lastName);
            listE[i].sector = auxSector.id;
            listE[i].salary += auxEmployee.salary;
            listE[i].isEmpty = BUSY;
            listE[i].id = auxEmployee.id;
        }
        else
        {
            listE[i].isEmpty = EMPTY;
        }

    }
    else
    {
        printf("\nNo hay lugar!\n");
    }
return saved;
}

int employees_emptyPlace (eEmployee listE[], int SEMP)
{
    int i; // variable de control para los empleados
    int index=-1; //lugar que ocupara el lugar vacio en caso de ser encontrado
    for(i=0; i<SEMP; i++)
    {
        if(listE[i].isEmpty==EMPTY)
        {
            index = i;
            break;
        }
    }
    return index;
}

eSector sectors_getSector(eSector sectors[], int SSEC, eEmployee listE[])
{
    int j; // variable de control para los empleados y luego para los sectores
    int sector; // guarda el id del sector
    eSector sectorReturn; // guarda una estructura sector elegida por el usuario
    sectorReturn.id = -1;

    do
    {
        for (j=0; j<SSEC; j++)
        {
            printf("ID %d: %s\n", sectors[j].id, sectors[j].description);
        }

        sector=getValidInt("el sector correspondiente segun ID", 1, SSEC);

        for (j=0; j<SSEC; j++)
        {
            if (sectors[j].id==sector)
            {
                sectorReturn = sectors[j];
            }
        }

        if (sectorReturn.id==-1)
        {
            printf("\nEl sector ingresado no existe!\n\n");
        }
    }

    while(sectorReturn.id==-1);
    return sectorReturn;
}

void employees_inputName(char auxName[], int ssize, char message[])
{
    char myString[ssize];

        getValidString(message, myString, ssize);
        firstToUpper (myString);
        strcpy (auxName, myString);
}

int employees_verifyConformity (char message[], char cancelMessage[])
{
    int save=-1; //bandera que avisa si el usuario desea guardar los datos ingresados
    char answer[2]; //respuesta del usuario

    printf("\n%s ingresado es correcto? (Si/No) \n", message);
    fflush(stdin);
    scanf("%s", answer);
    stringToUpper(answer);

    if (strcmp(answer, "SI")==0)
    {
        printf("\nEl dato fue cargado con exito.\n");
        save=1;
    }
    else
    {
        printf("\n%s.\n\n", cancelMessage);
    }
return save;
}

void employees_hcData(eEmployee listE[], int SEMP)
{
    int i; //variable de control para los empleados
    int id[]= {1,8,9,7,2,4};
    char name[][50]= {"Lorena","Eduardo","Carlos","Pedro","Carlos","Mateo"};
    char lastName[][50]={"B","A","B","A","B","A"};
    float salary[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,1,3,3,2,2};

    for(i=0; i<SEMP; i++)
    {
        listE[i].id = id[i];
        strcpy(listE[i].name, name[i]);
        strcpy(listE[i].lastName, lastName[i]);
        listE[i].salary = salary[i];
        listE[i].isEmpty = BUSY;
        listE[i].sector = sector[i];
    }
}

void employees_showList (eEmployee listE[], int SEMP, eSector sectors[], int SSEC)
{
    int i; // variable de control para sectores
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("%3s %18s %18s %18s %17s\n", "ID", "Sector", "Nombre", "Apellido", "Salario");
    for(i=0; i<SEMP; i++)
    {
        if(listE[i].isEmpty==BUSY)
        {
            employees_showOne(listE[i], sectors, SSEC);
        }
    }
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}

void employees_removeEmployee (eEmployee listE[], int SEMP, eSector sectors[], int SSEC, int lowLimit, int hiLimit)
{
    int i; //guardara el indice del id ingresado por el usuario
    i = employees_findEmployeeById (listE, SEMP, sectors, SSEC, lowLimit, hiLimit);
    if (i!=-1 && listE[i].isEmpty==BUSY)
    {
        listE[i].isEmpty = EMPTY;
        printf("\nEl empleado %s %s fue dado de baja.\n\n", listE[i].name, listE[i].lastName);
    }
    else
    {
        printf("\nEl numero de ID no pertenece a un empleado activo.\n\n");
    }

}

void employees_subMenuReports (eEmployee listE[], int SEMP, eSector sectors[], int SSEC, int id)
{
    int option; //guardara la opcion ingresada en el menu que desencadenara un switch
    do{
    system("pause");
    system("cls");
    printf("Usted esta en el menu Informes\n\n");
    option = employees_optionsMenu("1.Mostrar empleados\n2.Salarios: total, promedio y empleados que lo superan\n3.Volver al menu anterior\n\n\n", 1, 7);
    switch (option)
    {
        case 1:
            employees_sortEmployeesByLastName(listE, id, sectors, SSEC);
            employees_printEmployees(listE, SEMP, sectors, SSEC);
            break;
        case 2:
            employees_averageSalary(listE, id);
            break;
        case 3:
            printf("\nVolviendo al menu anterior...\n\n");
            break;
        default:
            printf("\nNo ingreso una opcion valida!\n\n");
            break;
    }
    }while (option!=3);
}

float employees_salaryAcum (eEmployee listE[], int SEMP)
{
    int i; // variable de control del for
    float salaryAcum=0; //guardara el salario total de todos los empleados
    for (i=0;i<SEMP; i++)
    {
        if (listE[i].isEmpty==BUSY)
        {
            salaryAcum+= listE[i].salary;
        }
    }
    printf("\n\nLa suma total de los salarios es: %.2f\n", salaryAcum);
    return salaryAcum;
}

void employees_averageSalary (eEmployee listE[], int SEMP)
{
    int i; // variable de control del for
    float totalSalary; //guardara el salario total de todos los empleados que retornara la funcion emplouee_salaryAcum
    float averageSalary; //guardara el salario promedio
    totalSalary = employees_salaryAcum(listE, SEMP);
    averageSalary = totalSalary / SEMP;
    printf("\n El salario promedio es: %.2f\n\n", averageSalary);
    printf("Los empleados que lo superan son: \n\n");
    for (i=0;i<SEMP;i++)
    {
        if (listE[i].salary > averageSalary && listE[i].isEmpty == BUSY)
        {
            printf("%s %s\n\n",listE[i].name, listE[i].lastName);
        }
    }
}

void employees_subMenuModify (eEmployee listE[], int SEMP, eSector sectors[], int SSEC, int lowLimit, int hiLimit)
{
    int option; // guardara la opcion del menu ingresada por el usuario que desencadenara un switch
    int i; // guardara el indice del ID a modificar previamente ingresado por el usuario
    eEmployee auxEmployee;
    eSector auxSector;
    i = employees_findEmployeeById(listE, SEMP, sectors, SSEC, lowLimit, hiLimit);
    if (i!=-1)
    {
        do{
    system("pause");
    system("cls");
    printf("Usted esta en el menu Modificar Empleado\n\n");
    employees_showList(listE, SEMP, sectors, SSEC);
    option = employees_optionsMenu("1.Modificar nombre\n2.Modificar apellido\n3.Modificar salario\n4.Modificar sector\n5.Volver al menu anterior.\n\n\n", 1, 7);
    switch (option)
    {
       case 1:
            system("cls");
            employees_inputName(auxEmployee.name, 50, "su nombre");
            if (employees_verifyConformity("El nombre", "El nombre no sera modificado.")==1)
            {
               strcpy(listE[i].name, auxEmployee.name);
            }
            break;
        case 2:
            system("cls");
            employees_inputName(auxEmployee.lastName, 50, "su apellido");
            if (employees_verifyConformity("El apellido", "El apellido no sera modificado.")==1)
            {
               strcpy(listE[i].lastName, auxEmployee.lastName);
            }
            break;
        case 3:
            system("cls");
            auxEmployee.salary=getValidFloat("su salario", 0, 50000);
            if (employees_verifyConformity("El salario", "El salario no sera modificado.")==1)
            {
               listE[i].salary=auxEmployee.salary;
            }
            break;
        case 4:
            system("cls");
            auxSector=sectors_getSector(sectors, SSEC, listE);
            auxEmployee.sector = auxSector.id;
            if (employees_verifyConformity("El sector", "El sector no sera modificado.")==1)
            {
               listE[i].sector = auxSector.id;
            }
            break;
        case 5:
            printf("\nVolviendo al menu anterior...\n\n");
            break;
        default:
            printf("\nNo ingreso una opcion valida!\n\n");
            break;
    }
    }while (option!=5);
    }
}

int employees_findEmployeeById (eEmployee listE[], int SEMP, eSector sectors[], int SSEC, int lowLimit, int hiLimit)
{
    int idPos=-1; //posicion del id que se buscara
    int flag=0; //bandera que permite saber si existe o no la posicion del id
    int id; //guarda el id que ingresa el usuario
    int i; // variable de control para los empleados

    employees_showList(listE, SEMP, sectors, SSEC);
    id = getValidInt("el numero de id: ", lowLimit, hiLimit);

    for (i=0; i<SEMP;i++)
    {
        if (listE[i].id==id && listE[i].isEmpty==BUSY)
         {
          idPos=i;
          flag=1;
          break;
          }
     }

      if (flag==0)
      {
        printf("\nEl id ingresado no existe!\n");
      }
      else
      {
        printf("\nCorrecto!\n\n");
      }

return idPos;
}

void employees_sortEmployeesByLastName(eEmployee listE[], int SEMP, eSector sectors[], int SSEC)
{
    int i;
    int j;
    eEmployee aux;

    for (i=0; i<SEMP-1; i++)
    {
        for (j=i+1; j<SEMP; j++)
        {
            if (strcmp(listE[i].lastName, listE[j].lastName)==1)
            {
                aux = listE[i];
                listE[i] = listE[j];
                listE[j] = aux;
            }
        }
    }
}

void employees_printEmployees(eEmployee listE[], int SEMP, eSector sectors[], int SSEC)
{
    int j; //variable de control del for para el sector
    int i; //variable de control del for para los empleados

    for (j=0; j<SSEC; j++)
    {printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("-%s:\n", sectors[j].description);
    printf("%3s %18s %18s %18s %17s\n", "ID", "Sector", "Nombre", "Apellido", "Salario");
        for (i=0; i<SEMP; i++)
        {
            if (listE[i].isEmpty==BUSY)
            {
                 if (listE[i].sector==sectors[j].id)
                {
                    employees_showOne(listE[i], sectors, SSEC);
                }
            }

        }
    }printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"
#include "strings.h"
#include "validations.h"
#define SIZE_EMPLOYEES 1000
#define SIZE_SECTORS 3
int main()
{
    int option; //opcion que derivara en un submenu
    eEmployee listE[SIZE_EMPLOYEES]; //lista de empleados
    eSector listS[SIZE_SECTORS]= {{1,"Contabilidad"},{2,"Sistemas"},{3, "RRHH"}}; //array de estructuras con relacion 1 a muchos con los sectores cargados
    employees_initEmployees(listE, SIZE_EMPLOYEES);
    int id=0;
    do
    {
        option = employees_optionsMenu("\t1.Dar de alta\n\t2.Modificar\n\t3.Dar de baja\n\t4.Informes\n\t5.Salir\n\n\n", 1, 5);
        switch(option)
        {
            case 1:
                if (employees_addEmployees(listE, SIZE_EMPLOYEES, listS, SIZE_SECTORS, id)==1)
                {
                        id++;
                }
                break;
            case 2:
                if (id>0)
                {
                    printf("\nEntrando al menu de modificacion...\n\n");
                    employees_subMenuModify (listE, SIZE_EMPLOYEES, listS, SIZE_SECTORS, 1, id);
                }
                else
                {
                     printf("\nNo hay empleados cargados!\n\n");
                }
                break;
            case 3:
                if (id>0)
                {
                    employees_removeEmployee (listE, SIZE_EMPLOYEES, listS, SIZE_SECTORS, 1, id);
                }
                else
                {
                    printf("\nNo hay empleados cargados!\n\n");
                }
                break;
            case 4:
                if (id>0)
                {
                    printf("\nEntrando al menu de informes...\n\n");
                    employees_subMenuReports (listE, SIZE_EMPLOYEES, listS, SIZE_SECTORS, id);
                }
                else
                {
                    printf("\nNo hay empleados cargados!\n\n");
                }
                break;
            case 5:
                printf("El programa se cerrara...\n");
                break;
            default:
                printf("No ingreso una opcion valida\n");
                break;
        }
        system("pause");
        system("cls");
    }while(option!=6);
    return 0;
}

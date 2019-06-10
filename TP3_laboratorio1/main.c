#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "style.h"
#include "Employee.h"

int main()
{
    system("color FD");
    int id = 0;
    int option = 0;
    int loadedFlag = 0;
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    welcome ("Bienvenido! :)   ", sizeof("Bienvenido! :)   "));
    do{
        employees_optionsMenu(&option, "\n1.Cargar empleados desde el archivo *Texto*\n2.Cargar empleados desde el archivo *Binario*\n\n"
        "3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Mostrar empleados\n7.SubMenu -> Ordenar\n\n8.Guardar datos "
        "en el archivo*Texto*\n9.Guardar datos en el archivo *Binario*\n\n10.Salir\n\n", 1, 10);

        switch(option)
        {
            case 1:
                if (loadedFlag == 0)
                {
                    if ((controller_loadFromText("dataT.csv", pArrayListEmployee))==1)
                    {
                        printf("\nLos empleados se cargaron con exito\n\n");
                        loadedFlag = 1;
                    }
                    else
                    {
                        printf("\n\aError, los empleados ya fueron cargados al sistema\n\n");
                    }
                }
                else
                {
                    printf("\n\aError, los empleados ya fueron cargados al sistema\n\n");
                }
                system("pause");
                break;
            case 2:
                if (loadedFlag == 0)
                {
                     if ((controller_loadFromBinary("dataB.csv", pArrayListEmployee))==1 && loadedFlag == 0)
                    {
                        printf("\nLos empleados fueron cargados con exito\n\n");
                        loadedFlag = 2;
                    }
                }
                else
                {
                    printf("\n\aError, los empleados ya fueron cargados al sistema\n\n");
                }
                system("pause");
                break;
            case 3:
                if (ll_len(pArrayListEmployee) != 0)
                {
                    system("cls");
                    employee_getLastId(pArrayListEmployee, &id);
                    if ((controller_addEmployee(pArrayListEmployee, &id))==1)
                    {
                        id++;
                    }
                }
                else
                {
                    printf("\n\aPor favor, cargue primero el archivo para evitar inconsistencias.\n\n");
                }
                system("pause");
                break;
            case 4:
                if (ll_len(pArrayListEmployee) != 0)
                {
                    system("cls");
                    controller_editEmployee(pArrayListEmployee, &id);
                }
                else
                    {
                        printf("\n\aPor favor, primero cargue el archivo!\n\n");
                    }
                system("pause");
                break;
            case 5:
                if (ll_len(pArrayListEmployee) != 0)
                {
                    system("cls");
                    controller_removeEmployee(pArrayListEmployee, &id);
                }
                else
                {
                    printf("\n\aPor favor, primero cargue el archivo!\n\n");
                }
                system("pause");
                break;
            case 6:
                if (ll_len(pArrayListEmployee) != 0)
                {
                    system("cls");
                    if (controller_ListEmployee(pArrayListEmployee)==1)
                    {
                        printf("\nMuestra terminada\n\n");
                    }
                    else
                    {
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                        printf("\n\aHubo un error en la muestra.\n\n");
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }
                else
                {
                    printf("\n\aPor favor, primero cargue el archivo!\n\n");
                }
                system("pause");
                break;
            case 7:
                if (ll_len(pArrayListEmployee) != 0)
                {
                    controller_sortEmployee(pArrayListEmployee);
                }
                else
                {
                    printf("\n\aPor favor, primero cargue el archivo!\n\n");
                    system("pause");
                }
                break;
            case 8:
                if (loadedFlag != 0)
                {
                    if (controller_saveAsText("dataT.csv" , pArrayListEmployee)==1)
                    {
                        printf("\nArchivos guardados\n\n");
                    }
                }
                else
                {
                    printf("\n\aPor favor, primero cargue el archivo!\n\n");
                }
                system("pause");
                break;
            case 9:
                if (loadedFlag != 0)
                {
                     if (controller_saveAsBinary("dataB.csv" , pArrayListEmployee)==1)
                    {
                        printf("\nArchivos guardados\n\n");
                    }
                }
                else
                {
                    printf("\n\aPor favor, primero cargue el archivo!\n\n");
                }
                system("pause");
                break;
            case 10:
                printf("\nEl programa se cerrara.\n\n");
                system("pause");
                break;
        }
    }while(option != 10);
    return 0;
}

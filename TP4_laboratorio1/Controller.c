#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "style.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int state = -1;
    FILE* pFile = NULL;
    pFile = fopen (path, "r");
    if (pFile!=NULL)
    {
        state = parser_EmployeeFromText(pFile, pArrayListEmployee);

    }
    fclose(pFile);
    pFile = NULL;
    return state;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int state = -1;
    FILE* pFile = NULL;
    pFile = fopen (path, "rb");
    if (pFile!=NULL)
    {
        state = parser_EmployeeFromBinary(pFile, pArrayListEmployee);

    }
    fclose(pFile);
    return state;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int state = -1;
    Employee* this = employee_new();
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    if ((employee_getAddParameters(this, id))==1)
    {
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("\n%5s  %14s %9s %10s\n\n", "ID", "NOMBRE", "HORAS", "SALARIO");
        employee_printOne(this);
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    }
    else
    {
        printf("\n\aERROR FATAL\nNo hay espacio en memoria para la operacion solicitada.\n\n");
    }

    if ((employee_verifyConformity("El empleado", "cargado"))==1)
    {
        ll_add(pArrayListEmployee, this);
        state = 1;
    }
    else
    {
        employee_delete(this);
    }
    return state;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int option;
    int state = -1;
    controller_ListEmployee(pArrayListEmployee);
    int index = employee_findById(pArrayListEmployee, "el id del empleado que desea buscar", id);
    Employee* this = ll_get(pArrayListEmployee, index);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    employee_printOne(this);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    if (employee_verifyConformity("El empleado", "modificado")==1)
    {
        if (index!=-1)
        {
            do
            {
                employees_optionsMenu(&option, "1.Modificar nombre\n2.Modificar horas\n3.Modificar salario\n4.Volver al menu anterior\n\n", 1, 4);
                switch (option)
                {
                case 1:
                    if ((employee_modName(this))==1)
                    {
                        printf("\nVolvera al menu de modificacion\n\n");
                    }
                    break;
                case 2:
                    if ((employee_modHours(this))==1)
                    {
                        printf("\nVolvera al menu de modificacion\n\n");
                    }
                    break;
                case 3:
                    if ((employee_modSalary(this))==1)
                    {
                        printf("\nVolvera al menu de modificacion\n\n");
                    }
                    break;
                }
            }
            while(option!=4);
        }
        else
        {
            printf("\n\aEl ID ingresado no es correcto!\n\n");
            printf("\nVolvera al menu anterior.\n\n");
            system("pause");
        }
    }
    return state;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int state = -1;
    Employee* this = NULL;
    controller_ListEmployee(pArrayListEmployee);
    int index = employee_findById (pArrayListEmployee, "el numero de ID de quien desea eliminar", id);

    if (index != -1)
    {
        this = ll_get(pArrayListEmployee, index);
    }
    if (this != NULL)
    {
        employee_printOne(this);
        if ((employee_verifyConformity("El empleado", "borrado"))==1)
        {

            ll_remove(pArrayListEmployee,index);
            state = 1;
        }
    }
    else
    {
        printf("\n\n\aEl empleado no fue encontrado.\n\n");
    }

    this = NULL;
    return state;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int state = -1;
    Employee* this;
    if (pArrayListEmployee != NULL)
    {
        printf("\n%5s  %14s %9s %10s\n\n", "ID", "NOMBRE", "HORAS", "SALARIO");
        for (i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%250==0)
            {
                system("pause");
            }

            this = ll_get(pArrayListEmployee, i);
            employee_printOne(this);
        }
        state = 1;
    }
    return state;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int (*pFunc) ();
    int option = 0;
    int state = -1;
    do
    {
        employees_optionsMenu(&option, "1.Ordenar por nombre (ascendente)\n2.Ordenar por nombre (descendente)\n\n3.Ordenar por Id (ascendente)\n"
                              "4.Ordenar por Id (descendente)\n\n5.Ordenar por horas (ascendente)\n6.Ordenar por horas (descendente)\n\n7.Salario (ascendente)\n8.Salario"
                              "(descendente)\n\n9.Volver al menu anterior\n\n", 1, 9);

        switch(option)
        {
        case 1:
            pFunc = employee_compareByName;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 1))==0) //1 ascendente 2 o 0 descendente
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 2:
            pFunc = employee_compareByName;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 0))==0) //1 ascendente 2 o 0 descendente
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 3:
            pFunc = employee_compareById;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 1))==0) //1 ascendente 2 o 0 descendente
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 4:
            pFunc = employee_compareById;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 0))==0) //1 ascendente 0 descendente
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 5:
            pFunc = employee_compareByHours;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 1))==0)
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 6:
            pFunc = employee_compareByHours;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 0))==0)
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 7:
            pFunc = employee_compareBySalary;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 1))==0)
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 8:
            pFunc = employee_compareBySalary;
            printf("\nLos datos estan siendo procesados\n");
            welcome ("...", sizeof("..."));
            if ((ll_sort(pArrayListEmployee, pFunc, 0))==0)
            {
                printf("\nLos empleados han sido ordenados.\n\n");
                state = 1;
                option = 9;
            }
            else
            {
                printf("\n\aHubo un error en el ordenamiento.\n\n");
            }
            system("pause");
            break;
        case 9:
            break;
        }

    }
    while (option!=9);

    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int state = -1;
    Employee* this = NULL;
    int id, hours, salary;
    char name[50];

    FILE* pFile = NULL;
    pFile = fopen (path, "w");

    if (pFile != NULL)
    {
        fprintf(pFile, "id,name,hours,salary\n");

        for (i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            this = ll_get(pArrayListEmployee, i);
            employee_getId(this, &id);
            employee_getName(this, name);
            employee_getHours(this, &hours);
            employee_getSalary(this, &salary);
            fprintf(pFile, "%d,%s,%d,%d\n", id, name, hours, salary);
            state = 1;
        }
    }

    fclose(pFile);
    this = NULL;
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int state = -1;
    Employee* this;
    FILE* pFile = NULL;
    pFile = fopen(path, "wb");
    if (pFile != NULL)
    {
        for (i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            this = ll_get(pArrayListEmployee, i);
            fwrite (this, sizeof(Employee), 1, pFile);
        }
        state = 1;
    }
    fclose(pFile);
    return state;
}


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Employee.h"
#include "input.h"
#include "strings.h"

void employee_getLastId(LinkedList* pArrayListEmployee,  int* id)
{
    int i;
    Employee* auxEmployee = NULL;
    *id = 0;
    for (i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmployee = ll_get(pArrayListEmployee, i);
        if (*id == auxEmployee->id)
        {
            *id = *id+1;
        }
    }
    return;
}
int employee_modName(Employee* this)
{
    int state = -1;
    Employee auxThis;
    getValidString("el nombre", auxThis.name, 60);
    firstToUpper(auxThis.name);
    if ((employee_verifyConformity("El nombre", "guardado"))==1)
    {
        strcpy(this->name, auxThis.name);
        state = 1;
    }
    return state;
}

int employee_modHours(Employee* this)
{
    int state = -1;
    Employee auxThis;
    getValidInt(&(auxThis.hours), "las horas trabajadas", 1, 800);
    if ((employee_verifyConformity("El numero de horas", "guardado"))==1)
    {
        this->hours = auxThis.hours;
        state = 1;
    }
    return state;
}

int employee_modSalary(Employee* this)
{
    int state = -1;
    Employee auxThis;
    getValidInt(&(auxThis.salary), "el salario", 6000, 200000);
    if ((employee_verifyConformity("El salario", "guardado"))==1)
    {
        this->salary = auxThis.salary;
        state = 1;
    }
    return state;
}

int employee_verifyConformity (char* message, char* cancelMessage)
{
    int state=-1; //bandera que avisa si el usuario desea guardar los datos ingresados
    char answer[2]; //respuesta del usuario

    printf("\n%s ingresado es correcto? (Si/No): ", message);
    fflush(stdin);
    scanf("%s", answer);
    stringToUpper(answer);

    if (strcmp(answer, "SI")==0)
    {
        printf("\n%s fue %s con exito.\n\n", message, cancelMessage);
        state=1;
    }
    else
    {
        printf("\n\a%s no sera %s.\n\n", message, cancelMessage);
    }
return state;
}

void employee_printOne(Employee* this)
{
    int id, salary, hours;
    char name[50];

    employee_getHours(this, &hours);
    employee_getId(this, &id);
    employee_getSalary(this, &salary);
    employee_getName(this, name);
    printf("\n%5d %15s %8d %11d\n", id, name, hours, salary);
}

void employee_delete(Employee* this)
{
    free(this);
    this = NULL;
}

int employee_findById (LinkedList* pArrayListEmployee, char* msg, int* idLimit)
{
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    Employee* auxEmployee;
    int index=-1;
    int id;
    int i;

    getValidInt(&id, msg, 1, 100000);

    for (i=0; i<ll_len(pArrayListEmployee);i++)
    {
        auxEmployee = ll_get(pArrayListEmployee, i);
        if (auxEmployee->id == id)
         {
          index = i;
          break;
         }
     }
    return index;
}

int employee_compareByName (void* emp1, void* emp2)
{
    int state = -2;
    Employee* auxEmp1 = (Employee*) emp1;
    Employee* auxEmp2 = (Employee*) emp2;
    state = strcmp(auxEmp1->name, auxEmp2->name);
    auxEmp1 = NULL;
    auxEmp2 = NULL;
    return state;
}

int employee_compareById (void* emp1, void* emp2)
{
    int state = 1;
    Employee* auxEmp1 = (Employee*) emp1;
    Employee* auxEmp2 = (Employee*) emp2;

    if (auxEmp1->id < auxEmp2->id)
    {
        state = -1;
    }
    else if (auxEmp1->id == auxEmp2->id)
    {
        state = 0;
    }

    auxEmp1 = NULL;
    auxEmp2 = NULL;
    return state;
}

int employee_compareByHours (void* emp1, void* emp2)
{
    int state = 1;
    Employee* auxEmp1 = (Employee*) emp1;
    Employee* auxEmp2 = (Employee*) emp2;

    if (auxEmp1->hours < auxEmp2->hours)
    {
        state = -1;
    }
    else if (auxEmp1->hours == auxEmp2->hours)
    {
        state = 0;
    }
    auxEmp1 = NULL;
    auxEmp2 = NULL;
    return state;
}

int employee_compareBySalary (void* emp1, void* emp2)
{
    int state = 1;
    Employee* auxEmp1 = (Employee*) emp1;
    Employee* auxEmp2 = (Employee*) emp2;

    if (auxEmp1->salary < auxEmp2->salary)
    {
        state = -1;
    }
    else if (auxEmp1->salary == auxEmp2->salary)
    {
        state = 0;
    }
    auxEmp1 = NULL;
    auxEmp2 = NULL;
    return state;
}

Employee* employee_new()
{
    Employee* oneEmployee;
    return oneEmployee = (Employee*) malloc (sizeof(Employee));
}

Employee* employee_newParameters(char* idStr,char* nameStr,char* hoursStr, char* salaryStr)
{
    Employee* this = employee_new();
    if (this != NULL)
    {
        employee_setId(this, atoi(idStr));
        employee_setName(this, nameStr);
        employee_setHours(this, atoi (hoursStr));
        employee_setSalary(this, atoi(salaryStr));
    }
    else
    {
        printf("\aFATAL ERROR-NO HAY ESPACIO EN LA MEMORIA RAM");
    }
    return this;
}

int employee_getAddParameters(Employee* this, int* id)
{
    int auxId, auxHours, auxSalary;
    char auxName [60];
    int state = -1;

    auxId = *id;
    getValidString("el nombre", auxName, 60);
    firstToUpper(auxName);
    getValidInt(&auxHours, "las horas trabajadas", 1, 800);
    getValidInt(&auxSalary, "el salario", 5000, 200000);


    if (this != NULL)
    {
        employee_setId(this, auxId);
        employee_setName(this, auxName);
        employee_setHours(this, auxHours);
        employee_setSalary(this, auxSalary);
        state = 1;
    }

    return state;
}

int employee_setId(Employee* this,int id)
{
    int state = -1;
    if (this != NULL)
    {
        this->id = id;
        state = 1;
    }
    return state;
}

int employee_getId(Employee* this,int* id)
{
    int state = -1;
    if (this!=NULL)
    {
        *id = this->id;
        state = 1;
    }
    return state;
}

int employee_setName(Employee* this,char* name)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(this->name, name);
        state = 1;
    }
    return state;

}

int employee_getName(Employee* this,char* name)
{
    int state = -1;
    if (this!=NULL)
    {
        strcpy(name, this->name);
        state = 1;
    }
    return state;
}

int employee_setHours(Employee* this,int hours)
{
    int state = -1;
    if (this != NULL)
    {
        this->hours = hours;
        state = 1;
    }
    return state;
}

int employee_getHours(Employee* this,int* hours)
{
    int state = -1;
    if (this!=NULL)
    {
        *hours = this->hours;
        state = 1;
    }
    return state;
}

int employee_setSalary(Employee* this,int salary)
{
    int state = -1;
    if (this != NULL)
    {
        this->salary = salary;
        state = 1;
    }
    return state;
}

int employee_getSalary(Employee* this,int* salary)
{
    int state = -1;
    if (this!=NULL)
    {
        *salary = this->salary;
        state = 1;
    }
    return state;
}

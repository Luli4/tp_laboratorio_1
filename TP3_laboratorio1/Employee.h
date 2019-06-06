#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char name[60];
    int hours;
    int salary;
}Employee;


int employee_modName(Employee* this);
int employee_modHours(Employee* this);
int employee_modSalary(Employee* this);

void employee_getLastId(LinkedList* pArrayListEmployee,  int* id);
int employee_getAddParameters(Employee* this, int* id);
void employee_printOne(Employee* this);
int employee_findById (LinkedList* pArrayListEmployee, char* msg, int* id);
int employee_verifyConformity (char* message, char* cancelMessage);

int employee_compareByName(void*, void*);
int employee_compareById (void* emp1, void* emp2);
int employee_compareByHours (void* emp1, void* emp2);
int employee_compareBySalary (void* emp1, void* emp2);


Employee* employee_new();
Employee* employee_newParameters(char* idStr,char* nameStr,char* hoursStr, char* salaryStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setHours(Employee* this,int hours);
int employee_getHours(Employee* this,int* hours);

int employee_setSalary(Employee* this,int salary);
int employee_getSalary(Employee* this,int* salary);

#endif // employee_H_INCLUDED

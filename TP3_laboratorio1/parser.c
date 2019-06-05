#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int state = -1;
    Employee* this = NULL;
    char idStr[7], nameStr[50], hoursStr[10], salaryStr[7];

    if (pArrayListEmployee!=NULL)
    {
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, nameStr, hoursStr, salaryStr);

        while(!(feof(pFile)))
        {
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, nameStr, hoursStr, salaryStr);
            this = employee_newParameters(idStr, nameStr, hoursStr, salaryStr);
            ll_add(pArrayListEmployee, this);
        }
    }

    if (feof(pFile))
    {
        state = 1;
    }

    fclose(pFile);
    pFile = NULL;
    return state;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int state = -1;
    Employee* this = NULL;

    if (pArrayListEmployee!=NULL)
    {
        while(!(feof(pFile)))
        {
            this = employee_new();
            fread(this, sizeof(Employee), 1, pFile);
            if (feof(pFile))
            {
                state = 1;
                break;
            }

            ll_add(pArrayListEmployee, this);
        }
    }
    fclose(pFile);
    pFile = NULL;
    return state;
}

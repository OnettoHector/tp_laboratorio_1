#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* reservoir;

    reservoir = (Employee*)malloc(sizeof(Employee));
    if (reservoir == NULL)
    {
     printf("No queda memoria \n");
     exit(0);
    }
    return reservoir;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* reservoir;

    reservoir = (Employee*)malloc(sizeof(Employee));
    if (reservoir == NULL)
    {
     printf("No queda memoria \n");
     exit(0);
    }
    reservoir->id = atoi(idStr);
    strcpy(reservoir->nombre, nombreStr);
    reservoir->horasTrabajadas = atoi(horasTrabajadasStr);

    return reservoir;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo = sueldo;

    return 1;
}

int employee_getId(Employee* this,int* id)
{
        *id = this->id;

    return 1;
}

int employee_getNombre(Employee* this,char* nombre)
{
        strcpy(nombre, this->nombre);
        return 1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
        *horasTrabajadas = this->horasTrabajadas;
    return 1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
        *sueldo = this->sueldo;

        return 1;
}








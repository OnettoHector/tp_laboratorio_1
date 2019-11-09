#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
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
    Employee *empleados;
    char id[25];
    char nombre[25];
    char horasTrabajadas[25];
    char sueldo[25];

    while (!feof(pFile))
    {
        fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n] \n",id,nombre,horasTrabajadas,sueldo);
        empleados = employee_newParametros(id,nombre,horasTrabajadas);
        employee_setSueldo(empleados, atoi(sueldo));
        ll_add(pArrayListEmployee,empleados);
    }


    return 1;
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
    Employee* empleados;
    int datos;
    while(!feof(pFile))
    {
        empleados = employee_new();
        datos = fread(empleados, sizeof(Employee), 1, pFile);
        if(datos == 1 && empleados != NULL)
        {
            ll_add(pArrayListEmployee, empleados);
        }
}

    return 1;
}

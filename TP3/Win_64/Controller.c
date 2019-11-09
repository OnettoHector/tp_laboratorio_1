#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "string.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* archivo = fopen(path, "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo \n");
        exit(0);
    }

    parser_EmployeeFromText(archivo,pArrayListEmployee);

    printf("Archivo cargado con exito \n");
    fclose(archivo);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    FILE* archivo = fopen(path, "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo \n");
        exit(0);
    }

    parser_EmployeeFromBinary(archivo,pArrayListEmployee);

    printf("Archivo cargado con exito \n");
    fclose(archivo);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *empleado;
    int id;
    char idStr[25];
    char nombre[25];
    char horasTrabajadas[25];
    char sueldo[25];
    int sueldoInt;

    getValidString("Ingrese el nombre del empleado \n","Solo se admiten letras",nombre);
    getStringNumeros("Ingrese las horas trabajadas \n",horasTrabajadas);
    getStringNumeros("Ingrese el sueldo\n",sueldo);

    id = controller_getMaxId(pArrayListEmployee);

    itoa(id,idStr,10);

    empleado = employee_newParametros(idStr,nombre,horasTrabajadas);
    sueldoInt = atoi(sueldo);
    employee_setSueldo(empleado,sueldoInt);
    ll_add(pArrayListEmployee,empleado);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int opcion;
    Employee *empleado;
    id = getValidInt("Ingrese el ID del empleado a modificar \n","Solo se admiten numeros",0,10000);

    empleado = ll_get(pArrayListEmployee,id);

    do
    {
    printf("Seleccione una opcion:\n"
           "1 para editar nombre \n"
           "2 para editar horas trabajadas \n"
           "3 para editar salario \n"
           "4 para salir \n");
           opcion = getValidInt(" ","Solo se permiten numeros",1,4);
           switch (opcion)
           {
           case 1:
            system("cls");
            getValidString("Ingrese el nuevo nombre del empleado \n","Solo se admiten letras",empleado->nombre);
            printf("Nombre cambiado exitosamente. \n");
            system("pause");
            system("cls");
            break;

           case 2:
            system("cls");
            empleado->horasTrabajadas = getValidInt("Ingrese el nuevo valor para horas trabajadas \n","Solo se admiten numeros",1,200);
            printf("Valor para horas trabajadas cambiado exitosamente  \n");
            system("pause");
            system("cls");
            break;

           case 3:
            system("cls");
            empleado->sueldo = getValidInt("Ingrese el nuevo valor para sueldo \n","Solo se admiten numeros",1,1000000);
            printf("Valor para sueldo cambiado exitosamente \n");
            system("pause");
            system("cls");
            break;

           }

    }while (opcion!=4);

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indice;

    indice = getValidInt("Ingrese el ID del empleado \n","Solo se admiten numeros\n",0,10000);

    indice = indice-1;

    ll_remove(pArrayListEmployee,indice);

    printf("Exito! \n");

    return 1;
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

    Employee *empleado;


    for (i=1;i<ll_len(pArrayListEmployee);i++)
    {
        empleado = ll_get(pArrayListEmployee,i);

        printf("%d %s %d %d \n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);

    }

    return 1;
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
    int opcion;
    Employee *empleadoUno;
    Employee *empleadoDos;
    char aux[25];
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    int i;
    int j;
    int len = ll_len(pArrayListEmployee);

    do
    {
    system("cls");
    printf("Ordenar por: \n"
            "1 por ID \n"
            "2 por nombre \n"
            "3 por horas trabajadas \n"
            "4 por salario \n"
            "5 salir \n");
           opcion = getValidInt(" ","Solo se permiten numeros",1,5);

           switch (opcion)
           {
            case 1:
                printf("Ordenando...\n");
                for (i=1;i<len-1;i++)
               {
                    empleadoUno = ll_get(pArrayListEmployee,i);
                   for (j=i+1;j<len;j++)
                   {
                    empleadoDos = ll_get(pArrayListEmployee,j);
                       if (empleadoUno->id > empleadoDos->id)
                       {
                           strcpy(aux,empleadoDos->nombre);
                           strcpy(empleadoDos->nombre,empleadoUno->nombre);
                           strcpy(empleadoUno->nombre,aux);

                           idAux = empleadoDos->id;
                           empleadoDos->id = empleadoUno->id;
                           empleadoUno->id = idAux;

                           horasTrabajadasAux = empleadoDos->horasTrabajadas;
                           empleadoDos->horasTrabajadas = empleadoUno->horasTrabajadas;
                           empleadoUno->horasTrabajadas = horasTrabajadasAux;

                           sueldoAux = empleadoDos->sueldo;
                           empleadoDos->sueldo = empleadoUno->sueldo;
                           empleadoUno->sueldo = sueldoAux;
                       }
               }
               }

               printf("Empleados ordenados exitosamente \n");
               system("pause");
               break;

           case 2:
               printf("Ordenando...\n");
               for (i=1;i<len-1;i++)
               {
                    empleadoUno = ll_get(pArrayListEmployee,i);
                   for (j=i+1;j<len;j++)
                   {
                    empleadoDos = ll_get(pArrayListEmployee,j);
                       if (strcmp(empleadoUno->nombre,empleadoDos->nombre)>0)
                       {
                           strcpy(aux,empleadoDos->nombre);
                           strcpy(empleadoDos->nombre,empleadoUno->nombre);
                           strcpy(empleadoUno->nombre,aux);

                           idAux = empleadoDos->id;
                           empleadoDos->id = empleadoUno->id;
                           empleadoUno->id = idAux;

                           horasTrabajadasAux = empleadoDos->horasTrabajadas;
                           empleadoDos->horasTrabajadas = empleadoUno->horasTrabajadas;
                           empleadoUno->horasTrabajadas = horasTrabajadasAux;

                           sueldoAux = empleadoDos->sueldo;
                           empleadoDos->sueldo = empleadoUno->sueldo;
                           empleadoUno->sueldo = sueldoAux;
                       }
               }
               }

               printf("Empleados ordenados exitosamente \n");
               system("pause");
               break;

           case 3:
            printf("Ordenando...\n");
            for (i=1;i<len-1;i++)
               {
                    empleadoUno = ll_get(pArrayListEmployee,i);
                   for (j=i+1;j<len;j++)
                   {
                    empleadoDos = ll_get(pArrayListEmployee,j);
                       if (empleadoUno->horasTrabajadas > empleadoDos->horasTrabajadas)
                       {
                           strcpy(aux,empleadoDos->nombre);
                           strcpy(empleadoDos->nombre,empleadoUno->nombre);
                           strcpy(empleadoUno->nombre,aux);

                           idAux = empleadoDos->id;
                           empleadoDos->id = empleadoUno->id;
                           empleadoUno->id = idAux;

                           horasTrabajadasAux = empleadoDos->horasTrabajadas;
                           empleadoDos->horasTrabajadas = empleadoUno->horasTrabajadas;
                           empleadoUno->horasTrabajadas = horasTrabajadasAux;

                           sueldoAux = empleadoDos->sueldo;
                           empleadoDos->sueldo = empleadoUno->sueldo;
                           empleadoUno->sueldo = sueldoAux;
                       }
               }
               }

               printf("Empleados ordenados exitosamente \n");
               system("pause");
               break;

           case 4:
               printf("Ordenando...\n");
               for (i=1;i<len-1;i++)
               {
                    empleadoUno = ll_get(pArrayListEmployee,i);
                   for (j=i+1;j<len;j++)
                   {
                    empleadoDos = ll_get(pArrayListEmployee,j);
                       if (empleadoUno->sueldo > empleadoDos->sueldo)
                       {
                           printf("Ordenando...\n");
                           strcpy(aux,empleadoDos->nombre);
                           strcpy(empleadoDos->nombre,empleadoUno->nombre);
                           strcpy(empleadoUno->nombre,aux);

                           idAux = empleadoDos->id;
                           empleadoDos->id = empleadoUno->id;
                           empleadoUno->id = idAux;

                           horasTrabajadasAux = empleadoDos->horasTrabajadas;
                           empleadoDos->horasTrabajadas = empleadoUno->horasTrabajadas;
                           empleadoUno->horasTrabajadas = horasTrabajadasAux;

                           sueldoAux = empleadoDos->sueldo;
                           empleadoDos->sueldo = empleadoUno->sueldo;
                           empleadoUno->sueldo = sueldoAux;
                       }
               }
               }

               printf("Empleados ordenados exitosamente \n");
               system("pause");
               break;


           }


    }while (opcion !=5);

    return 1;
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
    FILE* archivo;
    Employee* empleado;

    char nombre[25];
    int id;
    int horasTrabajadas;
    int sueldo;

    archivo = fopen(path, "w");
    if(archivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(archivo);
        for(int i=1; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(empleado,&id);
            employee_getNombre(empleado, nombre);
            employee_getHorasTrabajadas(empleado, &horasTrabajadas);
            employee_getSueldo(empleado, &sueldo);
            fprintf(archivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf("Datos guardados con exito\n");

    }
    fclose(archivo);
    return 1;
}


/** \brief Guarda los datos de los empleados en el archivoarchivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    Employee* empleados;
    int datos;
    archivo = fopen(path, "wb");

        rewind(archivo);
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
            empleados = (Employee*)ll_get(pArrayListEmployee,i);
            datos = fwrite(empleados, sizeof(Employee), 1, archivo);
            if(datos != 1)
            {
                printf("No se puede escribir en el archivo \n");
            }
            }
        printf("Datos guardados con exito \n");

    fclose(archivo);
    return 1;
}


int controller_getMaxId (LinkedList* pArrayListEmployee)
{
    Employee* empleados;
    int i;
    int numeroMax = 0;
    int primeraVez = 1;

    for (i=1;i<ll_len(pArrayListEmployee);i++)
    {
        empleados = ll_get(pArrayListEmployee,i);
            if (primeraVez == 1)
            {
            numeroMax = empleados->id;
            primeraVez = 0;
            }

            if (primeraVez == 0 && empleados->id > numeroMax)
                numeroMax = empleados->id;
    }

    return numeroMax+1;
}

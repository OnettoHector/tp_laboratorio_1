#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    int txt_cargado = 0;
    int bin_cargado = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
            system("cls");
            printf("Ingrese una opcion \n"
                   "1: Cargar datos desde archivo (texto)\n"
                   "2: Cargar datos desde archivo (binario)\n"
                   "3: Dar de alta un empleado\n"
                   "4: Modificar datos de empleado\n"
                   "5: Dar de baja un empleado\n"
                   "6: Listar empleados\n"
                   "7: Ordenar empleados\n"
                   "8: Guardar datos de empleados en archivo (texto)\n"
                   "9: Guardar datos de empleados en archivo (binario)\n"
                   "10:Salir \n");

                    opcion = getValidInt(" ","Solo se permiten numeros",1,10);

        switch(opcion)
        {
            case 1:
                system("cls");
                if (txt_cargado == 1 || bin_cargado == 1)
                {
                    printf("Ya se ha cargado un archivo \n");
                    system("pause");
                    break;
                }
                controller_loadFromText("data.csv",listaEmpleados);
                txt_cargado = 1;
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                if (txt_cargado == 1 || bin_cargado == 1)
                    {
                    printf("Ya se ha cargado un archivo \n");
                    system("pause");
                    break;
                    }
                controller_loadFromBinary("data.bin",listaEmpleados);
                bin_cargado = 1;
                system("pause");
                system("cls");
                break;

            case 3:
                if (txt_cargado == 0 && bin_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo \n");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    controller_addEmployee(listaEmpleados);
                    system("pause");
                    system("cls");
                    break;
                }


            case 4:
                if (txt_cargado == 0 && bin_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo \n");
                    system("pause");
                    break;
                }
                else
                {
                system("cls");
                controller_editEmployee(listaEmpleados);
                break;
                }

            case 5:
                if (txt_cargado == 0 && bin_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo \n");
                    system("pause");
                    break;
                }
                else
                {
                system("cls");
                controller_removeEmployee(listaEmpleados);
                break;
                }


            case 6:
                if (txt_cargado == 0 && bin_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo \n");
                    system("pause");
                    break;
                }
                else
                {
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
                break;
                }

            case 7:
                if (txt_cargado == 0 && bin_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo \n");
                    system("pause");
                    break;
                }
                else
                {
                system("cls");
                controller_sortEmployee(listaEmpleados);
                break;
                }

            case 8:
            if (txt_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo de texto \n");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    controller_saveAsText("data.csv",listaEmpleados);
                    break;
                }

            case 9:
                if (bin_cargado == 0)
                {
                    system("cls");
                    printf("Aun no se ha cargado un archivo binario \n");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    system("pause");
                    break;
                }

        }
    }while(opcion != 10);
    return 0;
}

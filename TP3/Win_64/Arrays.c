#include "arrays.h"
#include <string.h>

void inicializarArray(int elArray[], int capacidad, int valor)
{
    int i;

    for (i = 0; i<capacidad; i++)
    {
        elArray[i]/*.ISEMPTY*/ = valor;
    }
}

int buscarLugarLibre(int elArray[], int capacidad)
{
int i;

for (i = 0; i < capacidad; i++)
{
    if (elArray[i] == 1/*Valor en uno porque si se usa un isEmpty 1 seria true*/) //Esto se reemplaza por un isEmpty, en 1 esta vacio, en 0 ocupado.
    {
        return i;
    }
}
    return -1;

}

int buscarPorCodigo(int elArray[], int capacidad, int criterio)
{
    int i;

    for (i = 0; i < capacidad; i++)
    {
        if (elArray[i] == criterio /*&& elArray[i].isEmpty == 0*/)
        {
            return i;
        }
    }
    return -1;
}

void ordenarPorCriterio(int elArray[], int capacidad)
{
    int elArrayAux; //Esto se reemplazaria por una variable del tipo estructura, en vez de int por ej eLibro
    int i;
    int j;

    for (i = 0; i < capacidad; i++)
    {
        /*if (elArray[i].isEmpty == 0)
        {
            continue;
        }
        */
    for (j=i+1; j < capacidad; j++)
    {
        /*if (elArray[j].isEmpty == 0)
        {
            continue;
        }
        */

    if (strcmp(elArray[j]/*.CRITERIOCHAR*/,elArray[i]/*.CRITERIOCHAR*/)<0)
    {
        elArrayAux = elArray[j];
        elArray[j] = elArray[i];
        elArray[i] = elArrayAux;
    }
    else if(strcmp(elArray[j]/*.CRITERIOCHAR*/,elArray[i]/*.CRITERIOCHAR*/)==0)
    {
            if (elArray[i]/*.CRITERIOCHAR*/ > elArray[j]/*.CRITERIOCHAR*/)
                {
                elArrayAux = elArray[j];
                elArray[j] = elArray[i];
                elArray[i] = elArrayAux;
                }
            }
        }

    }
}

void cargarArray (int elArray[], int posicion, int criterioAux, char criterioStringAux[])
{
    elArray[posicion]/*.CRITERIO*/ = criterioAux;
    elArray[posicion]/*.CRITERIO*/ = criterioStringAux;
    //ElArray[posicion].isEmpty = 0;
}

void mostrarArray (int elArray[], int capacidad)
{
    int i;
    printf("\n CRITERIO |        CRITERIO      |   CRITERIO");
    for (i=0;i<capacidad;i++)
    {
        if (elArray[i]/*.isEmpty*/ != 1)
        {
            printf("\n| %d  | %s  | %d | ", elArray[i]/*.CRITERIOINT*/,elArray[i]/*.CRITERIOCHAR*/,elArray[i]/*.CRITERIOINT*/);
        }
    }
}

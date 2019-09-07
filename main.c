#include <stdio.h>
#include <stdlib.h>
#include "inc/operaciones.h"



int main()
{

    int seguir;
     seguir = 1;
    int numero1;
    int confirmacionUno = 0;
    int numero2;
    int confirmacionDos = 0;
    int rSuma;
    int rResta;
    int rMulti;
    float rDivi;
    int rFacto1;
    int rFacto2;
    int primeraVez;
    primeraVez = 1;
    int calculoExitoso;
    calculoExitoso = 0;

    printf("Bienvenido a la calculadora! \n \n");

    do
    {
        if (primeraVez == 1)
        {

        printf("Por favor, elija una opcion \n 1 Ingresar 1er operando \n 2 Ingresar 2do operando \n 3 Calcular todas las operaciones \n 4 Mostrar resultados \n 5 Salir \n \n");

        primeraVez = 0;

        }

        else
        {
            printf("Que desea hacer a continuacion? (1-5)\n");
        }

        switch (pedirOperacion())
        {
            case 1: printf("Ingrese el primer operando:\n");
                    numero1 = pedir();
                    printf("A = %d \n",numero1);
                    confirmacionUno = 1;
                    break;

            case 2: printf("Ingrese el segundo operando: \n");
                    numero2 = pedir();
                    printf("B = %d \n",numero2);
                    confirmacionDos = 1;
                    break;

            case 3: if (confirmacionUno == 0 || confirmacionDos == 0)
                    {
                        printf("Error al calcular, no se han ingresado dos operadores. \n");
                    }
                    else
                    {
                    rSuma = suma(numero1,numero2);
                    rResta = resta(numero1,numero2);
                    rMulti = multiplicacion(numero1,numero2);
                    rDivi = division(numero1,numero2);
                    rFacto1 = factorial(numero1);
                    rFacto2 = factorial(numero2);
                    printf("Calculos realizados con exito.\n");
                    calculoExitoso = 1;
                    }
                    break;

            case 4: if (confirmacionUno == 0 || confirmacionDos == 0)
                    {
                        printf("Error al calcular, no se han ingresado dos operadores. \n");
                    }
                    else if (calculoExitoso == 0)
                    {
                        printf("Error, aun no ha realizado el calculo (opcion 3) \n");
                    }
                    else
                    {
                     printf("El resultado de la suma entre %d y %d es %d \n",numero1,numero2,rSuma);
                     printf("El resultado de la resta entre %d y %d es %d \n",numero1,numero2,rResta);
                     printf("El resultado de la multiplicacion entre %d y %d es %d \n",numero1,numero2,rMulti);
                     if (numero2 == 0)
                     {
                         printf("No se puede dividir por cero. \n");
                     }
                     else
                    {
                     printf("El resultado de la division entre %d y %d es %.2f \n",numero1,numero2,rDivi);
                    }
                     if (numero1 <0)
                     {
                        printf("Error en primer operador, no se puede sacar factorial de numero negativo.");
                     }
                        else
                        {
                            printf("El resultado del factorial de %d es %d. ", numero1,rFacto1);
                        }

                    if (numero2 < 0)
                    {
                        printf("Error en segundo operador, no se puede sacar factorial de numero negativo \n.");
                    }
                    else
                    {
                        printf("El resultado del factorial de %d es %d\n", numero2,rFacto2);
                    }

                    system("pause");

                    system("cls");

                    confirmacionUno = 0;

                    confirmacionDos = 0;

                    calculoExitoso = 0;

                    primeraVez = 1;
                    }


                     break;

            case 5: printf("Adios!\n");
                    seguir = 0;
                    system("pause");
                    break;
        }

    }while (seguir == 1);

    }

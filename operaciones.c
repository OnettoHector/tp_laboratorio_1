
    #include <stdio.h>
    #include "inc/operaciones.h"


    int pedir ()
    {
        int pedido;

        scanf("%d", &pedido);
        return pedido;

    }

        int pedirOperacion()
    {
        int pedido;

        scanf("%d", &pedido);
        while (pedido <0 || pedido >5)
        {
            printf("Por favor, ingrese un numero dentro del rango (0-5) \n");
            scanf("%d", &pedido);
        }
        return pedido;
    }

    void operacion (int accionar)
    {
        int numero1;
        int numero2;
        float resultado;

        switch (accionar)
        {

        case 1: printf("Usted ha seleccionado suma \n");
                printf("Ingrese el 1er operando: \n");
                numero1 = pedir();
                printf("A = %d \n",numero1);
                printf("Ingrese el 2do operando: \n");
                numero2 = pedir();
                printf("B = %d \n",numero2);
                resultado = suma(numero1,numero2);
                printf("El resultado de %d + %d es: %.2f",numero1, numero2, resultado);

        break;

        case 2: printf("Usted ha seleccionado resta \n");
                printf("Ingrese el 1er operando: \n");
                numero1 = pedir();
                printf("A = %d \n",numero1);
                printf("Ingrese el 2do operando: \n");
                numero2 = pedir();
                printf("B = %d \n",numero2);
                resultado = resta(numero1,numero2);
                printf("El resultado de %d - %d es: %.2f",numero1, numero2, resultado);
        break;

        case 3: printf("Usted ha seleccionado multiplicacion \n");
                printf("Ingrese el 1er operando: \n");
                numero1 = pedir();
                printf("A = %d \n",numero1);
                printf("Ingrese el 2do operando: \n");
                numero2 = pedir();
                printf("B = %d \n",numero2);
                resultado = multiplicacion(numero1,numero2);
                printf("El resultado de %d * %d es: %.2f",numero1, numero2, resultado);
        break;

        case 4: printf("Usted ha seleccionado division: \n");
                printf("Ingrese el 1er operando: \n");
                numero1 = pedir();
                printf("A = %d \n",numero1);
                printf("Ingrese el 2do operando: \n");
                numero2 = pedir();
                printf("B = %d \n",numero2);
                while (numero2 == 0)
                {
                    printf("No se puede dividir por cero, reingrese divisor");
                    numero2 = pedir();
                }
                resultado = division(numero1,numero2);
                printf("El resultado de %d / %d es: %.2f",numero1, numero2, resultado);
        break;

        case 5: printf("Usted ha seleccionado factorial: \n");
                printf("Ingrese el 1er operando: \n");
                numero1 = pedir();
                printf("A = %d \n",numero1);
                while (numero1 < 0)
                {
                    printf("Error! Los numeros negativos no tienen factorial \n");
                    printf("Ingrese el 1er operador: \n");
                    numero1 = pedir();
                }
                printf("Ingrese el 2do operando: \n");
                numero2 = pedir();
                printf("B = %d \n",numero2);
                while (numero2 < 0)
                {
                    printf("Error! Los numeros negativos no tienen factorial \n");
                    printf("Ingrese el 2do operador: \n");
                    numero1 = pedir();
                }
                resultado = factorial(numero1,numero2);

        }

    }


    int suma (int numero1, int numero2)
    {
        int resultado;

        resultado = numero1 + numero2;
        return resultado;
    }

    int resta(int numero1, int numero2)
    {
        int resultado;

        resultado = numero1 - numero2;
        return resultado;
    }

    int multiplicacion(int numero1, int numero2)
    {
        int resultado;

        resultado = numero1 * numero2;
        return resultado;
    }

    float division(int numero1, int numero2)
    {
        float resultado;

        resultado = numero1 / (float)numero2;
        return resultado;
    }
    int factorial (int numero1, int numero2)
    {
        int factorialUno;
        int factorialDos;
        int resultadoFactorialUno = 1;
        int resultadoFactorialDos = 1;

        for (factorialUno = numero1; factorialUno > 0; factorialUno--)
            {
                resultadoFactorialUno *= factorialUno;
            }


        for (factorialDos = numero2; factorialDos > 0; factorialDos--)
            {
                resultadoFactorialDos *= factorialDos;
            }

            printf("El factorial de %d es: %d y el factorial de %d es: %d", numero1 ,resultadoFactorialUno, numero2, resultadoFactorialDos);

            return 0;
    }

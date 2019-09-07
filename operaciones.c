
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
    int factorial (int numero1)
    {
        int factorial;
        int resultadoFactorial = 1;

        for (factorial = numero1; factorial > 0; factorial--)
            {
                resultadoFactorial *= factorial;
            }

            return resultadoFactorial;
    }

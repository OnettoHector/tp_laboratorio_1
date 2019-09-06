#include <stdlib.h>

/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \return El numero ingresado por el usuario
 */

int pedir ();

/**
 * \brief Solicita el numero de operacion al usuario y devuelve el resultado
 * \return El numero ingresado por el usuario
 */

int pedirOperacion();

/**
 * \brief Realiza una operacion dependiendo del numero que se le ingrese (1 suma - 2 resta 3 - multiplicacion 4 - division - 5 factorial) y devuelve el resultado
 * \param accionar El numero que determina qué operación se llevara a cabo
 * \return El resultado de la/s operacion
 */

void operacion (int accionar);

/**
 * \brief Suma dos numeros y devuelve el resultado
 * \param numero1 El primer sumando
 * \param numero2 El segundo sumando
 * \return El total
 */

int suma (int numero1, int numero2);

/**
 * \brief Resta dos numeros y devuelve el resultado
 * \param numero1 El minuendo
 * \param numero1 El sustraendo
 * \return La diferencia
 */

int resta (int numero1, int numero2);

/**
 * \brief Multiplica dos numeros y devuelve el resultado
 * \param numero1 El multiplicando
 * \param numero2 El multiplicador
 * \return El producto
 */

int multiplicacion (int numero1, int numero2);

/**
 * \brief Divide dos numeros y devuelve el resultado
 * \param numero1 El dividendo
 * \param numero2 El divisor
 * \return El cociente
 */

float division (int numero1, int numero2);

/**
 * \brief Calcula el factorial de dos numeros, y devuelve dos resultados
 * \param numero1 El primer numero al que se le sacara el factorial
 * \param nmero2 El segundo numero al que se le sacara el factorial
 \ return El factorial de el primer y segundo numero
 */

int factorial (int numero1, int numero2);


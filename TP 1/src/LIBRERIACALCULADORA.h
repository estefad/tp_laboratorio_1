/*
 * LIBRERIACALCULADORA.h
 *
 *  Created on: 25 mar. 2021
 *      Author: Estefania
 */

#ifndef LIBRERIACALCULADORA_H_
#define LIBRERIACALCULADORA_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float Sumar(float, float)
 * @brief la funcion recibe dos parametros(int, float, etc)y los suma
 *
 * @return retorna la suma de ambos numeros
 */
float Sumar(float numero1, float numero2);

/**
 * @fn float Restar(float, float)
 * @brief la funcion recibe dos parametros(int, float, etc)y los resta
 *
 * @return retorna la resta de ambos numeros
 */
float Restar(float numero1, float numero2);

/**
 * @fn float Multiplicacion(float, float)
 * @brief la funcion recibe dos parametros(int, float, etc)y realiza el producto
 *
 * @return retorna el producto de ambos numeros
 */
float Multiplicacion(float numero1, float numero2);

/**
 * @fn float Division(float, float)
 * @brief la funcion recibe dos parametros(int, float, etc)y realiza la division
 *
 * @return retorna el cociente de ambos numeros
 */
float Division(float numero1, float numero2);

/**
 * @fn unsigned long int Factorial(long int)
 * @brief la funcion factorial recibe un paramentro y calcula el factorial
 * 		 del parametro ingresado
 *
 * @return retorna el factorial de dicho parametro
 */
unsigned long int Factorial(long int numero1);

#endif /* LIBRERIACALCULADORA_H_ */

/*
 * VALIDACIONES.h
 *
 *  Created on: 28 mar. 2021
 *      Author: Estefania
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int PedirEntero(char[], char[], int, int)
 * @brief la funcion recibe y valida un dato del tipo entero
 *
 * @return retorna un entero
 */
int PedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);

/**
 * @fn float PedirFlotante(char[], char[], float, float)
 * @brief la funcion recibe y valida un dato del tipo float
 *
 * @return retorna un flotante
 */
float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo);


/**
 * @fn int ValidoFactorial(float)
 * @brief valido si el parametro que se ingresa es decimal o entero para poder
 * 			realizar el factorial.
 *
 * @return 1 si el parametro es decimal, 0 si es entero
 */
int ValidoFactorial(float numero);


/**
 * @fn double PedirDouble(char[], char[], double, double)
 * @brief la funcion recibe y valida un dato del tipo double
 *
 * @return retorna un valor preciso con coma o punto
 */
double PedirDouble(char mensaje[], char mensajeError[], double minimo, double maximo);

/**
 * @fn char PedirChar(char[], char[])
 * @brief la funcion recibe y valida un caracter
 * 		en este caso, le asigno el valor a la cadena para
 * 		que usuario pueda ingresar la cant que quiera.
 *
 * @return retorna una cadena
 */
char PedirChar(char mensaje[], char mensajeError[]);


#endif /* VALIDACIONES_H_ */

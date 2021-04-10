/*
 * VALIDACIONES.h
 *
 *  Created on: 28 mar. 2021
 *      Author: Estefania
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>

int PedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);
float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo);
double PedirDouble(char mensaje[], char mensajeError[], double minimo, double maximo);
char PedirChar(char mensaje[], char mensajeError[]);


#endif /* VALIDACIONES_H_ */

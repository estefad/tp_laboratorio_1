/*
 * DataInt.h
 *
 *  Created on: 10 jun. 2021
 *      Author: Estefania
 */

#ifndef DATAINT_H_
#define DATAINT_H_

#include <stdio.h>
#include<stdlib.h>

int GetInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);
int GetName(char* pResultado, int tam,char* mensaje, char* mensajeError, int reintentos);
int ValidarEntero(char* numero);

#endif /* DATAINT_H_ */

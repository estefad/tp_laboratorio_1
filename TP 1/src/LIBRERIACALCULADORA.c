/*
 * LIBRERIACALCULADORA.c
 *
 *  Created on: 25 mar. 2021
 *      Author: Estefania
 */
#include "LIBRERIACALCULADORA.h"

float Sumar(float numero1, float numero2)
{
	float resultado;
	resultado=numero1+numero2;
	return resultado;
}



float Restar(float numero1, float numero2)
{
	float resultado;
	resultado=numero1-numero2;
	return resultado;
}



float Multiplicacion(float numero1, float numero2)
{
	float resultado;
	resultado=numero1*numero2;
	return resultado;
}



float Division(float numero1, float numero2)
{
	float resultado;
	resultado=numero1/numero2;
	return resultado;
}



unsigned long int Factorial(long int numero1, long int numero2)
{
	 long int resultado;
	 resultado=numero1*(numero1-1);
	 resultado=numero2*(numero2-1);
	 return resultado;
}


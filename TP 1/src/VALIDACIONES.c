/*
 * VALIDACIONES.c
 *
 *  Created on: 28 mar. 2021
 *      Author: Estefania
 */

#include "VALIDACIONES.h"
#include <string.h>


int PedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int numeroIngresado;

    printf("\n %s", mensaje);
	scanf("%d", &numeroIngresado);
	while(numeroIngresado<minimo || numeroIngresado>maximo)
	{
	    printf("\n %s", mensajeError);
	    scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}


float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo)
{
    float numeroIngresado;

    printf("\n %s", mensaje);
	scanf("%f", &numeroIngresado);
	while(numeroIngresado<minimo || numeroIngresado>maximo)
	{
	    printf("\n %s", mensajeError);
	    scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

int ValidoFactorial(float numeroFloat)
{
	int rtn;
	int tomoEntero;

	tomoEntero=numeroFloat;//si ingreso un numero decimal, va a tomar solo la parte entera y en if comparo.
	if(numeroFloat>tomoEntero || numeroFloat<0)
	{
		rtn=1;
	}
	else
	{
		rtn=0;
	}

  return rtn;
}

double PedirDouble(char mensaje[], char mensajeError[], double minimo, double maximo)
{
     double numeroIngresado;

    printf("\n %s", mensaje);
	scanf("%lf", &numeroIngresado);
	while(numeroIngresado<minimo || numeroIngresado>maximo)
	{
	    printf("\n %s", mensajeError);
	    scanf("%lf", &numeroIngresado);
	}

	return numeroIngresado;
}


char PedirChar(char mensaje[], char mensajeError[])
{
	char nombreIngresado;
	char auxString[1000];

    printf("\n %s", mensaje);
    fflush(stdin);
	scanf("%s", &nombreIngresado);
	while(strlen(auxString)>1000)
	{
	    printf("\n %s", mensajeError);
	    fflush(stdin);
	    scanf("%s", &nombreIngresado);
	}

	return nombreIngresado;
}

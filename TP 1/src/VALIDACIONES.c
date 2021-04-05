/*
 * VALIDACIONES.c
 *
 *  Created on: 28 mar. 2021
 *      Author: Estefania
 */

#include "VALIDACIONES.h"

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


double PedirDouble(char mensaje[], char mensajeError[], double minimo, double maximo)
{
     double numeroIngresado;

    printf("\n %s", mensaje);
	scanf("%f", &numeroIngresado);
	while(numeroIngresado<minimo || numeroIngresado>maximo)
	{
	    printf("\n %s", mensajeError);
	    scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}


char pedirChar(char mensaje[], char mensajeError[])
{
	char nombreIngresado;

    printf("\n %s", mensaje);
	scanf("%f", &nombreIngresado);
	while(mensaje!="algo")
	{
	    printf("\n %s", mensajeError);
	    scanf("%f", &nombreIngresado);
	}

	return nombreIngresado;
}

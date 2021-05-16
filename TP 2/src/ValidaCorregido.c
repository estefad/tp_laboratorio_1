/*
 * VALIDACIONES.c
 *
 *  Created on: 28 mar. 2021
 *      Author: Estefania
 */

#include "ValidaCorregido.h"

#include <ctype.h>
#include <string.h>
#define N 10000


//PEDIR ENTERO

int PedirEntero(char mensaje[], char mensajeError[])
{
    char numero[N];
    int rtn;

    printf("\n %s", mensaje);
    fflush(stdin);
	scanf("%[^\n]", numero);


	while(ValidarInt(numero)==0)
	{
		printf("\n %s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]", numero);
	}
	rtn=atoi(numero);

	return rtn;
}

/*while(ValidarInt(numero)==0)
	{
		do
		{
			printf("\n %s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", numero);

		}while(mensajeError!=5);
	}*/

//VALIDAR ENTERO

int ValidarInt(char numero[])
{
	int resultado=1;
	int i;

	for(i=0; i<strlen(numero); i++)
	{
		if(isdigit(numero[i])==0)
		{
			resultado=0;
			break;
		}

	}
	return resultado;
}


//ENTERO SIN RANGO

int PedirEnteroRango(char mensaje[], char mensajeError[], int min, int max)
{
    int numeroIngresado;
    numeroIngresado=PedirEntero(mensaje, mensajeError);

	while(numeroIngresado<min || numeroIngresado>max)
	{
	    printf("\n %s", mensajeError);
	    scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}


//PEDIR FLOAT

float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo)
{
    float numeroIngresado;

    printf("\n %s", mensaje);
	scanf("%f", &numeroIngresado);
	while(ValidoFloat(numeroIngresado)!=0 || numeroIngresado<minimo || numeroIngresado>maximo)
	{
	    printf("\n %s", mensajeError);
	    scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}


//VALIDO FLOAT

int ValidoFloat(float numeroFloat)
{
	int rtn=0;
	int tomoEntero;

	tomoEntero=numeroFloat;//si ingreso un numero decimal, va a tomar solo la parte entera y en if comparo.
	if(numeroFloat>tomoEntero || numeroFloat<0)
	{
		rtn=1;
	}


  return rtn;
}

//FLOAT SIN RANGO

float PedirFlotanteSinRango(char mensaje[], char mensajeError[])
{
    float numeroIngresado;

    printf("\n %s", mensaje);
	scanf("%f", &numeroIngresado);
	while(ValidoFloat(numeroIngresado)!=0)
	{
	    printf("\n %s", mensajeError);
	    scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}


//PEDIR DOUBLE

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


//PEDIR CHAR

char PedirChar(char mensaje[], char mensajeError[])
{
	char caracter[1000];
	//int rtn;

    printf("\n %s", mensaje);
    fflush(stdin);
	scanf("%[^\n]", caracter);
	while(ValidarLetras(caracter)==0 || strlen(caracter)>1)
	{
	    printf("\n %s", mensajeError);
	    fflush(stdin);
	    scanf("%[^\n]", caracter);
	}
	//rtn=caracter[0];

	return caracter[0];
}


//VALIDAR CHAR

int ValidarLetras(char cadena[])
{
		int i;
		int resultado;

		for(i=0; i<strlen(cadena); i++)
		{
			if(!(isalpha(cadena[i])))
			{
				resultado=0;
			}
			else
			{
				resultado=1;
			}
		}
	return resultado;
}

//PEDIR CADENAS DE STRING

void PedirString(char MSJ[], char ERRORMSJ[],char copiaParametro[], int TAM)
{
	char parametro[1000];

	printf("%s", MSJ);
	fflush(stdin);
	gets(parametro);

	while(ValidarLetras(parametro)!=1 || strlen(parametro) > TAM || strlen(parametro) == 0) //strlen(longitud) es mayor a tam o menor a tam, se repite el ciclo
	{
		printf("ERROR. Fuera de rango CARACTERES [MIN]=1 [MAX]=%d.\n", TAM);
		printf("%s", ERRORMSJ);
		fflush(stdin);
		gets(parametro);
	}
	strcpy(copiaParametro, parametro);

}


int MenuGen()
{
	int opcion;


	printf("  *[MENU DE EMPLEADOS]*\n");
	printf("  *********************\n");
	printf("  .1.ALTA EMPLEADOS\n");
	printf("  .2.MODIFICACIONES\n");
	printf("  .3.BAJA EMPLEADOS\n");
	printf("  .4.Listado\n");
	printf("  .5.Listado\n");
	printf("  .6.SALIR\n");
	fflush(stdin);
	opcion=PedirEnteroRango("-Ingrese una opcion del MENU-\n", "-ERROR, ingrese una opcion valida-\n", 1, 6);

	return opcion;
}




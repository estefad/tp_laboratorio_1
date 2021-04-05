/*
 ============================================================================
 Name        : LIBRERIACALCULADORA1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIBRERIACALCULADORA.h"


int main()
{
	char respuesta;
	float numeroA;
	float numeroB;
	int opcionesMenu;
	float resultado;
	long int resultadoA;
	long int resultadoB;
	float contadorX;
	float numeroX;
	float contadorY;
	float numeroY;

	respuesta='s';
	contadorX=0;
	contadorY=0;

	setbuf(stdout, NULL);

	do
	{
		/*printf(" '1'- Operando X");
		printf("\n '2'- Operando Y");
		printf("\n '3' - Calcular todas las operaciones");
		printf("\n '4' - Mostrar resultados");
		printf("\n '5' - Salir");
		scanf("\n %d", &opcionesMenu);*/

		switch (opcionesMenu)
		{
			case '1':
				printf("Usted ingreso la opcion 1. Por favor ingrese el primer numero (A=x): ");
				scanf("%f", &numeroA);
				if(contadorX==0)
				{
					numeroA=numeroX;
					contadorX++;
				}
				break;

			case '2':
				printf("Usted ingreso la opcion 2. Por favor ingrese el segundo numero (B=y): ");
				scanf("%f", &numeroB);
				if(contadorY==0)
				{
					numeroB=numeroY;
					contadorY++;
				}
				break;

			case '3':
				resultado=Sumar(numeroA, numeroB);
				resultado=Restar(numeroA, numeroB);
				resultado=Multiplicacion(numeroA, numeroB);
				resultado=Division(numeroA, numeroB);
				resultadoA=Factorial(numeroA, numeroB);
				resultadoB=Factorial(numeroB, numeroA);
				printf("se estan ejecutando las operaciones para X= %f e Y= %f", numeroA, numeroB);
				break;

			case '4':
				printf("La suma es: %f \n", resultado);
				printf("La resta es: %f \n", resultado);
				printf("La multiplicacion es: %f \n", resultado);
				if(numeroB==0)
				{
					printf("error, no se admite la division por cero");
				}
				else
				{
					printf("la division es: %f \n", resultado);
				}
				printf("\n El resultado de factorial X! es: %ld \n El resultado de factorial Y! es: %ld ", resultadoA, resultadoB);
				break;

			case '5':
				printf("\n desea salir? s/n");
				break;
			}

	}while(respuesta<5);






	return EXIT_SUCCESS;
}

/*printf("la suma es: %f \n", resultado);
 * printf("la resta es: %f \n", resultado);
 * printf("la multiplicacion es: %f \n", resultado);
 * printf("el resultado de factorial es: %ln ", resultado);
 *
 * if(numeroB==0)
   {
		printf("error, no se admite la division");
   }
   else
   {
		printf("la division es: %f \n", resultado);
   }
		 *
 *
 * */

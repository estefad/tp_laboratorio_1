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
#include "VALIDACIONES.h"


int main()
{
	char respuesta;
	float numeroA;
	float numeroB;
	int opcionesMenu;
	float resultadoSuma;
	float resultadoResta;
	float resultadoProducto;
	float resultadoDivision;
	long int resultadoA;
	long int resultadoB;
	float contadorX;
	//float X;
	float contadorY;
	//float Y;

	respuesta='s';
	contadorX=0;
	contadorY=0;

	setbuf(stdout, NULL);

	do
	{
		system("COLOR 05");
		printf("bienvenido a la calculadora \n");

		printf("\n '1'- Ingresar Operando X");
		printf("\n '2'- Ingresar Operando Y");
		printf("\n '3' - Calcular todas las operaciones");
		printf("\n '4' - Mostrar resultados");
		printf("\n '5' - Salir");

		opcionesMenu=PedirEntero("ingrese una opcion", "Error, reingrese una opcion valida", 1, 5);
		//scanf("\n %d", &opcionesMenu);

		switch (opcionesMenu)
		{
			case 1:
				if(opcionesMenu==1)
				{
					printf("Usted ingreso la opcion 1. Por favor ingrese el primer numero (A=x): ");
					scanf("%f", &numeroA);
					if(contadorX==0)
					{
						//numeroA=X;
						contadorX++;
					}
				}

				break;

			case 2:
				printf("Usted ingreso la opcion 2. Por favor ingrese el segundo numero (B=y): ");
				scanf("%f", &numeroB);
				if(contadorY==0)
				{
					//numeroB=Y;
					contadorY++;
				}
				break;

			case 3:
				resultadoSuma=Sumar(numeroA, numeroB);
				resultadoResta=Restar(numeroA, numeroB);
				resultadoProducto=Multiplicacion(numeroA, numeroB);
				resultadoDivision=Division(numeroA, numeroB);
				resultadoA=Factorial(numeroA, numeroB);
				resultadoB=Factorial(numeroB, numeroA);
				printf("se estan ejecutando las operaciones para X= %f e Y= %f", numeroA, numeroB);
				break;

			case 4:
				printf("La suma es: %f \n", resultadoSuma);
				printf("La resta es: %f \n", resultadoResta);
				printf("La multiplicacion es: %f \n", resultadoProducto);
				if(numeroB==0)
				{
					printf("error, no se admite la division por cero");
				}
				else
				{
					printf("la division es: %.2f \n", resultadoDivision);
				}
				printf("\n El resultado de factorial X! es: %ld \n El resultado de factorial Y! es: %ld ", resultadoA, resultadoB);
				break;

			case 5:
				printf("\n desea salir? s/n");
				break;
				system("pause");
			}

	}while(respuesta=='s');






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

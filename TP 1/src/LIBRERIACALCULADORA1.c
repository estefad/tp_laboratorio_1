/*
 ============================================================================
 Name        : LIBRERIACALCULADORA1.c
 Author      : Dominguez Estefania
 Curso       : 1f
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn librerias Calculadora y Validaciones de datos
 * @brief calculadora recibe parametros del tipo float y realiza las operaciones aritmeticas
 * 		validaciones, recibe los datos que ingresa el usuario(tipo int o float)y los valida
 *
 * @return Calculadora retorna los resultados de las operaciones aritmeticas,
 * 		   Validaciones,retorna los parametros ingresados por el usuario.
 */
#include "LIBRERIACALCULADORA.h"
#include "VALIDACIONES.h"

int main()
{

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
	float contadorY;
	int caseTres;
	float contadorA;
	float contadorB;

	contadorX=0;
	contadorY=0;
	caseTres=0;
	contadorA=0;
	contadorB=0;

	setbuf(stdout, NULL);

	do
	{
		system("COLOR 05");
		printf("**BIENVENIDO A LA CALCULADORA** \n");

		printf("\n '1'- Ingresar Operando A=%.2f", numeroA);
		if(contadorA==0)
		{
			numeroA=0;
			contadorA++;
		}
		printf("\n '2'- Ingresar Operando B=%.2f", numeroB);
		if(contadorB==0)
		{
			numeroB=0;
			contadorB++;
		}
		printf("\n '3' - Calcular todas las operaciones");
		printf("\n '4' - Mostrar resultados");
		printf("\n '5' - Salir");

		opcionesMenu=PedirEntero("\n *Ingrese una opcion: ", "Error, reingrese una opcion valida", 1, 5);

		switch (opcionesMenu)
		{
			case 1:

				printf("Usted ingreso la opcion 1. Por favor ingrese el primer numero: ");
				fflush(stdin);
				scanf("%f", &numeroA);
				if(contadorX==0)
				{
					contadorX++;
				}
				system("pause");
				break;

			case 2:
				printf("Usted ingreso la opcion 2. Por favor ingrese el segundo numero: ");
				fflush(stdin);
				scanf("%f", &numeroB);
				if(contadorY==0)
				{
					contadorY++;
				}
				system("pause");
				break;

			case 3:
				caseTres++;
				if(contadorX==0)
				{
					printf("opcion invalida, debe ingresar el operador A=x \n");
				}
				else
				{
					if(contadorY==0)
					{
						printf("opcion invalida, debe ingresar el operador B=y \n");
					}
					else
					{
						printf("se estan ejecutando las operaciones para A= %.2f e B= %.2f \n", numeroA, numeroB);
						resultadoSuma=Sumar(numeroA, numeroB);
						resultadoResta=Restar(numeroA, numeroB);
						resultadoProducto=Multiplicacion(numeroA, numeroB);
						resultadoDivision=Division(numeroA, numeroB);
						resultadoA=Factorial(numeroA);
						resultadoB=Factorial(numeroB);
					}
				}
				system("pause");
				break;

			case 4:
				if(caseTres==0)
				{
					printf("No se pueden mostrar los resultados, no se ingreso el calculo de las operaciones \n");
				}
				else
				{
					printf("El resultado de A+B es: %.2f \n", resultadoSuma);
					printf("El resultado de A-B es: %.2f \n", resultadoResta);
					printf("El resultado de A*B es: %.2f \n", resultadoProducto);
					if(numeroB==0)
					{
						printf("error, no se admite la division por cero \n");
					}
					else
					{
						printf("El resultado de A/B es: %.2f \n", resultadoDivision);
					}
					if(numeroA<0 || numeroA==',' || numeroA=='.')
					{
						resultadoA=printf("No se puede ejecutar factorial A! ya que es un numero decimal o negativo");
					}
					else
					{
						printf("\n El factorial A! es: %ld  \n ", resultadoA);
					}
					if(numeroB<0 || numeroB==',' || numeroB=='.')
					{
						resultadoB=printf("No se puede ejecutar factorial B! ya que es un numero decimal o negativo");
					}
					else
					{
						printf("\n El factorial B! es: %ld  \n ", resultadoB);
					}
				}
				system("pause");
				break;

			case 5:
				printf("\n **INGRESO SALIR...GRACIAS POR USAR LA CALCULADORA TP1** \n ");
				system("pause");
				break;
			}

	}while(opcionesMenu!=5);



	return EXIT_SUCCESS;
}



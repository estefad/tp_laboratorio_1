
#ifndef GET_H_
#define GET_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
 * @fn int PedirEntero(char[], char[])
 * @brief la funcion recibe y valida un dato del tipo entero
 *
 * @param mensaje
 * @param mensajeError
 * @return retorna un entero
 */
int PedirEntero(char mensaje[], char mensajeError[]);

/**
 * @fn int ValidarInt(char[])
 * @brief
 *
 * @param numero
 * @return
 */
int ValidarInt(char numero[]);



int ValidarEntero(float numIngresado);



/**
 * @fn int PedirEnteroRango(char[], char[], int, int)
 * @brief la funcion pide un entero
 * 		y valida la entrada
 *
 * @param mensaje
 * @param mensajeError
 * @return el entrero ingresado
 */
int PedirEnteroRango(char mensaje[], char mensajeError[], int minimo, int maximo);

/**
 * @fn float PedirFlotante(char[], char[], float, float)
 * @brief la funcion recibe y valida un dato del tipo float
 *
 * @return retorna un flotante
 */
float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo);


/**
 * @fn int ValidoFloat(float)
 * @brief la funcion valida si el parametro ingresado es un numero decimal o negativo
 *
 * @param numeroFloat
 * @return 1 si es decimal o negativo, 0 si es solo entero o raiz u otro.
 */
int ValidoFloat(float numeroFloat);


/**
 * @fn float PedirFlotanteSinRango(char[], char[])
 * @brief recibe un flotante y lo valida,sin rango min o max
 *
 * @param mensaje
 * @param mensajeError
 * @return el numero ingresado
 */
float PedirFlotanteSinRango(char mensaje[], char mensajeError[]);


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


/**
 * @fn int ValidarLetras(char[], int)
 * @brief la funcion valida si una cadena esta conformada
 * 		solo por letras del alfabeto, o espacios (mayusc, minusc o '')
 *
 * @return 1 si la condicion se cumple, 0 si la condicion no se cumple
 */
int ValidarLetras(char cadena[]);


/**
 * @fn void PedirString(char[], char[], char[], int)
 * @brief
 *
 * @param MSJ
 * @param ERRORMSJ
 * @param copiaParametro
 * @param TAM
 */
void PedirString(char MSJ[], char ERRORMSJ[], char copiaParametro[], int TAM);

int MenuGen();



#endif /* GET_H_ */

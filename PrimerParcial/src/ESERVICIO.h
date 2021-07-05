/*
 * ESERVICIO.h
 *
 *  Created on: 25 may. 2021
 *      Author: Estefania
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Get.h"
#include "eEstructura.h"

#define MAX_CHARS_CADENA 200
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int horarioEntregas;
	char diaEntrega[MAX_CHARS_CADENA];
	char zonaEntrega[MAX_CHARS_CADENA];
	char cliente[MAX_CHARS_CADENA];
	int isEmpty;

}eEntrega;

typedef struct{
	int idServicio;
	char descripcion[MAX_CHARS_CADENA];
	float precio;
	eEntrega miEntrega;
	int isEmpty;
}eServicios;


typedef struct
{
	int id;
	int contador;
	float acumulador;
	char descripcion[MAX_CHARS_CADENA];
}eAuxiliar;

/**
 * @fn void InicializarServicios(eServicios[], int)
 * @brief inicializa array en espacio libre
 *
 * @param lista
 * @param tam
 */
void InicializarServicios(eServicios lista[],int tam);

/**
 * @fn int ObtenerIDservicio(void)
 * @brief genera id autoincremental
 *
 * @return id
 */
int ObtenerIDservicio(void);

/**
 * @fn int ServicioBuscarLibre(eServicios[], int)
 * @brief busca espacio para carga de datos
 *
 * @param array
 * @param TAM
 * @return el index del primer vector libre
 */
int ServicioBuscarLibre(eServicios array[], int TAM);

/**
 * @fn void HardcodeoServicio(eServicios[], int)
 * @brief listado de datos pasados
 *
 * @param lista
 * @param tam
 */
void HardcodeoServicio(eServicios lista[], int tam);
/**
 * @fn void MostrarHardcodeo(eServicios[], int)
 * @brief muestra la lista de datos hardcodeados
 *
 * @param lista
 * @param tam
 */
void MostrarHardcodeo(eServicios lista[], int tam);

/**
 * @fn int Servicio_CargarDatos(eServicios[], int)
 * @brief busca espacio libre y si encuentra pide carga datos del alta
 *
 * @param array
 * @param TAM
 * @return datos cargados
 */
int Servicio_CargarDatos(eServicios array[], int TAM);

/**
 * @fn eServicios AltaServicio(eServicios[], int)
 * @brief  pide cargar datos
 *
 * @param lista
 * @param tam
 * @return datos cargados
 */
eServicios AltaServicio(eServicios lista[], int tam);

/**
 * @fn void MostrarServicio(eServicios)
 * @brief print de  listado de servicios
 *
 * @param listado
 * @param tamT
 */
void MostrarServicio(eServicios listado);

/**
 * @fn void ListaServicios(eServicios[], int)
 * @brief lista de servicios hardcodeados
 *
 * @param listado
 * @param tam
 */
void ListaServicios(eServicios listado[],int tam);

/**
 * @fn int eServicios_BuscarPorID(eServicios[], int, int)
 * @brief busco id
 *
 * @param array
 * @param TAM
 * @param ID
 * @return devuelve el index del id encontrado
 */
int eServicios_BuscarPorID(eServicios array[], int TAM, int ID);

/**
 * @fn int eServiciosBaja(eServicios[], int)
 * @brief borrado logico
 *
 * @param array
 * @param TAM
 * @return1 si se accedio a la baja, 0 sino se accedio
 */
int eServiciosBaja(eServicios array[], int TAM);

/**
 * @fn int TrabajosOrdenadosPorMarca(eServicios[], int, eBicicleta[], int)
 * @brief ordena segun parametro
 *
 * @return 1 si ordeno, 0 en caso de error
 */
int TrabajosOrdenadosPorMarca(eServicios array[], int TAM, eBicicleta lista[], int tam);

/**
 * @fn void MostrarTrabajosOrdenadosPorMarca(eServicios[], int, eBicicleta[], int)
 * @brief
 *
 * @param listaServicio
 * @param tamM
 * @param miLista
 * @param tam
 */
void MostrarTrabajosOrdenadosPorMarca(eServicios listaServicio[],int tamM, eBicicleta miLista[], int tam);

/**
 * @fn void ListadoDeServiciosConBicicletas(eServicios[], int, eBicicleta[], int)
 * @brief imprime listado de servicios de cada bicicleta
 *
 * @param listado
 * @param tamT
 * @param lista
 * @param tam
 */
void ListadoDeServiciosConBicicletas(eServicios listado[], int tamT, eBicicleta lista[], int tam);

//void ServiciosConMasTrabajos(eServicios lista[],int tam);
//void MostrarServiciosConMasTrabajos(eServicios listado[], int tam);
/**
 * @fn int ListadoEntregas(eServicios[], int, eBicicleta[], int)
 * @brief listado de entrega, segun parametros
 *
 * @return
 */
int ListadoEntregas(eServicios listaServicio[],int tamM,eBicicleta miLista[], int tam);

/**
 * @fn void HardcodeoEntregas(eEntrega[], int)
 * @brief hardcodeo de la estructura de entregas
 *
 * @param lista
 * @param tam
 */
void HardcodeoEntregas(eEntrega lista[], int tam);

/**
 * @fn void MostrarHardcodeoEntregas(eEntrega[], int, eBicicleta[])
 * @brief muestra la estrucrura con los datos pasados
 *
 * @param lista
 * @param tam
 * @param miMarca
 */
void MostrarHardcodeoEntregas(eEntrega lista[], int tam, eBicicleta miMarca[]);




#endif /* ESERVICIO_H_ */

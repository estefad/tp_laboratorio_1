

#ifndef EESTRUCTURA_H_
#define EESTRUCTURA_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENA 200
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int idBicicleta;
	char marcaBicicleta[MAX_CHARS_CADENA];
	int rodadoBicicleta;
	char color[50];
	int isEmpty;
}eBicicleta;

/**
 * @fn void InicializarBicicletas(eBicicleta[], int)
 * @brief inicializa array en espacio libre
 *
 * @param lista
 * @param tam
 */
void InicializarBicicletas(eBicicleta lista[],int tam);

/**
 * @fn int ObtenerIDbicicleta(void)
 * @brief busca id
 *
 * @return en index del id encontrado
 */
int ObtenerIDbicicleta(void);

/**
 * @fn int BicicletaBuscarLibre(eBicicleta[], int)
 * @brief id AUTOINCREMENTAL
 *
 * @param array
 * @param TAM
 * @return id
 */
int BicicletaBuscarLibre(eBicicleta array[], int TAM);

/**
 * @fn void HardcodeoBicicleta(eBicicleta[], int)
 * @brief hardcodeo de datos de la estructura
 *
 * @param lista
 * @param tam
 */
void HardcodeoBicicleta(eBicicleta lista[], int tam);

/**
 * @fn void MostrarHardcodeoBicicleta(eBicicleta[], int)
 * @brief muestra los datos hardcodeados
 *
 * @param lista
 * @param tam
 */
void MostrarHardcodeoBicicleta(eBicicleta lista[], int tam);

/**
 * @fn int eBicicleta_BuscarPorID(eBicicleta[], int, int)
 * @brief busqueda por id
 *
 * @param array
 * @param TAM
 * @param ID
 * @return el index del id encontrado
 */
int eBicicleta_BuscarPorID(eBicicleta array[], int TAM, int ID);




#endif /* EESTRUCTURA_H_ */

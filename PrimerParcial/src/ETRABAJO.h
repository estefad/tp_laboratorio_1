
#ifndef ETRABAJO_H_
#define ETRABAJO_H_

#include "ESERVICIO.h"
#include "eEstructura.h"


#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


typedef struct{

	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct{

	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajos;

/**
 * @fn int TotalPorServicios(eServicios[], int, eTrabajos[], int)
 * @brief  trabajos ordenados por año y ante igualdad de año por marca de la bicicleta.
 *
 * @param lista
 * @param tam
 * @param listado
 * @param tamT
 * @return
 */
int TotalPorServicios(eServicios lista[], int tam, eTrabajos listado[], int tamT);

/**
 * @fn void InicializarTrabajo(eTrabajos[], int)
 * @brief inicializa array en espacio libre
 *
 * @param lista
 * @param tam
 */
void InicializarTrabajo(eTrabajos lista[],int tam);

/**
 * @fn int ObtenerID(void)
 * @brief genera id autoincremental
 *
 * @return id
 */
int ObtenerID(void);

/**
 * @fn int TrabajoBuscarLibre(eTrabajos[], int)
 * @brief busca espacio libre para cargar datos
 *
 * @param array
 * @param TAM
 * @return el index del primer vector libre
 */
int TrabajoBuscarLibre(eTrabajos array[], int TAM);

/**
 * @fn void HardcodeoTrabajo(eTrabajos[], int)
 * @brief listado de datos pasados
 *
 * @param lista
 * @param tam
 */
void HardcodeoTrabajo(eTrabajos lista[], int tam);

/**
 * @fn void MostrarHardcodeoTrabajo(eTrabajos[], int)
 * @brief muestra el hardcodeo de datos
 *
 * @param lista
 * @param tam
 */
void MostrarHardcodeoTrabajo(eTrabajos lista[], int tam);

/**
 * @fn int CargarDatosTrabajo(eTrabajos[], int)
 * @brief busca espacio libre y si encuentra pide carga datos del alta
 *
 * @param array
 * @param TAM
 * @return el auxiliar del espacio que encontro
 */
int CargarDatosTrabajo(eTrabajos array[], int TAM);

/**
 * @fn eTrabajos AltaTrabajo()
 * @brief pide cargar datos
 *
 * @return datos cargados
 */
int AltaTrabajo();

/**
 * @fn int Modificacion(eTrabajos[], int, eServicios[], int, eBicicleta[], int)
 * @brief modifica un elemento de la lista
 *
 * @return 0 en caso de error, 1 en caso de modificacion exitosa
 */
int Modificacion(eTrabajos producto[],int tam,eServicios servicio[], int tamT, eBicicleta miBicicleta[], int tamB);

/**
 * @fn int eTrabajosBaja(eTrabajos[], int, eBicicleta[], int)
 * @brief baja logica
 *
 * @return-1 para baja, borra el dato y deja cargar otro
 */
int eTrabajosBaja(eTrabajos array[], int TAM,eBicicleta lista[], int tam);

/**
 * @fn int eTrabajos_BuscarPorID(eTrabajos[], int, int)
 * @brief busca id por parametro
 *
 * @return el index del id buscado
 */
int eTrabajos_BuscarPorID(eTrabajos array[], int TAM, int ID);

/**
 * @fn void MostrarTrabajo(eTrabajos, int, eBicicleta, int)
 * @brief muestra un trabajo cargado
 *
 * @param listado
 * @param tamT
 * @param lista
 * @param tamb
 */
void MostrarTrabajo(eTrabajos listado, int tamT, eBicicleta lista, int tamb);

/**
 * @fn int MostrarTodosLosTrabajos(eTrabajos[], int, eBicicleta[], int)
 * @brief muestra todos los trabajos cargados
 *
 * @param listado
 * @param TAM
 * @param lista
 * @param tam
 * @return lista de trabajos cargados
 */
int MostrarTodosLosTrabajos(eTrabajos listado[], int TAM, eBicicleta lista[], int tam);

/**
 * @fn int OrdenarporCriterio(eTrabajos[], int, eBicicleta[], int)
 * @brief ordena segun parametro pasado
 *
 * @return 0 en caso de error, 1 en caso de sort exitoso
 */
int OrdenarporCriterio(eTrabajos array[], int TAM, eBicicleta lista[], int tam);

/**
 * @fn void ListarTrabajos(eTrabajos[], int, eServicios[], int)
 * @brief muestra listado segun criterio de ordenamiento
 *
 * @param listaTrabajo
 * @param tam
 * @param listaServicio
 * @param tamM
 */
void ListarTrabajos(eTrabajos listaTrabajo[],int tam, eServicios listaServicio[],int tamM,eBicicleta miLista[], int tamb);

/**
 * @fn void ListadoPorCriterio(eTrabajos[], int, eServicios[], int, eBicicleta[], int)
 * @brief muestra listado, segun ordenamiento
 *
 * @param listaTrabajo
 * @param tam
 * @param listaServicio
 * @param tamM
 * @param miLista
 * @param tamb
 */
void ListadoPorCriterio(eTrabajos listaTrabajo[],int tam, eServicios listaServicio[],int tamM, eBicicleta miLista[], int tamb);


/**
 * @fn int BiciRojaConServicio(eServicios[], int, eBicicleta[], int, eTrabajos[], int)
 * @brief funcion que suma la cant de bicicletas rojas que tengan un servicio
 *
 * @return 1 si el contador encontro bicicleta con el parametro pasado, 0 en caso de error
 */
int BiciRojaConServicio(eServicios listaServicios[],int tamS,eBicicleta listaBicicletas[], int tamB, eTrabajos lista[], int tam);

/**
 * @fn int ServicioOrdenadoZona(eEntrega[], int, eTrabajos[], int, eServicios[], int)
 * @brief ordena el servicio con horario, segun al zona
 *
 * @return
 */
int ServicioOrdenadoZona(eEntrega listado[], int TAM, eTrabajos lista[], int tam, eServicios listaS[], int tamS);

/**}
 * @fn void MostrarTrabajosOrdenadosPorZona(eEntrega[], int, eServicios[], int, eTrabajos[], int)
 * @brief muestra los servicios ordenados por zona y horario
 *
 * @param miEntrega
 * @param tamE
 * @param listaServicio
 * @param tamM
 * @param lista
 * @param tam
 */
void MostrarTrabajosOrdenadosPorZona(eEntrega miEntrega[], int tamE, eServicios listaServicio[],int tamM, eTrabajos lista[], int tam);

#endif /* ETRABAJO_H_ */

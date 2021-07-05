#include "ETRABAJO.h"

#define MAX 8


int main(void)
{

	setbuf(stdout, NULL);
	int opcion;

	eServicios listaServicio[MAX];
	eTrabajos listaTrabajo[MAX];
	eBicicleta listaBicicleta[MAX];
	eEntrega listaEntregas[MAX];

	InicializarServicios(listaServicio, MAX);
	InicializarTrabajo(listaTrabajo, MAX);
	InicializarBicicletas(listaBicicleta, MAX);

	HardcodeoTrabajo(listaTrabajo, MAX);
	HardcodeoServicio(listaServicio, MAX);
	HardcodeoBicicleta(listaBicicleta, MAX);
	HardcodeoEntregas(listaEntregas, MAX);


	do{

		opcion=MenuGen();

		switch(opcion)
		{
			case 1:
				//ALTA
					if(CargarDatosTrabajo(listaTrabajo, MAX))
					{
						printf("\n*Dato generado correctamente*\n");
						MostrarTodosLosTrabajos(listaTrabajo, MAX, listaBicicleta, MAX);
					}

				break;

			case 2:
				//MODIFICACION
					Modificacion(listaTrabajo, MAX, listaServicio, MAX, listaBicicleta, MAX);

				break;

			case 3:
				//BAJA
					eTrabajosBaja(listaTrabajo, MAX, listaBicicleta, MAX);

				break;

			case 4:
				//listado de todos los trabajos ordenados por año y ante igualdad de año por marca de la bicicleta.
				ListarTrabajos(listaTrabajo, MAX, listaServicio, MAX, listaBicicleta, MAX);

				break;

			case 5:
				//LISTADO de servicios-
				ListaServicios(listaServicio,5);

				break;

			case 6:
				//LISTADO total por servicios
				TotalPorServicios(listaServicio, MAX, listaTrabajo, MAX);
				break;

			case 7:
				//Listado de todos los trabajos ordenados por marca de la bicicleta.
				MostrarTrabajosOrdenadosPorMarca(listaServicio, 5, listaBicicleta, 5);

				break;

			case 8:
				//Listado de servicios con los datos de las bicicletas que se lo realizaron
				ListadoDeServiciosConBicicletas(listaServicio, MAX, listaBicicleta, MAX);

				break;
			case 9:
				//LISTADO La cantidad de biciletas de color Rojo que realizaron un servicio-
				if(!BiciRojaConServicio(listaServicio, MAX, listaBicicleta, MAX, listaTrabajo, MAX))
				{
					puts("no hay bicicletas rojas con servicio realizado");
				}

				break;

			case 10://dia y horario de entrega segun marca
				if(!ListadoEntregas(listaServicio, 5, listaBicicleta, 5))
				{
					puts("no hay entregas programadas");
				}

				break;

			case 11://servicio segun zona
				MostrarTrabajosOrdenadosPorZona(listaEntregas, MAX, listaServicio, MAX, listaTrabajo, MAX);

				break;

			case 12:
			{
				printf("\nsalida del menu de opciones.. \n");
				system("pause");
				break;
			}
		}

	}while(opcion!=12);

	return EXIT_SUCCESS;
}





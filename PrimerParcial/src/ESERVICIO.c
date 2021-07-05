#include "ESERVICIO.h"


void InicializarServicios(eServicios lista[],int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty = LIBRE;

	}
}


int ObtenerIDservicio(void)
{
	int idUnico=19999;
	idUnico+=1;

	return idUnico;
}


int ServicioBuscarLibre(eServicios array[], int TAM)
{
	int index;
	int i;

	index=-1;

	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				index = i;
				break;
			}
		}
	}
	return index;
}

void HardcodeoServicio(eServicios lista[], int tam)
{
	int i;

	int idServicio[30]={20000,20001,20002,20003,20004,20000,20002,20003};
	char descripcion[100][10]={{"limpieza"},{"parche"},{"centrado"},{"cadena"},{"rueda"},{"limpieza"},{"parche"},{"centrado"}};
	int precio[30]={250,300,400,350,150,250,300,400};
	int espacio[50]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

	for(i=0; i<tam; i++)
	{

		lista[i].idServicio=idServicio[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].precio=precio[i];
		lista[i].isEmpty=espacio[i];

	}
}

void MostrarHardcodeo(eServicios lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		HardcodeoServicio(lista, tam);
		printf(" %5d  %10s  %2.f \n", lista[i].idServicio, lista[i].descripcion, lista[i].precio);
	}

}




void HardcodeoEntregas(eEntrega lista[], int tam)
{
	int i;

	int horario[30]={14,12.30,18,13,13.15,11,16,17};
	char diaEntrega[100][10]={{"lunes"},{"martes"},{"miercoles"},{"jueves"}, {"viernes"},{"martes"},{"miercoles"},{"jueves"}};
	char zonaEntrega[100][10]={{"palermo"},{"avellaneda"},{"lanus"},{"caballito"}, {"banfield"},{"caballito"}, {"escalada"},{"cañuelas"}};
	char nombreCliente[150][20]={{"joan Bianco"},{"Ana Villaba"},{"Victor Gutierrez"},{"Nicolas Ojeda"}, {"Hernan Marma"},
								{"Jose montero"},{"agus pacci"}, {"veronica ruiz"}};

	int espacio[50]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

	for(i=0; i<tam; i++)
	{
		lista[i].horarioEntregas=horario[i];
		strcpy(lista[i].diaEntrega,diaEntrega[i]);
		strcpy(lista[i].zonaEntrega,zonaEntrega[i]);
		strcpy(lista[i].cliente,nombreCliente[i]);
		lista[i].isEmpty=espacio[i];
	}
}


void MostrarHardcodeoEntregas(eEntrega lista[], int tam, eBicicleta miMarca[])
{
	int i;
	eServicios array[tam];
	for(i=0; i<tam; i++)
	{
		HardcodeoEntregas(lista, tam);
		TrabajosOrdenadosPorMarca(array, tam, lista, tam);
		printf("%5d  %10s  %5s  %10s  %10s\n", lista[i].horarioEntregas, lista[i].diaEntrega, miMarca[i].marcaBicicleta, lista[i].zonaEntrega, lista[i].cliente);
	}

}


int Servicio_CargarDatos(eServicios array[], int TAM)
{

	int auxiliar;//EL QUE RETORNO CON LOS DATOS QUE NECESITO SIN ID NI ESTADO

	auxiliar=ServicioBuscarLibre(array, TAM);
	if(auxiliar!=-1) //si es distinto, encontro espacio
	{
		AltaServicio(array, TAM);
		printf("\n*Dato generado correctamente*\n");
	}
	else
	{
		printf("No hay espacio suficiente!!!");
	}
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}



eServicios AltaServicio(eServicios lista[], int tam)
{
	eServicios aux;

    PedirString("Ingrese descripcion del servicio: ", "error, ingrerse una opcion correcta", aux.descripcion, 25);

    aux.idServicio = ObtenerIDservicio(); //obtengo id unico

    aux.isEmpty = OCUPADO;

    return aux;
}


void MostrarServicio(eServicios listado)
{

	printf("\n%d %5s %5f \n", listado.idServicio,
							  listado.descripcion,
							  listado.precio);
}




void ListaServicios(eServicios listado[],int tam)
{
	int i;

	printf(" iD   servicio   precio  \n");

	for(i=0; i<tam; i++)
	{
	    printf(" %5d - %10s - %2.f \n", listado[i].idServicio, listado[i].descripcion, listado[i].precio);
	}
}


int eServicios_BuscarPorID(eServicios array[], int TAM, int ID)
{
	int rtn = -1;
	int i;

		for (i = 0; i < TAM; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idServicio == ID && array[i].isEmpty == OCUPADO)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}

	return rtn;
}


int eServiciosBaja(eServicios array[], int TAM) //borrado logico
{
	int rtn = 0;
	int idServicio;
	int index;
	int flag = 0;
	char respuesta;


	if (ServicioBuscarLibre(array, TAM))
	{
		flag = 1;
	}

	//SI HAY  PARA DAR DE BAJAi
	if (flag)
	{
		//PIDO ID A DAR DE BAJA
		idServicio=PedirEnteroRango("ingrese el id de servicio 20000-limpieza 20001-parche 20002-centrado 20003-cadena", "Error, porfavor ingrese un id valido", 20000, 20003);

		//BUSCO INDEX POR ID EN ARRAY
		while (eServicios_BuscarPorID(array, TAM, idServicio) == -1)
		{
			puts("NO EXISTE ID.");
			idServicio = PedirEntero("ingrese el id de servicio 20000-limpieza 20001-parche 20002-centrado 20003-cadena", "Error, porfavor ingrese un id valido");
		}
		//aca estoy con id valido
		//OBTENGO INDEX DEL ARRAY DE Mascota A DAR DE BAJA
		index =eServicios_BuscarPorID(array, TAM, idServicio);

		respuesta=PedirChar("desea continuar con la baja? s/n", "ingrese una opcion valida");
		if(respuesta=='s')
		{
			printf("baja exitosa");
			array[index].isEmpty = BAJA;
			rtn = 1;
		}
	}

	return rtn;
}



int TrabajosOrdenadosPorMarca(eServicios array[], int TAM, eBicicleta lista[], int tam)
{
	int rtn = 0;
	int i;
	int j;
	int indexBici1;
	int indexBici2;
	eBicicleta auxiliar;

	for(i=0; i<TAM-1; i++)//trabajo
	{
		for(j=i+1; j<TAM; j++)
		{
			indexBici1=eBicicleta_BuscarPorID(lista, tam, lista[i].idBicicleta);
			indexBici2=eBicicleta_BuscarPorID(lista, tam, lista[j].idBicicleta);

			if(strcmp(lista[indexBici1].marcaBicicleta , lista[indexBici2].marcaBicicleta)<0)//comparo silos indices coinciden en marca
			{
					auxiliar = lista[i];
					lista[i] = lista[j];
					lista[j] = auxiliar;
			}
			rtn=1;
		}
	}
	return rtn;
}


//G. Listado de todos los trabajos ordenados por marca de la bicicleta.
void MostrarTrabajosOrdenadosPorMarca(eServicios listaServicio[],int tamM, eBicicleta miLista[], int tam)
{
	int j;

	puts("   - Trabajos Ordenados por Marca -");
	TrabajosOrdenadosPorMarca(listaServicio, tamM, miLista, tam);
	for(j=0; j<tam; j++)
	{
	printf("    %s %10s \n", listaServicio[j].descripcion, miLista[j].marcaBicicleta);
	}
}



//9-Listado de servicios con los datos de las bicicletas que se lo realizaron
void ListadoDeServiciosConBicicletas(eServicios listado[], int tamT, eBicicleta lista[], int tam)
{
	int j;

	puts("id servicio--descripcion--precio--id de bicicleta--marca--rodado--color");

	for(j=0; j<tamT; j++)
	{
		printf("\n%d %15s %10.2f %8d %15s %8d %5s \n", listado[j].idServicio, listado[j].descripcion, listado[j].precio, lista[j].idBicicleta,
											lista[j].marcaBicicleta, lista[j].rodadoBicicleta, lista[j].color);
	}
}


//LISTADO de entrgas por dia//que se imprima la marca y el dia de entrega segun la marca
//
int ListadoEntregas(eServicios listaServicio[], int tamM,eBicicleta miLista[], int tam)
{
	int rtn=0;
	eEntrega lista[tam];

	printf(" HORA ENTREGA- -DIA- -MARCA- -ZONA- -CLIENTE-\n");

	MostrarHardcodeoEntregas(lista, tam, miLista);

	rtn=1;

	return rtn;
}






#include "ETRABAJO.h"

//LISTADO total por servicios
int TotalPorServicios(eServicios lista[], int tam, eTrabajos listado[], int tamT)
{
	int rtn=0;
	int i;
	int j;
	int indexAux;

	eAuxiliar aux[tam];

	for(i=0;i<tam;i++)//lista servicios
	{
		aux[i].id=lista[i].idServicio;
		aux[i].contador=0;
		aux[i].acumulador=0;

		for(j=0;j<tam;j++)
		{
			indexAux = eServicios_BuscarPorID(lista, tam, listado[j].idServicio);//comparo id trabajo con servicio
			if(indexAux!=-1)//si encontro el id
			{
				aux[indexAux].contador++;
				aux[indexAux].acumulador+=lista[indexAux].precio;
			}
		}
	}
	puts("\n--DESCRIPCION--PRECIO--TOTAL POR SERVICIO--\n");
	for(i=0; i<tam; i++)
	{

		printf(" %s   --     %5.2f   --   %5.2f \n", lista[i].descripcion, lista[i].precio, aux[i].acumulador);
		rtn=1;
	}
	return rtn;
}


void InicializarTrabajo(eTrabajos lista[],int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty = LIBRE;

	}
}


int ObtenerID(void)
{
	int idUnico=0;
	idUnico+=1;

	return idUnico;
}



int TrabajoBuscarLibre(eTrabajos lista[], int TAM)
{
	int index;
	int i;

	index=-1;

	if (lista != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				index = i;
				break;
			}
		}
	}
	return index;
}



void HardcodeoTrabajo(eTrabajos lista[], int tam)
{
	int i;

	eFecha fecha[100]={{29,03,2001},{23,06,2008},{04,05,2018},{19,07,1996},{29,03,2001},{23,06,2008},{04,05,2018},{13,07,2008}};
	int idServicio[30]={20000,20001,20002,20003,20004,20001,20002,20003};
	int idBicicleta[30]={25,26,27,28,29,30,31,32};

	for(i=0; i<tam; i++)
	{
		lista[i].fecha=fecha[i];
		lista[i].idServicio=idServicio[i];
		lista[i].idBicicleta=idBicicleta[i];
	}
}


void MostrarHardcodeoTrabajo(eTrabajos lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		HardcodeoTrabajo(lista, tam);
		printf(" %d/%d/%d \n", lista[i].fecha.dia, lista[i].fecha.mes, lista[i].fecha.anio);
	}

}


int CargarDatosTrabajo(eTrabajos lista[], int TAM)
{

	int auxiliar;//EL QUE RETORNO CON LOS DATOS QUE NECESITO SIN ID NI ESTADO

	auxiliar=TrabajoBuscarLibre(lista, TAM);
	if(auxiliar!=-1) //si es distinto, encontro espacio
	{
		AltaTrabajo(TAM);
	}
	else
	{
		printf("No hay espacio suficiente!!!");
	}
	return auxiliar;
}



int AltaTrabajo()
{
	int rtn=0;
	eTrabajos aux;
	eServicios auxi;
	char auxiliar[30];
	eBicicleta miBicicleta;

	aux.fecha.dia=PedirEnteroRango("ingrese dia: ", "error, reingrese dia valido", 1, 31);
	aux.fecha.mes=PedirEnteroRango("ingrese mes: ", "error, reingrese mes valido", 1, 12);
	aux.fecha.anio=PedirEnteroRango("ingrese año: \n", "error, reingrese año valido", 1990, 2021);
	aux.idBicicleta=ObtenerID();

	PedirString("Ingrese el color de su bicicleta: ", "Error, ingrese un color valido, solo caracteres", auxiliar, 30);
	strcpy(miBicicleta.color,auxiliar);

	miBicicleta.rodadoBicicleta=PedirEntero("Ingrese el rodado de su bicicleta: ", "Error, solo numeros");


	PedirString("Ingrese la marca de su bicicleta: bmx, Sava, vox, nsz, lion: ", "Error, ingrese una marca valido,. solo caracteres", auxiliar, 30);
	strcpy(miBicicleta.marcaBicicleta,auxiliar);


	auxi.idServicio=ObtenerIDservicio();

	aux.isEmpty = OCUPADO;

	rtn=1;

    return rtn;
}


void MostrarTrabajo(eTrabajos listado, int tamT, eBicicleta lista, int tamb)
{


		printf("\n %d-- %5s %5d  %5d %5d/%d/%d \n", lista.idBicicleta,
													lista.marcaBicicleta,
													lista.rodadoBicicleta,
													listado.idServicio,
													listado.fecha.dia,
													listado.fecha.mes,
													listado.fecha.anio);

}



int MostrarTodosLosTrabajos(eTrabajos listado[], int TAM, eBicicleta lista[], int tam)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\nLISTADO DE BICICLETAS\n");
	puts("\nId bici--Marca--Rodado--Id servicio--fecha\n");

	if (listado != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (listado[i].isEmpty == OCUPADO)
			{
				MostrarTrabajo(listado[i], TAM, lista[i], tam);
				//CONTADOR DE trabajo

				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO trabajos PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0)
	{
		rtn = 1;
	}
	return rtn;
}





int Modificacion(eTrabajos producto[],int tam,eServicios servicio[], int tamT, eBicicleta miBicicleta[], int tamB)
{
	int i;
	int id;
	char respuesta;
	char aux[tam];
	int opcion;
	int auxServicio;
	int rtn;

	rtn=0;

	MostrarTodosLosTrabajos(producto, tam, miBicicleta, tamB);
	id=PedirEntero("Ingres el id de su producto: ", "Error! porfavor ingrese un id valido, solo numeros");//funcion donde compare si encontro el id, si lo encuentra 1, sino -1
	id=eBicicleta_BuscarPorID(miBicicleta, tamB, id);

	for(i=0; i<tam; i++)
	{
		if(id==miBicicleta[i].idBicicleta && producto[i].isEmpty==OCUPADO)
		{
			opcion=PedirEnteroRango("Elija una opcion de modificacion: 1-por marca  2-por servicio", "Error, ingrese una pocion valida", 1, 2);

				switch(opcion)
				{
					case 1:
						respuesta=PedirChar("Esta seguro de modificar el producto? s/n", "Error, ingrese una respuesta valida s/n");
						//scanf("%s", &respuesta);
						if(respuesta=='s')
						{
							PedirString("ingrese la marca: lion, bmx, nsz, vox", "error, ingrese una marca valida", aux, 25);
							strcpy(miBicicleta[i].marcaBicicleta,aux);
							printf("Modificacion ejecutada con exito");

						}
						break;

					case 2:
						respuesta=PedirEntero("Esta seguro de modificar el servicio? s/n ", "Error, ingrese una respuiesta valida s/n");
						if(respuesta=='s')
						{
							producto[i].idServicio=PedirEnteroRango("Ingrese el servicio: 1-limpieza, 2-parche 3-centrado 4-cadena", "error,  reingrese un servicio valido" ,1, 4);
							auxServicio=producto[i].idServicio;
							printf("Modificacion ejecutada con exito");
						}
						break;
						rtn=1;
				}
		}
	}

	return rtn;
}





int eTrabajos_BuscarPorID(eTrabajos array[], int TAM, int ID)
{
	int rtn = -1;
	int i;

		for (i = 0; i < TAM; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idBicicleta == ID && array[i].isEmpty == OCUPADO)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}

	return rtn;
}



int eTrabajosBaja(eTrabajos listaa[], int TAM,eBicicleta lista[], int tam) //borrado logico
{
	int rtn = 0;
	int idBicicleta;
	int index;
	int flag = 0;
	char respuesta;


	if (MostrarTodosLosTrabajos(listaa, TAM, lista, tam))
	{
		flag = 1;
	}

	//SI HAY  PARA DAR DE BAJAi
	if (flag)
	{
		//PIDO ID A DAR DE BAJA
		idBicicleta=PedirEntero("ingrese el id de su bicicleta", "Error, porfavor ingrese un id valido");

		//BUSCO INDEX POR ID EN ARRAY
		while (eBicicleta_BuscarPorID(lista, tam, idBicicleta) == -1)
		{
			puts("NO EXISTE ID.");
			idBicicleta = PedirEntero("ingrese el id de su bicicleta", "Error, porfavor ingrese un id valido");
		}
		//aca estoy con id valido
		//OBTENGO INDEX DEL ARRAY  A DAR DE BAJA
		index = eBicicleta_BuscarPorID(lista, tam, idBicicleta);

		respuesta=PedirChar("desea continuar con la baja? s/n", "ingrese una opcion valida");
		if(respuesta=='s')
		{
			printf("baja exitosa");
			listaa[index].isEmpty = BAJA;
			rtn = 1;
		}
	}

	return rtn;
}


//LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad de año por marca de la bicicleta.
void ListarTrabajos(eTrabajos listaTrabajo[],int tam, eServicios listaServicio[],int tamM,eBicicleta miLista[], int tamb)
{

	OrdenarporCriterio(listaTrabajo, tam, miLista, tam);

	printf("    trabajos  --  marca  --  año \n");

	ListadoPorCriterio(listaTrabajo, tam, listaServicio, tamM, miLista, tamb);

}


void ListadoPorCriterio(eTrabajos listaTrabajo[],int tam, eServicios listaServicio[],int tamM, eBicicleta miLista[], int tamb)
{
	int j;

	OrdenarporCriterio(listaTrabajo, tam, miLista, tam);
	for(j=0; j<tam; j++)
	{
	printf(" %5s %5s %10d/%d/%d \n", listaServicio[j].descripcion, miLista[j].marcaBicicleta, listaTrabajo[j].fecha.dia,
												listaTrabajo[j].fecha.mes, listaTrabajo[j].fecha.anio);
	}
}



int OrdenarporCriterio(eTrabajos listado[], int TAM, eBicicleta lista[], int tam)
{
	int rtn=0;
	int i;
	int j;
	int indexBici1;
	int indexBici2;
	eTrabajos auxiliar;

	if(listado != NULL && TAM>0 && lista != NULL && tam>0)
	{
		if (listado != NULL && TAM>0)
		{
			for(i=0;i<TAM-1;i++)//listado trabajos
			{
				indexBici1=eBicicleta_BuscarPorID(lista,tam, listado[i].idBicicleta);//comparo el id de la bicicleta con el de trabajos
				for(j=i+1;j<TAM;j++)
				{
					indexBici2=eBicicleta_BuscarPorID(lista,tam, listado[j].idBicicleta);
					if(listado[i].fecha.anio>listado[j].fecha.anio)//si coinciden en año
					{
						auxiliar=listado[i];
						listado[i]=listado[j];
						listado[j]=auxiliar;

						rtn=1;
					}//sino en marca y anio
					if(listado[i].fecha.anio==listado[j].fecha.anio && strcmp(lista[indexBici1].marcaBicicleta, lista[indexBici2].marcaBicicleta)>0)
					{
						auxiliar=listado[i];
						listado[i]=listado[j];
						listado[j]=auxiliar;

						rtn=2;
					}
				}
			}
		}
	}
	return rtn;
}



int BiciRojaConServicio(eServicios listaServicios[],int tamS,eBicicleta listaBicicletas[], int tamB, eTrabajos lista[], int tam)
{
	int rtn=0;
	int i;
	int j;
	int indexBici;

	int contadorBicicleta=0;

	for(i=0;i<tamS;i++)//recorro servicios
	{
		for(j=0;j<tam;j++)//recorro trabajos
		{
			if(lista[j].idServicio==listaServicios[i].idServicio)//si id trabajo coincide con el de servicios
			{
				indexBici=eBicicleta_BuscarPorID(listaBicicletas, tamB, lista[j].idBicicleta);//busco el id de bici

				//HardcodeoBicicleta(listaBicicletas, tamB);
				if(strcmp(listaBicicletas[indexBici].color,"rojo")==0)// si ihay alguno en la lista de ese color
				{
					contadorBicicleta++;
				}
				rtn=1;
			}
		}
	}

	printf("\n    * La cantidad de bicicletas rojas con un servicio es: %d *  \n", contadorBicicleta);

	return rtn;
}



int ServicioOrdenadoZona(eEntrega listado[], int TAM, eTrabajos lista[], int tam, eServicios listaS[], int tamS)
{
	int rtn = 0;
	int i;
	int j;
	int indexBici1;
	int indexBici2;
	eEntrega auxiliar;

	for(i=0; i<tamS-1; i++)//servicio
	{
		indexBici1=eServicios_BuscarPorID(listaS, TAM, lista[i].idServicio);
		for(j=i+1; j<tamS; j++)
		{
			indexBici2=eServicios_BuscarPorID(listaS, TAM, lista[j].idServicio);

			if(listaS[i].miEntrega.horarioEntregas==listaS[j].miEntrega.horarioEntregas && strcmp(listado[indexBici1].zonaEntrega, listado[indexBici2].zonaEntrega)>0)//comparo silos indices coinciden
			{
					auxiliar = listado[i];
					listado[i] = listado[j];
					listado[j] = auxiliar;
			}
			rtn=1;
		}
	}

	return rtn;
}


void MostrarTrabajosOrdenadosPorZona(eEntrega miEntrega[], int tamE, eServicios listaServicio[],int tamM, eTrabajos lista[], int tam)
{
	int j;

	puts("   - SERVICIO SEGUN ZONA -");
	puts("   - ZONA-- DESCRIPCION--HORARIO -");
	ServicioOrdenadoZona(miEntrega, tamE, lista, tam, listaServicio, tamM);

	for(j=0; j<tamM; j++)
	{
	printf(" %10s %15s %5d \n", miEntrega[j].zonaEntrega,listaServicio[j].descripcion, miEntrega[j].horarioEntregas);
	}
}





#include "eEstructura.h"


void InicializarBicicletas(eBicicleta lista[],int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty = LIBRE;

	}
}


int ObtenerIDbicicleta(void)
{
	int idUnico=24;
	idUnico+=1;

	return idUnico;
}



int BicicletaBuscarLibre(eBicicleta array[], int TAM)
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



void HardcodeoBicicleta(eBicicleta lista[], int tam)
{
	int i;

	int idBicicleta[30]={25,26,27,28,29,30,31,32};
	char marca[100][10]={{"lion"},{"bmx"},{"nsz"},{"vox"},{"vox"},{"lion"},{"bmx"},{"venzo"}};
	int rodadoBicicleta[30]={12,23,26,28,26,24,28,25};
	char color[100][10]={{"rojo"},{"negro"},{"ocre"},{"blanco"},{"verde"},{"rojo"},{"amarillo"},{"cian"}};
	int espacio[50]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};


	for(i=0; i<tam; i++)
	{
		lista[i].idBicicleta=idBicicleta[i];
		strcpy(lista[i].marcaBicicleta,marca[i]);
		lista[i].rodadoBicicleta=rodadoBicicleta[i];
		strcpy(lista[i].color,color[i]);
		lista[i].isEmpty=espacio[i];
	}
}


void MostrarHardcodeoBicicleta(eBicicleta lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		HardcodeoBicicleta(lista, tam);
		printf("%5d  %10s  %d  %s \n", lista[i].idBicicleta, lista[i].marcaBicicleta, lista[i].rodadoBicicleta, lista[i].color);
	}

}


int eBicicleta_BuscarPorID(eBicicleta array[], int TAM, int ID)
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









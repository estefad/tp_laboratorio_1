#include "DataInt.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 1000


int ValidarEntero(char* numero)
{
	int rtn=-1;
	int i;

	if(numero!=NULL)
	{
		for(i=0; i<TAM; i++)
		{
			if(numero[i]<0 || numero[i]>9 || numero[i]=='+' || numero[i]=='-')
			{
				rtn=1;
				//break;
			}
		}
	}

	return rtn;
}


int GetInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max)
{
	int rtn=-1;
	char buffer[TAM];

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]", buffer);
	if(	ValidarEntero(buffer) > 0)
	{
		while(buffer[TAM]<min && buffer[TAM]>max)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
		}
		rtn=1;
	}

	*pResultado = atoi(buffer);


	return rtn;
}




int GetName(char* pResultado, int tam,char* mensaje, char* mensajeError, int reintentos)
{
	char buffer[TAM];
	int rtn = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		if(strnlen(buffer,sizeof(buffer)) < tam )
		{
			strncpy(pResultado,buffer,tam);
			rtn = 0;
			break;
		}
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]", buffer);
	}
	return rtn;
}

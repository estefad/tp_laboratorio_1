#include "Eempleados.h"

void InitEmployees(eEmpleado lista[],int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty = LIBRE;
	}

}


int findFreeSpace(eEmpleado listado[], int TAM)
{
	int index;
	int i;

	index=-1;

	if (listado != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (listado[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				index = i;
				break;
			}
		}
	}
	return index;
}


int ChargeEmployee(eEmpleado lista[], int TAM)
{

	int auxiliar;//EL QUE RETORNO CON LOS DATOS QUE NECESITO SIN ID NI ESTADO


	auxiliar=findFreeSpace(lista, TAM);

	if(auxiliar!=-1) //si es distinto, encontro espacio
	{
		lista[auxiliar]=AddEmployee();
		lista[auxiliar].id=auxiliar+1;
		printf("\n*Dato generado correctamente*\n");
	}
	else
	{
		printf("No hay espacio suficiente!!!");
	}
	return auxiliar;
}



eEmpleado AddEmployee()
{
	eEmpleado aux;
	char nameParameter[MAX_CHARS_CADENAS];

	PedirString(" Ingrese su nombre: ", "Error, solo letras, reingrese nombre: ", nameParameter, MAX_CHARS_CADENAS);
	strcpy(aux.name, nameParameter);
	PedirString(" Ingrese su apellido: ", "Error, solo letras, reingrese apellido: ", nameParameter, MAX_CHARS_CADENAS);
	strcpy(aux.lastName, nameParameter);
	aux.salary=PedirFlotanteSinRango(" Ingrese su salario: ", "Error, solo caracteres numericos, ingrese salario: ");
	aux.sector=PedirEntero(" Ingrese el numero de sector de trabajo: ", "Error, solo numeros, reingrese sector de trabajo: ");
    aux.isEmpty = OCUPADO;

    return aux;

}



int SeeAllEmployees(eEmpleado listado[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\nLISTADO DE EMPLEADOS CARGADOS");
	puts("Id de empelado--Nombre--Apellido--Salario--Sector");

	if (listado!=NULL && TAM>0)
	{
		for (i = 0; i < TAM; i++)
		{

			if (listado[i].isEmpty == OCUPADO)//SI LO PONGO EN OCUPADO, NO ME MUESTRA NADA, Y EN LIBRE BASURA
			{
				SeeEmployees(listado[i]);
				//CONTADOR DE empleados
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



void SeeEmployees(eEmpleado listado)
{
	printf("\n%d %10s %5s %5.2f %5d",listado.id,
									listado.name,
									listado.lastName,
									listado.salary,
									listado.sector);
}


int FindEmployeeById(eEmpleado array[], int TAM, int ID)
{
	int rtn = -1;
	int i;

		for (i = 0; i < TAM; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}

	return rtn;
}


int ModifyEmployees(eEmpleado empleado[],int tam)
{
	int i;
	int idEmployee;
	char auxName[MAX_CHARS_CADENAS];
	char respuesta;
	float auxSalary;
	int auxSector;
	int opcion;
	//int index;
	int rtn;

	rtn=0;

	//SeeHardcode(empleado, tam);
	idEmployee=PedirEntero("Ingres su id de empleado ", "Error! porfavor ingrese un id valido, solo numeros");
	FindEmployeeById(empleado, tam, idEmployee);
	for(i=0; i<tam; i++)
	{
		if(idEmployee==empleado[i].id && empleado[i].isEmpty==OCUPADO)
		{
			do
			{
				opcion=SubMenu();
				switch(opcion)
				{
					case 1:
						respuesta=PedirChar("Esta seguro de modificar el nombre? s/n", "Error, ingrese una respuesta valida s/n");
						if(respuesta=='s')
						{
							PedirString("Ingrese su nombre: \n", "Error, solo letras, ingrese su nombre: \n", auxName, MAX_CHARS_CADENAS);
							strcpy(empleado[i].name, auxName);
							printf("Modificacion ejecutada con exito");
							rtn=1;
						}
						break;

					case 2:
						respuesta=PedirEntero("Esta seguro de modificar el apellido? s/n ", "Error, ingrese una respuiesta valida s/n");
						if(respuesta=='s')
						{
							PedirString("Ingrese su nombre: \n", "Error, solo letras, ingrese su nombre: \n", auxName, MAX_CHARS_CADENAS);
							strcpy(empleado[i].lastName, auxName);
							printf("Modificacion ejecutada con exito");
							rtn=1;
						}
						break;
					case 3:
						respuesta=PedirEntero("Esta seguro de modificar el salario? s/n ", "Error, ingrese una respuiesta valida s/n");
						if(respuesta=='s')
						{
							auxSalary=PedirFlotanteSinRango("Ingrese nuevo salario: \n", "Error, solo numeros, reingrese salario: \n");
							auxSalary=empleado[i].salary;
							printf("Modificacion ejecutada con exito");
							rtn=1;
						}
						break;

					case 4:
						respuesta=PedirEntero("Esta seguro de modificar el sector de trabajo? s/n ", "Error, ingrese una respuiesta valida s/n");
						if(respuesta=='s')
						{
							auxSector=PedirEntero("ingrese su nuevo sector de trabajo", "Error, solo numeros, ingrese numero de sector");
							auxSector=empleado[i].sector;
							printf("Modificacion ejecutada con exito");
							rtn=1;
						}
						break;
				}

			}while(opcion!=5);
		}
		else{
			puts("no existe id, intente nuevamente");
		}
	}

	return rtn;
}




int RemoveEmployee(eEmpleado lista[], int TAM) //borrado logico
{
	int rtn = 0;
	int id;
	int index;
	int flag = 0;
	char respuesta;


	if (SeeAllEmployees(lista, TAM))
	{
		flag = 1;
	}
	if (flag)
	{
		flag=SeeAllEmployees(lista, TAM);
		id=PedirEntero("ingrese su id de empleado", "Error, porfavor ingrese un id valido");

		//BUSCO INDEX POR ID EN ARRAY
		while (FindEmployeeById(lista, TAM, id) == -1)
		{
			puts("NO EXISTE ID.");
			id = PedirEntero("ingrese su id de empleado", "Error, porfavor ingrese un id valido");
		}
		//aca estoy con id valido
		//OBTENGO INDEX DEL ARRAY A DAR DE BAJA
		index = FindEmployeeById(lista, TAM, id);
		respuesta=PedirChar("desea continuar con la baja? s/n", "ingrese una opcion valida");
		if(respuesta=='s')
		{
			printf("baja exitosa");
			lista[index].isEmpty = BAJA;
			rtn = 1;
		}
	}

	return rtn;
}

//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.

void SeeSortEmployees(eEmpleado lista[],int tam, int criterio)
{
	int j;

	SortEmployees(lista, tam, criterio);
	puts("Apellido--Sector");
	for(j=0; j<tam; j++)
	{
	printf(" %5d %5s \n", lista[j].sector, lista[j].lastName);
	}
}




int SortEmployees(eEmpleado lista[], int TAM, int criterio)
{
	criterio = 0;
	int i;
	int j;
	eEmpleado auxiliar;

	if(TAM > 0)
	{
		//de menor a mayor
			for(i=0; i<TAM-1; i++)//trabajo
			{
				for(j=i+1; j<TAM; j++)
				{
					if (lista[i].id==OCUPADO && lista[j].id==OCUPADO)
					{
						if(lista[i].sector<lista[j].sector)//por sector
						{
							auxiliar = lista[i];
							lista[i] = lista[j];
							lista[j] = auxiliar;
						}
						else
						{
							if(lista[i].sector==lista[j].sector&&strcmp(lista[i].lastName , lista[j].lastName)>0)//por sector y apellido
							{
								auxiliar = lista[i];
								lista[i] = lista[j];
								lista[j] = auxiliar;
							}
						}
					}
					criterio=1;
				}
			}
	}

	return criterio;
}



void HardcodeEmployee(eEmpleado lista[], int tam)
{
	int i;

	 int id[100]={1,2,3,4};
	 char name[MAX_CHARS_CADENAS][5]={{"mario"},{"bera"},{"ana"},{"juan"}};
	 char lastName[MAX_CHARS_CADENAS][4]={{"B"},{"S"},{"E"},{"F"}};
	 float salary[100]={25000,1236,5489,3256};
	 int sector[]={5,2,5,3};

	for(i=0; i<tam; i++)
	{

		lista[i].id=id[i];
		strcpy(lista[i].name, name[i]);
		strcpy(lista[i].lastName, lastName[i]);
		lista[i].salary=salary[i];
		lista[i].sector=sector[i];
	}
}


void SeeHardcode(eEmpleado lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		HardcodeEmployee(lista, tam);
		printf("%5d %10s %10s %5.2f %d \n", lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector);
	}

}

//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.


void TotalAverageSalary(eEmpleado lista[], int tam)
{

	int i;
	int j;
	float acumuladorSalary;
	float promedioSalary;
	int contadorEmpleados;
	int contadorSalario;
	acumuladorSalary=0;
	contadorEmpleados=0;
	contadorSalario=0;

	//SeeHardcode(lista, tam);
	puts("--Total salarios--Promedio salarios\n");

	for(i=0; i<tam; i++)
	{
		for(j=0; j<tam; j++)
		{
			if(lista[i].id==lista[j].id)
			{
				if(lista[i].salary!=0)
				{
					contadorSalario++;
					acumuladorSalary=acumuladorSalary+lista[i].salary;
					promedioSalary=acumuladorSalary/contadorSalario;

					printf("%5.2f--%5.2f\n" ,acumuladorSalary, promedioSalary);
				}
				if(promedioSalary<lista[i].salary)
				{
					contadorEmpleados++;
					printf("Empleados por encima del salario promedio: %d", contadorEmpleados);
				}
			}
		}
	}
}






int SubMenu()
{
	int opcion;


	printf("  *[SUB MENU]*\n");

	printf("  .1.MODIFICAR NOMBRE\n");
	printf("  .2.MODIFICAR APELLIDO\n");
	printf("  .3.MODIFICAR SALARIO\n");
	printf("  .4.MODIFICAR SECTOR\n");
	printf("  .5.SALIR\n");
	fflush(stdin);
	opcion=PedirEnteroRango("-Ingrese una opcion del MENU-\n", "-ERROR, ingrese una opcion valida-\n", 1, 5);

	return opcion;
}

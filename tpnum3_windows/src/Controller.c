#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include"parser.h"
#include"DataInt.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pLista;
	int rtn=-1;

	if(pArrayListEmployee!=NULL)
	{
		pLista=fopen(path, "r");

		if(pLista!=NULL)
		{
			//employee_new();
			rtn=parser_EmployeeFromText(pLista, pArrayListEmployee);
			fclose(pLista);
		}
	}

	return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pLista;
	Employee* miEmployee;
	int rtn=-1;


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pLista=fopen(path, "rb");
		fwrite(&miEmployee,sizeof(Employee),1,pLista);
		miEmployee=employee_new();
		rtn=parser_EmployeeFromBinary(pLista, pArrayListEmployee);
		fclose(pLista);
	}
	else
	{
		rtn=0;
	}
	return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1;
    Employee* aux;
    char auxNombre[128];
    int auxHorasTrabajadas;
	int auxSalario;
	int auxId;

	aux=(Employee*)employee_new();
	auxId=ll_len(pArrayListEmployee)+1;

	if(aux!=NULL)
	{
		//PIDO DATOS
		GetName(auxNombre, 128, "Ingrese su nombre: \n", "Error, reingrese su nombre: \n", 5);
		GetInt(&auxHorasTrabajadas,"\nIngrese la cantidad de hs trabajadas: \n" , "Error, ingrese una cantidad valida: \n", 1, 150);
		GetInt(&auxSalario, "\ningrese su salario: \n", "Error, ingrese correctamente su salario: \n", 5000,100000);

		if(employee_setId(aux, auxId) && employee_setNombre(aux, auxNombre )&&
		   employee_setHorasTrabajadas(aux, auxHorasTrabajadas) && employee_setSueldo(aux, auxSalario))
		{
			ll_add(pArrayListEmployee, aux);
			//aux=employee_newParametros(&auxId, auxNombre, &auxHorasTrabajadas, &auxSalario);
			puts("Alta exitosa!");
			rtn=1;
		}
	}
	return rtn;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int opcion;
	int idAux;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int i;
	int len;
	//char respuesta[1];
	Employee* myEmployee;

	if(pArrayListEmployee != NULL)
	{
		if(GetInt(&idAux, "Ingrese el id del empleado a modificar", "Error, ingrese un id valido", 1, 5000) && idAux<= ll_len(pArrayListEmployee))
		{
			len=ll_len(pArrayListEmployee);
			for(i=0; i<len; i++)
			{
				myEmployee=(Employee*)ll_get(pArrayListEmployee, i);//pido que me busque el empleado segun el id
				if(employee_getId(myEmployee, idAux))
				{
					employee_showEmployee(myEmployee);//lo muestro si existe
					break;
				}
			}

			do{
				GetInt(&opcion, "ingrese un opcion del menu\n 1.Modificar nombre\n 2.Modificar hs trabajadas\n 3.Modificar sueldo\n 4.SALIR\n", "Error, ingrese una opcion correcta", 1, 4);
				switch(opcion)
				{
					case 1:
						GetName(nombre, 128, "ingrese el nombre modificado: ", "Error, ingrese correctamente el nombre", 1);

						employee_setNombre(myEmployee,nombre);
						printf("Nombre modificado \n");
						rtn=1;
						break;
					case 2:
						GetInt(&horasTrabajadas, "ingrese las horas trabajadas: ", "Error, ingrese correctamente las hs", 1, 150);

						employee_setHorasTrabajadas(myEmployee,horasTrabajadas);
						printf("Horas trabajadas modificadas \n");
						rtn=1;
						break;
					case 3:
						GetInt(&sueldo, "ingrese el sueldo modificado: ", "Error, ingrese una cantidad valida", 5000, 100000);

						employee_setSueldo(myEmployee,sueldo);
						printf("Sueldo modificado\n");
						rtn=1;
						break;
					case 4:
						printf("\n*SALIDA DEL MENU MODIFICACIONES*\n");
						break;
				}
			}while(opcion!=4);
		}


	}
    return rtn;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int i;
	int idAux;
	char remove;
	int len;
	Employee* myEmployee;

	if(pArrayListEmployee != NULL)
	{
		if(GetInt(&idAux, "Ingrese el id del empleado a modificar", "Error, ingrese un id valido", 1, 5000) && idAux<= ll_len(pArrayListEmployee))
		{
			len=ll_len(pArrayListEmployee);
			for(i=0; i<len; i++)
			{
				myEmployee=(Employee*)ll_get(pArrayListEmployee, i);//pido que me busque el empleado segun el id
				if((myEmployee->id=idAux))
				{
					printf("Esta seguro de eliminar? s/n: ");
					fflush(stdin);
					scanf("%s", remove);
					if(remove=='s')
					{
						if(ll_pop(pArrayListEmployee, i))
						{
							employee_delete(myEmployee);
							puts("Empleado eliminado");
							rtn=1;
						}
					}
				}
				else
				{
					puts("El empleado no existe");
					rtn=0;
				}
			}
		}
	}
    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=0;
	int lenEmployee;
	Employee* aux;

	int i;

	printf("    ID -- NOMBRE -- HS -- SUELDO \n");
	printf("  *                              *\n");

	if(pArrayListEmployee!=NULL)
	{
		lenEmployee=ll_len(pArrayListEmployee);

		for(i=0; i<lenEmployee; i++)
		{
			aux=(Employee*)ll_get(pArrayListEmployee, i);//casteo
			employee_showEmployee(aux);

		}
		rtn=1;
	}

	return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int opcion;
	Employee* employee1;
	Employee* employee2;

	if(pArrayListEmployee!=NULL)
	{
		GetInt(&opcion, "Ingrese una opcion de ordenamiento: 0-Ascendente\n 1-Descendente\n 2-SALIR\n", "Error, reintente", 1, 2);
		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListEmployee, employee_CompareByName(employee1, employee2), 0);
				rtn=1;
				break;
			case 2:
				ll_sort(pArrayListEmployee, employee_CompareByName(employee1, employee2), 1);
				rtn=1;
				break;
			case 3:
				puts("SALIENDO..");
				break;
		}
	}
	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* aux;
    int rtn=-1;
    int i;
    int len;

    int id;
    char name[50];
    int horasTrabajadas;
    int salary;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        pFile=fopen(path, "w");
    	len=ll_len(pArrayListEmployee);

    	if(pFile!=NULL)
    	{
    		for(i=0; i<len; i++)
    		{
    			aux=(Employee*)ll_get(pArrayListEmployee, i);//retorna cada empleado de la lista que va leyendo
    			employee_getId(aux, &id);
    			employee_getNombre(aux, name);
    			employee_getHorasTrabajadas(aux, &horasTrabajadas);
    			employee_getSueldo(aux, &salary);

    			fprintf(pFile," %d--%s--%d--%d ", id, name, horasTrabajadas, salary);//guarda en el archivo
    			rtn=1;
    		}
    	}
    	fclose(pFile);
    }

	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* aux;
	int rtn=-1;
	int i;
	int len;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pFile=fopen(path, "wb");
		len=ll_len(pArrayListEmployee);

		if(pFile!=NULL)
		{
			for(i=0; i<len; i++)
			{
				aux=(Employee*)ll_get(pArrayListEmployee, i);
				fwrite(aux, sizeof(Employee),1, pFile);
				rtn=1;
			}
		}
		fclose(pFile);
	}


    return rtn;
}



int controller_searchById(LinkedList* this, int id)
{

}

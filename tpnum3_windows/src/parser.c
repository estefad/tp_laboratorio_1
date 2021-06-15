#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn;
	Employee* aux;

	char idStr[50];
	char nombreStr[128];
	char horasTrabajadasStr[100];
	char sueldoStr[50];

	rtn=-1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
		do
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
			aux=employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);//crea el empleado con los datos
			//validar que no sea null
			ll_add(pArrayListEmployee, aux);//genero la lsita de empleados
			rtn=1;;

		}while(!feof(pFile));//leo los datos mientras no sea el fin del archivo

	}

	else
	{
		rtn=0;
	}

		return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	Employee* aux;

	if(pFile != NULL)
	{
		do
		{
			aux = employee_new(); //reservo lugar para un empleado
			if(fread(aux, sizeof(Employee), 1, pFile)==1)
			{
				ll_add(pArrayListEmployee, aux);
				rtn=1;
			}
		}while(!feof(pFile));
	}


    return rtn;
}

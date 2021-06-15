#include "Employee.h"
#define MAX_ID 5000

Employee* employee_new()//buscar libre espacio en memoria
{
	Employee* aux;

	aux=(Employee*)calloc(sizeof(Employee),1);

	return aux;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* miEmployee;
	miEmployee= employee_new();

	if(miEmployee!=NULL)
	{
		if(employee_setId(miEmployee, atoi(idStr)) &&
		employee_setNombre(miEmployee, nombreStr)&&
		employee_setHorasTrabajadas(miEmployee, atoi(horasTrabajadasStr))&&
		employee_setSueldo(miEmployee, atoi(sueldoStr)))
		{
			return miEmployee;
		}
	}
//pasar a los set los atoi o guarda y pasarle las var a los set
	return miEmployee;
}

//liberar memoria-lo que ingrese como parametro
void employee_delete(Employee* miEmployee)
{
	free(miEmployee);
}


int employee_setId(Employee* this,int id)//asigna un valor
{
	int rtn=0;
	if(this!=NULL)
	{
		this->id=id;
		rtn=1;
	}
	return rtn;
}


int employee_getId(Employee* this,int* id)//devuelve el valor de id
{
	int rtn=0;
	if(this!=NULL)
	{
		*id=this->id;
		rtn=1;
	}
	return rtn;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int rtn=0;
	if(this!=NULL)
	{
		strcpy(this->nombre, nombre);
		rtn=1;
	}
	return rtn;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int rtn=0;
	if(this!=NULL)
	{
		nombre=strcpy(this->nombre, nombre);
		rtn=1;
	}
	return rtn;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn=0;
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		rtn=1;
	}
	return rtn;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn=0;
	if(this!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		rtn=1;
	}
	return rtn;
}


int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn=0;
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		rtn=1;
	}
	return rtn;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn=0;
	if(this!=NULL)
	{
		*sueldo=this->sueldo;
		rtn=1;
	}
	return rtn;
}


int employee_showEmployee(Employee* miEmployee)
{
	int rtn=-1;

	if(miEmployee!=NULL)
	{
		printf("%5d--%10s--%5d--%5d\n", miEmployee->id, miEmployee->nombre, miEmployee->horasTrabajadas, miEmployee->sueldo);//usar get
		rtn=1;
	}
	return rtn;
}



int employee_CompareByName(void* e1, void* e2)//generico
{
	int compare;
//de generico a particular, casteo los empleados
	Employee* emp1;
	Employee* emp2;
	emp1=(Employee*)e1;//casteo
	emp1=(Employee*)e2;

//comparo la entrada de nombre
	if(emp1!=NULL && emp2!=NULL)
	{
		compare=strcmp(emp1->nombre, emp2->nombre);
	}
	return compare;
}


int employee_CompareById(void* e1, void* e2)
{
	int comp=-1;

	Employee* emp1;
	Employee* emp2;
	emp1=(Employee*)e1;//casteo
	emp1=(Employee*)e2;

//comparo con funcion get id y despues if
	if(employee_getId(emp1, e1) && employee_getId(emp2, e2))
	{
		if(emp1->id > emp2->id)
		{
			comp=1;
		}
		else
		{
			if(emp1->id < emp2->id)
			{
				comp=0;
			}
		}
	}
	return comp;
}




int employee_Menu()
{
	int opcion;

	printf("*      ------------------------      *\n");
	printf("*[BIENVENIDO AL SISTEMA DE EMPLEADOS]*\n");
	printf("*      ------------------------      *\n");
	printf(".1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf(".2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf(".3. Alta de empleado\n");
	printf(".4. Modificar datos de empleado\n");
	printf(".5. Baja de empleado\n");
	printf(".6. Listar empleados\n");
	printf(".7. Ordenar empleados\n");
	printf(".8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf(".9. Guardar los datos de los empleados en el archivo data.csv (modo binario). \n");
	printf(".10. SALIR \n");


	opcion=PedirEnteroRango("-Ingrese una opcion del MENU-", "-ERROR, ingrese una opcion valida-", 1, 10);

	return opcion;
}

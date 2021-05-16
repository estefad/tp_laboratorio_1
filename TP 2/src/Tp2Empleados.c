#include "Eempleados.h"

#define TAME 4

int main(void)
{

	setbuf(stdout, NULL);

	int opcion;
	eEmpleado listaEmpleados[TAME];
	int criteriOrdenamioento;
	int cargaDatos;
	int flag;
	flag=0;


	InitEmployees(listaEmpleados, TAME);

	do
	{
		opcion=MenuGen();


		switch(opcion)
		{
			case 1:
				//ALTA
				cargaDatos=ChargeEmployee(listaEmpleados, TAME);
				flag=1;
				//SeeAllEmployees(listaEmpleados, TAME);
				break;

			case 2:
				//MODIFICACION
				if(flag)
				{
					SeeAllEmployees(listaEmpleados, TAME);
					ModifyEmployees(listaEmpleados, TAME);
				}
				else
				{
					puts("no se puede ingresar sin datos cargados");
				}
				break;

			case 3:
				//BAJA
				if(flag)
				{
					RemoveEmployee(listaEmpleados, TAME);
				}
				break;

			case 4:
				//LISTADO
				criteriOrdenamioento=1;
				SeeSortEmployees(listaEmpleados, TAME , criteriOrdenamioento);
				break;

			case 5:
				//LISTADO
				if(ChargeEmployee(listaEmpleados, TAME)==0)
				{
					puts("no hay datos para esta opcion");
				}
				else
				{
					TotalAverageSalary(listaEmpleados, TAME);
				}
				break;

			case 6:
				puts("\n*[...SALIENDO DEL MENU EMPLEADOS...]*");
				system("pause");
				break;
		}

	}while(opcion!=6);


	return EXIT_SUCCESS;
}

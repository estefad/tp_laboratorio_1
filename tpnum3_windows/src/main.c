#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int lenEmployee;
    //int lastId;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
      		option=employee_Menu();

      		switch(option)
      		{
      			case 1://*Charge file as text*
      				lenEmployee=controller_loadFromText("data.csv",listaEmpleados);
					if(lenEmployee!=0)
					{
						printf("se cargaron los Empleados al sistema\n");
						//printf("len= %d", lenEmployee);
					}
					else
					{
						puts("El directorio no existe\n");
					}
      				break;

      			case 2://*Charge file as binary*
					if(controller_loadFromBinary("data.bin", listaEmpleados)!=0)
					{
						printf("se cargaron los Empleados en el archivo binario\n");
					}
					else
					{
						puts("El directorio no existe\n");
					}
      				break;

      			case 3://*Add employee*
      				controller_addEmployee(listaEmpleados);
      				if(listaEmpleados==0)
      				{
      					puts("Error al dar de alta\n");
      				}
      				break;

      			case 4://*Edit employee*
      				controller_editEmployee(listaEmpleados);
      				break;

      			case 5://*Remove employee*
      				controller_removeEmployee(listaEmpleados);
      				break;

      			case 6://*List employee*
      				controller_ListEmployee(listaEmpleados);
      				break;

      			case 7://*Sort by name*
      				lenEmployee=controller_sortEmployee(listaEmpleados);
      				if(lenEmployee!=0)
      				{
      					puts("ordenamiento finalizado con exito");
      				}
      				else
      				{
      					puts("no se ha podido completar el sort");
      				}
      				break;

      			case 8://*Save as text*
      				lenEmployee=controller_saveAsText("data.csv", listaEmpleados);
					if(lenEmployee!=0)
					{
						printf("se guardaron todo Empleados al sistema\n");
					}
					else
					{
						puts("Error al guardar directorio");
					}
      				break;

      			case 9://*Save as binary*
      				lenEmployee=controller_saveAsBinary("data.bin", listaEmpleados);
					if(lenEmployee!=0)
					{
						printf("se guardaron todo Empleados al archivo binario\n");
					}
					else
					{
						puts("Error al guardar directorio");
					}
      				break;

      			case 10:
      				puts("\n*[...SALIENDO DEL SISTEMA DE EMPLEADOS...]*");
      				system("pause");
      				break;
      		}
      	}while(option!=10);
    return 0;
}

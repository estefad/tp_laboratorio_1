

#ifndef EEMPLEADOS_H_
#define EEMPLEADOS_H_

#include <stdio.h>
#include <stdlib.h>
#include "ValidaCorregido.h"

#define MAX_CHARS_CADENAS 51
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int id;
	char name[MAX_CHARS_CADENAS];
	char lastName[MAX_CHARS_CADENAS];
	float salary;
	int sector;
	int isEmpty;

}eEmpleado;

void InitEmployees(eEmpleado lista[],int tam);//inicializa en libre todos las posciciones del array de empleados
int findFreeSpace(eEmpleado array[], int TAM);//busca espacio libre

int ChargeEmployee(eEmpleado array[], int TAM);//busca espacio libre y si encuentra pide carga datos del alta
eEmpleado AddEmployee();//toma de datos
void SeeEmployees(eEmpleado listado);//muestra un empleado
int SeeAllEmployees(eEmpleado listado[], int TAM);//muestra lista de empleados

int FindEmployeeById(eEmpleado array[], int TAM, int ID);//buscar id de empleado
int ModifyEmployees(eEmpleado producto[],int tam);//modificacion por id

int RemoveEmployee(eEmpleado array[], int TAM);//Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.

int SortEmployees(eEmpleado lista[], int TAM, int criterio);//lista de empleados ordenados por apellido y sector
void SeeSortEmployees(eEmpleado lista[],int tam, int criterio);//mostrar lista

void HardcodeEmployee(eEmpleado lista[], int tam);
void SeeHardcode(eEmpleado lista[], int tam);

void TotalAverageSalary(eEmpleado lista[], int tam);// Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
int SubMenu();


#endif /* EEMPLEADOS_H_ */

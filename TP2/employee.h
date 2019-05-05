#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include"utn.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>

typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employees;

int initEmployees(Employees* empleado,int length,int valor);
int getAlgunaAlta(Employees* empleado,int length);
int getIndiceVacio(Employees* empleado,int length);
int addEmployee(Employees* empleado,int length,int index);
int findEmployeeById(Employees* empleado,int length,int id);
int removeEmployeeById(Employees* empleado,int length,int index);
int modificarEmployee(Employees* empleado,int length,int index);
int sortEmployeesByLastName(Employees* empleado,int length,int valor);
int quick_sortLastname(Employees*empleado,int limite_izq,int limite_der);
int quick_sortSector(Employees*empleado,int limite_izq,int limite_der);
void qsLastname(Employees* empleado,int length);
void qsSector(Employees* empleado,int length);
int printEmployees(Employees* empleado,int length);
int totalSalarios(Employees* empleado,int length,float* sumaSalario,float* promedio);
int empleadosSuperaPromedio(Employees* empleado,int length,float* promedio,int* empleadosSP);
int setEmployees(Employees*empleado,int index,char*nombre,char*apellido,float salario,int sector);
void menuEmployees(void);

#endif // EMPLOYEE_H_INCLUDED

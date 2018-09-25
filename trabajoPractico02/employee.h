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
int getIndiceVacio(Employees* empleado,int length);
int getAnyAlta(Employees* empleado,int length);
int addEmployee(Employees* empleado,int length);
int findEmployeeById(Employees* empleado,int length);
int removeEmployeeById(Employees* empleado,int length,int id);
int modificarEmployee(Employees* empleado,int length);
int sortEmployeesByLastName(Employees* empleado,int length,int valor);
int printEmployees(Employees* empleado,int length);
int totalSalarios(Employees* empleado,int length,float* sumaSalario,float* promedio);
int empleadosSuperaPromedio(Employees* empleado,int length,float promedio,int* empleadosSP);


#endif // EMPLOYEE_H_INCLUDED

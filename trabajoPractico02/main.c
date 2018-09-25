#include <stdio.h>
#include <stdlib.h>
#include"utn.h"
#include"employee.h"
#include<string.h>
#include<stdio_ext.h>
#define QTY_EMPLEADOS 5
void menuEmployees(void);

int main()
{
    __fpurge(stdin);
    float alta=0;
    float promedio;
    int cantidadEmple;
    Employees empleado[QTY_EMPLEADOS];
    menuEmployees();
    return 0;
}

void menuEmployees(void)
{
    Employees empleado[QTY_EMPLEADOS];
    initEmployees(empleado,QTY_EMPLEADOS,1);
    int opcion;
    int index;
    do
    {
        printf("ALTA DE EMPLEADO (1) \nBAJA DE EMPLEADO (2)\nMODIFICACION DE EMPLEADO (3)\nINFORMES (4)\nSALIR (5)");
        utn_getEntero(&opcion,1,"INGRESE OPCION: ","ERROR",1,5);
        system("clear");
        switch(opcion)
        {
            case 1:
                addEmployee(empleado,QTY_EMPLEADOS);
                break;
            case 2:
                removeEmployeeById(empleado,QTY_EMPLEADOS,findEmployeeById(empleado,QTY_EMPLEADOS));
                break;
            case 3:
                modificarEmployee(empleado,QTY_EMPLEADOS);
                break;
            case 4:
                printEmployees(empleado,QTY_EMPLEADOS);
                break;
            default:
                break;

        }

    }while(opcion!=5);
}

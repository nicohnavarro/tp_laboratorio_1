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
    menuEmployees();
    return 0;
}

void menuEmployees(void)
{
    Employees empleado[QTY_EMPLEADOS];
    initEmployees(empleado,QTY_EMPLEADOS,1);
    int index;
    int auxId;
    int opcion;
    int opcionInfo;
    float sumaSalario;
    float promedio;
    int empleadosSP;
    do
    {
        printf("ALTA DE EMPLEADO (1) \nMODIFICACION DE EMPLEADO (2)\nBAJA DE EMPLEADO (3)\nINFORMES (4)\nSALIR (5)");
        utn_getEntero(&opcion,1,"INGRESE OPCION: ","ERROR",1,5);
        system("clear");
        switch(opcion)
        {
            case 1:
                index=getIndiceVacio(empleado,QTY_EMPLEADOS);
                addEmployee(empleado,QTY_EMPLEADOS,index);
                break;
            case 2:
                if(getAlgunaAlta(empleado,QTY_EMPLEADOS))
                {
                    printf("No hay Altas.\n");
                    break;
                }
                utn_getEntero(&auxId,2,"Ingrese el ID a Modificar ","Error",0,QTY_EMPLEADOS);
                index=findEmployeeById(empleado,QTY_EMPLEADOS,auxId);
                if(index!=-1)
                {
                    modificarEmployee(empleado,QTY_EMPLEADOS,index);
                }
                else
                {
                    printf("No se encontro id.\n");
                }

                break;
            case 3:
                if(getAlgunaAlta(empleado,QTY_EMPLEADOS))
                {
                    printf("No hay Altas.\n");
                    break;
                }
                utn_getEntero(&auxId,2,"Ingrese el ID a Borrar ","Error",0,QTY_EMPLEADOS);
                index=findEmployeeById(empleado,QTY_EMPLEADOS,auxId);
                if(index!=-1)
                {
                    removeEmployeeById(empleado,QTY_EMPLEADOS,index);
                }
                else
                {
                    printf("No se encontro id.\n");
                }
                break;
            case 4:
                if(getAlgunaAlta(empleado,QTY_EMPLEADOS))
                {
                    printf("No hay Altas.\n");
                    break;
                }
                system("clear");
                printf("INFORMES\n(1)Listar Empleados por Apellido y Sector\n(2)Total,Promedio Salario-Cantidad de Empleados que superan el Promedio\n(3)ATRAS...");
                do
                {
                    if(utn_getEntero(&opcionInfo,1,"Ingrese opcion: ","Error",1,3)==0)
                    {
                        switch(opcionInfo)
                        {
                            case 1:
                                qsLastname(empleado,QTY_EMPLEADOS);
                                printf("POR APELLIDO \n");
                                printEmployees(empleado,QTY_EMPLEADOS);
                                qsSector(empleado,QTY_EMPLEADOS);
                                printf("POR SECTOR \n");
                                printEmployees(empleado,QTY_EMPLEADOS);
                                printf("\n\n");
                                break;
                            case 2:
                                __fpurge(stdin);
                                sumaSalario=0;
                                promedio=0;
                                empleadosSP=0;
                                totalSalarios(empleado,QTY_EMPLEADOS,&sumaSalario,&promedio);
                                empleadosSuperaPromedio(empleado,QTY_EMPLEADOS,&promedio,&empleadosSP);
                                printf("El Total de los Salarios es: $%.2f\nEl promedio es: $%.2f\nLa cantidad de EMPLEADOS que supera el Promedio es [%d]\n",sumaSalario,promedio,empleadosSP);
                                break;
                            default:
                                break;
                        }
                    }
                }while(opcionInfo!=3);
                system("clear");
                break;
            default:
                break;
        }
    }while(opcion!=5);
}

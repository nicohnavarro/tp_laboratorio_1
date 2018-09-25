#include"utn.h"
#include"employee.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>

static int generarID(void);

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}

int initEmployees(Employees* empleado,int length,int valor)
{
    int i;
    int retorno=-1;
    if(empleado!=NULL && length>0)
    {
        for (i=0;i<length;i++)
        {
            empleado[i].isEmpty=valor;
            retorno=0;
        }
    }

    return retorno;
}

int getIndiceVacio(Employees* empleado,int length)
{
    int i;
    int retorno=-1;
    for(i=0;i<length;i++)
    {
        if(empleado[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int getAnyAlta(Employees* empleado,int length)
{
    int retorno=-1;
    int i;
    if(empleado!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(empleado[i].isEmpty==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int addEmployee(Employees* empleado,int length)
{
    int retorno=-1;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int index;
    index=getIndiceVacio(empleado,length);
    if(index<length)
    {
        if(utn_getLetras(auxName,51,2,"INGRESE NOMBRE DEL EMPLEADO: ","ERROR DE NOMBRE.")==0)
        {
            if(utn_getLetras(auxLastName,51,2,"INGRESE APELLIDO DEL EMPLEADO: ","ERROR DE APELLIDO.")==0)
            {
                if(utn_getFloat(&auxSalary,2,"INGRESE SALARIO DEL EMPLEADO: ","ERROR DE SALARIO.",0,120000)==0)
                {
                    if(!utn_getEntero(&auxSector,2,"INGRESE SECTOR DE PERTENECIA: ","ERROR DE SECTOR.",0,5))
                    {
                        strncpy(empleado[index].name,auxName,51);
                        strncpy(empleado[index].lastName,auxLastName,51);
                        empleado[index].salary=auxSalary;
                        empleado[index].sector=auxSector;
                        empleado[index].isEmpty=0;
                        empleado[index].id=generarID();
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

int findEmployeeById(Employees* empleado,int length)
{
    int i;
    int retorno=-1;
    int auxId;
    if(empleado!=NULL && length>0)
    {
        if(getAnyAlta(empleado,length)==0)
        {
            if(utn_getEntero(&auxId,2,"INGRESE EL ID DEL EMPLEADO QUE BUSCA: ","ERROR DE ID.",0,length)==0 )
            {
                for(i=0;i<length;i++)
                {
                    if(empleado[i].id==auxId && empleado[i].isEmpty==0)
                    {
                        retorno=i;
                        break;
                    }
                    else
                        retorno=-1;
                }
            }
        }
    }
    return retorno;
}

int removeEmployeeById(Employees* empleado,int length,int id)
{
    int i;
    int retorno=-1;
    if(id!=-1)
    {
        for(i=0;i<length;i++)
        {
            if(empleado[i].id==id && empleado[i].isEmpty==0)
            {
                empleado[i].isEmpty=1;
                retorno=0;
                printf("EL EMPLEADO DE ID : [%d] HA SIDO DADO DE BAJA.\n",i);
                break;
            }
        }
    }
    else
        printf("NO HAY EMPLEADOS DADOS DE ALTA.\n");

    return retorno;
}

int modificarEmployee(Employees* empleado,int length)
{
    int index;
    int retorno=-1;
    int opcion;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
    index=findEmployeeById(empleado,length);
    if(index==-1)
    {
        printf("NO HAY EMPLEADOS DADOS DE ALTA.\n");

    }
    else
    {
        printf("Que desea modificar del Empleado ID[%d]\n",empleado[index].id);
        printf("NOMBRE (1)\nAPELLIDO (2)\nSALARIO(3)\nSECTOR(4)");
        utn_getEntero(&opcion,2,"INGRESE OPCION: ","ERROR",1,4);
        switch(opcion)
        {
            case 1:if(utn_getLetras(auxNombre,51,2,"Ingrese Nuevo Nombre: ","Error")==0)
                    {
                        strcpy(empleado[index].name,auxNombre);
                        retorno=0;
                    }
                    break;
            case 2:if(utn_getLetras(auxApellido,51,2,"Ingrese Nuevo Apellido: ","Error")==0)
                    {
                        strcpy(empleado[index].lastName,auxApellido);
                        retorno=0;
                    }
                    break;
            case 3:if(utn_getFloat(&auxSalario,2,"ingrese Nuevo Salario: $","Error",0,120000)==0)
                    {
                        empleado[index].salary=auxSalario;
                        retorno=0;
                    }
                    break;
            case 4:if(utn_getEntero(&auxSector,2,"Ingrese Nuevo Sector: ","Error",0,5)==0)
                    {
                        empleado[index].sector=auxSector;
                        retorno=0;
                    }
                    break;
            default:
                    break;
        }
    }
    return retorno;
}

int sortEmployeesByLastName(Employees* empleado,int length,int valor)
{
    int i;
    int j;
    int retorno=-1;
    char auxLastName[51];
    for(i=1;i<length;i++)
    {
        strcpy(auxLastName,empleado[i].lastName);
        j=i-1;
        while(j>=0 && (strcmp(auxLastName,empleado[j].lastName)<0))
        {
            strcpy(empleado[j+1].lastName,empleado[j].lastName);
            j--;
        }
        strcpy(empleado[j+1].lastName,auxLastName); //insertion
    retorno=0;
    }
    return retorno;
}

int printEmployees(Employees* empleado,int length)
{
    int retorno=-1;
    int i;
    if(empleado!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(empleado[i].isEmpty==0)
            {
                printf("Nombre: %s\tApellido: %s\tSalario: $%.2f\tSector nro[%d]\tID[%d]\n",empleado[i].name,empleado[i].lastName,empleado[i].salary,empleado[i].sector,empleado[i].id);
                retorno=0;
            }

        }
    }
    return retorno;
}
int totalSalarios(Employees* empleado,int length,float* sumaSalario,float* promedio)
{
    int retorno=-1;
    int i;
    int contadorEmpleados=0;
    float auxSumaSalarios;
    for(i=0;i<length;i++)
    {
        if(empleado[i].isEmpty==0)
        {
            contadorEmpleados++;
            auxSumaSalarios+=empleado[i].salary;
            retorno=0;
        }

    }
    *sumaSalario=auxSumaSalarios;
    *promedio=auxSumaSalarios/contadorEmpleados;
    return retorno;
}

int empleadosSuperaPromedio(Employees* empleado,int length,float promedio,int* empleadosSP)
{
    int retorno=-1;
    int i;
    int cantidadEmpleados=0;
    if(empleado!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(empleado[i].isEmpty==0)
            {
                if(empleado[i].salary>promedio)
                {
                    cantidadEmpleados++;
                    retorno=0;
                }
            }
        }
    }
    *empleadosSP=cantidadEmpleados;
    return retorno;
}

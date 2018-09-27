#include"utn.h"
#include"employee.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#define QTY_EMPLEADOS 10

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

int getAlgunaAlta(Employees* empleado,int length)
{
    int i;
    int retorno=-1;
    for(i=0;i<length;i++)
    {
        if(empleado[i].isEmpty==0)
        {
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

int addEmployee(Employees* empleado,int length,int index)
{
    int retorno=-1;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
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

int findEmployeeById(Employees* empleado,int length,int id)
{
    int i;
    int retorno=-1;
    if(empleado!=NULL && length>0)
    {
            for(i=0;i<length;i++)
            {
                if(empleado[i].isEmpty==0 && empleado[i].id==id)
                {
                    return i;
                    break;
                }
            }
    }
    return retorno;
}

int removeEmployeeById(Employees* empleado,int length,int index)
{
    int retorno=-1;
    empleado[index].isEmpty=1;
    printf("Se removio el Empleado de id[%d]\n",empleado[index].id);
    return retorno;
}

int modificarEmployee(Employees* empleado,int length,int index)
{
    int retorno=-1;
    int opcion;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
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
    return retorno;
}

int sortEmployeesByLastName(Employees* empleado,int length,int valor)
{
    int i;
    int j;
    int retorno=-1;
    Employees auxEmpleado;
    for(i=1;i<length;i++)
    {
        if(empleado[i].isEmpty==1)
            continue;
        strcpy(auxEmpleado.lastName,empleado[i].lastName);
        j=i-1;
        while(j>=0 && (strcmp(auxEmpleado.lastName,empleado[j].lastName)<0) && valor==1)
        {
            empleado[j+1]=empleado[j];
            j--;
        }
        empleado[j+1]=auxEmpleado; //insertion
        retorno=0;
    }
    return retorno;
}

int quick_sortLastname(Employees*empleado,int limite_izq,int limite_der)
{
    int izq;
    int der;
    Employees auxiliar;
    Employees pivote;
    izq=limite_izq;
    der=limite_der;
    strcpy(pivote.lastName,empleado[(izq+der)/2].lastName);
    do {
        while((strcmp(empleado[izq].lastName,pivote.lastName)<0) && izq<limite_der)izq++;
        while((strcmp(pivote.lastName,empleado[der].lastName)<0) && der>limite_izq)der--;
        if(izq<=der)
        {
            auxiliar=empleado[izq];
            empleado[izq]=empleado[der];
            empleado[der]=auxiliar;
            izq++;
            der--;
        }
    }while(izq<=der);
    if(limite_izq<der)
    {
        quick_sortLastname(empleado,limite_izq,der);
    }
    if(limite_der>izq)
    {
        quick_sortLastname(empleado,izq,limite_der);
    }
    return 0;
}

int quick_sortSector(Employees*empleado,int limite_izq,int limite_der)
{
    int izq;
    int der;
    Employees auxiliar;
    Employees pivote;
    izq=limite_izq;
    der=limite_der;
    pivote.sector=empleado[(izq+der)/2].sector;
    do {
        while(empleado[izq].sector<pivote.sector && izq<limite_der)izq++;
        while(pivote.sector<empleado[der].sector && der>limite_izq)der--;
        if(izq<=der)
        {
            auxiliar=empleado[izq];
            empleado[izq]=empleado[der];
            empleado[der]=auxiliar;
            izq++;
            der--;
        }
    }while(izq<=der);
    if(limite_izq<der)
    {
        quick_sortSector(empleado,limite_izq,der);
    }
    if(limite_der>izq)
    {
        quick_sortSector(empleado,izq,limite_der);
    }
    return 0;
}


void qsLastname(Employees* empleado,int length)
{
    quick_sortLastname(empleado,0,(length-1));
}

void qsSector(Employees* empleado,int length)
{
    quick_sortSector(empleado,0,(length-1));
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
                printf("Nombre: [%s]-Apellido: [%s]-Salario: [$%.2f]-Sector nro[%d]-ID[%d]\n",empleado[i].name,empleado[i].lastName,empleado[i].salary,empleado[i].sector,empleado[i].id);
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
        else
            continue;

    }
    *sumaSalario=auxSumaSalarios;
    *promedio=auxSumaSalarios/contadorEmpleados;
    return retorno;
}

int empleadosSuperaPromedio(Employees* empleado,int length,float* promedio,int* empleadosSP)
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
                if(empleado[i].salary>*promedio)
                {
                    cantidadEmpleados++;
                    retorno=0;
                }
            }
            else
                continue;
        }
    }
    *empleadosSP=cantidadEmpleados;
    return retorno;
}

void menuEmployees(void)
{
    Employees empleado[QTY_EMPLEADOS];
    initEmployees(empleado,QTY_EMPLEADOS,1);
    setEmployees(empleado,0,"Ricardo","Perez",12000,1);
    setEmployees(empleado,2,"Julio","Azaro",14500,3);
    setEmployees(empleado,3,"Amalia","Zeta",14500,2);
    setEmployees(empleado,5,"Enrique","Bonzo",9500,1);
    int index;
    int auxId;
    int opcion;
    int opcionInfo;
    float sumaSalario;
    float promedio;
    int empleadosSP;
    do
    {
        printf("1-ALTA DE EMPLEADO\n2-MODIFICACION DE EMPLEADO\n3-BAJA DE EMPLEADO\n4-INFORMES\n5-SALIR");
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
                __fpurge(stdin);
                printf("INFORMES\n(1)Listar Empleados por Apellido y Sector\n(2)Total,Promedio Salario-Cantidad de Empleados que superan el Promedio\n(3)ATRAS...");
                sumaSalario=0.0;
                promedio=0.0;
                empleadosSP=0;
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

int setEmployees(Employees*empleado,int index,char*nombre,char*apellido,float salario,int sector)
{
    int retorno=-1;
    if(index<QTY_EMPLEADOS)
    {
        strncpy(empleado[index].name,nombre,51);
        strncpy(empleado[index].lastName,apellido,51);
        empleado[index].salary=salario;
        empleado[index].sector=sector;
        empleado[index].isEmpty=0;
        empleado[index].id=generarID();
        retorno=0;
    }
    return retorno;
}

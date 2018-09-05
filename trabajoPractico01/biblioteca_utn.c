#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "biblioteca_utn.h"
static int getFloat(float* pResultado);
void menuCalculadora(void)
{
    float numero1=0;
    float numero2=0;
    char continuar='s';
    int opcion;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    int division;
    int resultadoFactorialA;
    int resultadoFactorialB;
    do
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",numero1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);
        printf("3- Calcular todas las operaciones\n");
        printf("4- Informar todas las operaciones\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: utn_getFlotante(&numero1,"Ingrese 1er operando A= ","Error debe Ingresar un numero\n",3,-1000000,1000000);
                system("clear");
                break;
            case 2:utn_getFlotante(&numero2,"Ingrese 2do operando B= ","Error debe Ingresar un numero\n",3,-1000000,1000000);
                system("clear");
                break;
            case 3: sumar(numero1,numero2,&resultadoSuma);
                restar(numero1,numero2,&resultadoResta);
                multiplicar(numero1,numero2,&resultadoMultiplicacion);
                system("clear");
                division=dividir(numero1,numero2,&resultadoDivision,"NO SE PUEDE DIVIDIR POR CERO\n");
                resultadoFactorialA=factorial(numero1);
                if(resultadoFactorialA==-1)
                {
                    printf("Error al calcular factorial de A\n");
                }
                resultadoFactorialB=factorial(numero2);
                if(resultadoFactorialB==-1)
                {
                    printf("Error al calcular factorial de B\n");
                }
                printf("SE HA REALIZADO TODOS LOS CALCULOS\n");
                break;
            case 4:
                system("clear");
                printf("La Suma (A+B)= %.2f\n",resultadoSuma);
                printf("La Resta (A-B)= %.2f\n",resultadoResta);
                printf("La Multiplicacion (A*B)= %.2f\n",resultadoMultiplicacion);
                if(division==0)
                {
                    printf("La Division (A/B)= %.2f\n",resultadoDivision);
                }
                else
                {
                    printf("La Division (A/B)= ERROR\n");
                }
                printf("El factorial de A!: %d\n",resultadoFactorialA);
                printf("El factorial de B!: %d\n\n\n",resultadoFactorialB);
                break;

            default: continuar='n';

        }

    }while(continuar=='s');


}

int utn_getFlotante(float* pNumero,char* pMsg,char*pMsgError,int intentos,int minimo,int maximo)
{
    int retorno=-1;
    float auxNumero;

    for(;intentos>0;intentos--)
    {
        printf("%s",pMsg);
        if(getFloat(&auxNumero)==0)
        {
            if (auxNumero>=minimo && auxNumero<maximo)
            {
                *pNumero=auxNumero;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",pMsgError);
            }
        }
        else
        {
            printf("%s",pMsgError);
            __fpurge(stdin);
        }
    }
    return retorno;


}

int sumar(float numero1,float numero2,float* pResultado)
{
    *pResultado=numero1+numero2;
    return 0;
}

int restar(float numero1,float numero2,float* pResultado)
{
    *pResultado=numero1-numero2;
    return 0;
}

int multiplicar(float numero1,float numero2,float* pResultado)
{
    *pResultado=numero1*numero2;
    return 0;
}

int dividir (float numero1,float numero2,float* pResultado,char* pMsgError)
{
    float auxiliarResultado;
    int retorno=-1;

    auxiliarResultado=numero1/numero2;
    if (numero2==0)
    {
        printf("%s",pMsgError);
        return retorno;
    }
    else
    {
        *pResultado=auxiliarResultado;
        retorno=0;
        return retorno;

    }
}

int factorial (int numero)
{
    int i;
    int resultado=1;
    if (numero>0 && numero<12)
    {
        for (i=1;i<=numero;i++)
        {
            resultado*=i;
        }
    return resultado;
    }
    else
    {
        return -1;
    }
}

static int getFloat(float* pResultado)
{
    float auxResultado;
    int retorno=-1;

    if(scanf("%f",&auxResultado)==1)
    {
        *pResultado=auxResultado;
        retorno=0;
    }
    return retorno;
}


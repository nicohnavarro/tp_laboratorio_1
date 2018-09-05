#ifndef BIBLIOTECA_UTN_H_INCLUDED
#define BIBLIOTECA_UTN_H_INCLUDED
/**
    utn_getFlotante : pide un flotante al usuario
    @param
    @param reIntentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getFlotante(float* pNumero,char* pMsg,char*pMsgError,int intentos,int minimo,int maximo);
void menuCalculadora(void);
int sumar(float numero1,float numero2,float* pResultado);
int restar(float numero1,float numero2,float* pResultado);
int multiplicar(float numero1,float numero2,float* pResultado);
int dividir (float numero1,float numero2,float* pResultado,char* pMsgError);
int factorial (int numero);
#endif // BIBLIOTECA_UTN_H_INCLUDED

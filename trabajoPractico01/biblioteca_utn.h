#ifndef BIBLIOTECA_UTN_H_INCLUDED
#define BIBLIOTECA_UTN_H_INCLUDED
/**
    utn_getFlotante : pide un flotante al usuario
    @param  punteroNumero
    @param  mensaje inicial
    @param  mensaje Error
    @param reIntentos: cantidad de reintentos
    @param minimo
    @param maximo
    @return : 0 OK, -1 error.
*/
int utn_getFlotante(float* pNumero,char* pMsg,char*pMsgError,int intentos,int minimo,int maximo);


/** \brief menu de Calculadora
 *
 * \param
 * \param
 * \return
 *
 */
void menuCalculadora(void);


/** \brief  suma dos numeros
 *
 * \param primer numero
 * \param segundo numero
 * \param puntero del resultado
 * \return 0
 *
 */
int sumar(float numero1,float numero2,float* pResultado);

/** \brief  resta dos numeros
 *
 * \param primer numero
 * \param segundo numero
 * \param puntero del resultado
 * \return 0
 *
 */
int restar(float numero1,float numero2,float* pResultado);

/** \brief  multiplica dos numeros
 *
 * \param primer numero
 * \param segundo numero
 * \param puntero del resultado
 * \return 0
 *
 */
int multiplicar(float numero1,float numero2,float* pResultado);

/** \brief  divide dos numeros
 *
 * \param primer numero
 * \param segundo numero
 * \param puntero del resultado
  * \param Mensaje de Error
 * \return 0 OK, -1 error.
 *
 */
int dividir (float numero1,float numero2,float* pResultado,char* pMsgError);

/** \brief  calcula factorial de un numero
 *
 * \param primer numero
 * \return  resultado OK , -1 error.
 *
 */
int factorial (int numero);
#endif // BIBLIOTECA_UTN_H_INCLUDED

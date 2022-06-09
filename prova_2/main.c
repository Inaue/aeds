/**
 * @file   main.c
 * @brief  ARQUIVO PRINCIPAL DO PROGRAMA PARA A PROVA 1
 * @author Inaue Ferreira da Silva
 * @date   05-07-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include "lista.h"
#include "pilhas.h"
#include "fila2.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int         main		(int argc, char** argv);
void        interface_problema 	(void);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INTERFACE DO USUARIO
 */
void interface_problema(void)
{

}

/**
 * @brief FUNCAO PRINCIPAL
 *
 * @param argc NUMERO DE ARGUMENTOS
 * @param argv ARGUMENTOS
 * @return int CODIGO DE ERRO
 */
int main(int argc, char** argv)
{
    interface_problema();

    return EXECUTADO_COM_EXITO;
}

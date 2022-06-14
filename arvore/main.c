/**
 * @file   main.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE ARVORES
 * @author Inaue Ferreira da Silva
 * @date   06-10-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int		main					(int argc, char** argv);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void aula()
{
	Arv* A1 = arv_cria('c', arv_criavazia(), arv_criavazia());
	Arv* A2 = arv_cria('d', arv_criavazia(), arv_criavazia());
	Arv* A3 = arv_cria('b', A1, arv_criavazia());
	Arv* A4 = arv_cria('a', A3, A2);

	printf("Pre-ordem:\n");
	arv_imprime_preordem(A4);
	printf("\nSimetria:\n");
	arv_imprime_simetrica(A4);
	printf("\nPos-ordem:\n");
	arv_imprime_posordem(A4);
	/*A4 = arv_libera(A4);*/
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
    aula();

    return EXECUTADO_COM_EXITO;
}

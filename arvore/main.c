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

Arv* arv_insere_ordenado(Arv* Arv_inserir, char dado)
{
	if (Arv_inserir == NULL)
		return arv_cria(dado, arv_criavazia(), arv_criavazia());

	if (dado > Arv_inserir->info)
		Arv_inserir->dir = arv_insere_ordenado(Arv_inserir->dir, dado);
	else 
		Arv_inserir->esq = arv_insere_ordenado(Arv_inserir->esq, dado);

	return Arv_inserir;
}
void aula()
{
	Arv* avri = arv_criavazia();

	avri = arv_insere_ordenado(avri, 'c');
	avri = arv_insere_ordenado(avri, 'a');
	avri = arv_insere_ordenado(avri, 'b');
	avri = arv_insere_ordenado(avri, 'd');

	printf("Pre-ordem:\n");
	arv_imprime_preordem(avri);
	printf("\nSimetria:\n");
	arv_imprime_simetrica(avri);
	printf("\nPos-ordem:\n");
	arv_imprime_posordem(avri);
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

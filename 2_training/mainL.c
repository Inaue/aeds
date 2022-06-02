/**
 * @file   mainL.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE LISTAS
 * @author Inaue Ferreira da Silva
 * @date   02-06-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include "lista.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */

#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
int     main	                (int argc, char** argv);
void    lst_imprime_rec         (Lista *l);
void	exec1			        (void);
Lista*  lerLst                  (Lista* LstALer);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief RETIRA UM ELEMENTO DA LISTA RECURSIVAMENTE
 * @param l LISTA
 * @param v VALOR A SER RETIRADO
 * @return  Lista* ENDERECO DA LISTA MODIFICADA
 */
Lista *lst_retira_rec(Lista* l, Lista* celulaAnterior, Lista *celulaAtual, int v){
	if(celulaAtual!=NULL && celulaAtual->info!=v)
        return lst_retira_rec(l, celulaAtual, celulaAtual->prox, v);
	
    if(celulaAtual==NULL){
		printf("Elemento não encontrado\n");
		return l;
	}

	if(celulaAnterior==NULL)
		l=celulaAtual->prox;
	else
		celulaAnterior->prox=celulaAtual->prox;

	free(celulaAtual);
	return l;
}

/**
 * @brief LE UMA LISTA DE INTEIROS DO USUARIO
 *
 * @param LstALer	LISTA A SER LIDA
 * @return Lista*	ENDERECO DA LISTA COMPLETA
 */
Lista* lerLst(Lista* LstALer)
{
	int tamanhoLst, elemento, valor;

	printf("________________________________________________________________________\n");
	printf("Digite quantos elementos deseja inserir na lista:\n");
	scanf(" %i", &tamanhoLst);

	for (elemento = 0; elemento < tamanhoLst; elemento++)
	{
		printf("\tDigite o valor do %i elemento: ", (elemento + 1));
		scanf(" %i", &valor);
		LstALer = lst_insere(LstALer, valor);
	}

	printf("________________________________________________________________________\n");

	return LstALer;
}

/**
 * @brief IMPRIME RECURSIVAMENTE OS ELEMENTOS DA LISTA
 * @param l LISTA
 */
void lst_imprime_rec(Lista *l){
	if (l!=NULL)
    {
		printf("Valor: %d\n", l->info);
        lst_imprime_rec(l->prox);
	}
}

/**
 * @brief RESOLUCAO DO EXERCICIO 1
 */
void exec1()
{
    int retirar;
    Lista* ListaUsuario = lst_cria();

    ListaUsuario = lerLst(ListaUsuario);
    printf("Digite o elemento que deseja retirar:\n");
    scanf("%i", &retirar);
    printf("Elementos da lista antes:\n");
    lst_imprime_rec(ListaUsuario);
    ListaUsuario = lst_retira_rec(ListaUsuario, NULL, ListaUsuario, retirar);
    printf("Elementos da lista depois:\n");
    lst_imprime_rec(ListaUsuario);
    lst_libera(ListaUsuario);
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
    exec1();

    return EXECUTADO_COM_EXITO;
}

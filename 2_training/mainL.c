/**
 * @file   mainL.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE LISTAS
 * @author Inaue Ferreira da Silva
 * @date   06-06-2022
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
int     main	               	(int argc, char** argv);
void	exec1			(void);
void	exec2			(void);
Lista*  lerLst                  (Lista* LstALer);
void    lst_imprime_rec         (Lista *l);
void	lst_libera_rec		(Lista* l);
Lista*	lst_retira_rec		(Lista* l, Lista* celulaAnterior, Lista *celulaAtual, int v);
Lista*	lst_intercala		(Lista* l1, Lista* l2);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief RESOLUCAO DO EXERCICIO 1
 */
void exec2()
{
    Lista* Lista1Usuario = lst_cria();
    Lista* Lista2Usuario = lst_cria();
    Lista* ListasIntercaladas;
    
    printf("________________________________________________________________________\n");
    printf("Lista 1\n");
    Lista1Usuario = lerLst(Lista1Usuario);
    printf("Lista 2\n");
    Lista2Usuario = lerLst(Lista2Usuario);
    printf("________________________________________________________________________\n");
    printf("Lista 1:\n");
    lst_imprime_rec(Lista1Usuario);
    printf("Lista 2:\n");
    lst_imprime_rec(Lista2Usuario);
    printf("Listas intercaladas:\n");
    ListasIntercaladas = lst_intercala(Lista1Usuario, Lista2Usuario);
    lst_imprime_rec(ListasIntercaladas);
    lst_libera_rec(ListasIntercaladas);
    Lista1Usuario	= NULL;
    Lista2Usuario	= NULL;
    ListasIntercaladas	= NULL;
}

/**
 * @brief INTERCALA DUAS LISTA (DESTROI AS LISTAS ORIGINAIS)
 * @param l1 PRIMEIRA LISTA
 * @param l2 SEGUNDA LISTA
 * @return Lista*	LISTA RESULTANTE
 */
Lista*	lst_intercala		(Lista* l1, Lista* l2) {
	Lista* Auxiliar;

	if (lst_vazia(l2))
		return l1;
	
	if (!lst_vazia(l1))
	{
		Auxiliar = l2->prox;
		l2->prox = l1;
		l1->prox = lst_intercala(l1->prox, Auxiliar);
	}
	
	return l2;
}
/**
 * @brief LIBERA UMA LISTA RECURSIVAMENTE
 * @param l LISTA A LIBERAR
 */
void lst_libera_rec(Lista* l)
{
	Lista* tmp;
	
	if (l!=NULL){
		tmp = l->prox;
		free(l);
		lst_libera_rec(tmp);
	}
}

/**
 * @brief RETIRA UM ELEMENTO DA LISTA RECURSIVAMENTE
 * @param l LISTA
 * @param celulaAnterior CELULA ANTERIOR A CELULA ATUAL
 * @param celulaAtual CELULA A SE MANIPULAR
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
    lst_libera_rec(ListaUsuario);
    ListaUsuario = NULL;
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
    exec2();

    return EXECUTADO_COM_EXITO;
}

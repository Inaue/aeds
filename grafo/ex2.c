/**
 * @file   ex2.c
 * @brief  RESOLUCAO DO EXERCICIO DE GRAFOS
 * @author Inaue Ferreira da Silva
 * @date   07-10-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*	CONSTANTES	*/
#define VERDADEIRO	(1 == 1)
#define FALSO		!VERDADEIRO
#define MAX_VERTICES	10

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main		(int argc, char** argv);
int	grau_vertice	(Lista* vertice);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	grau_vertice	(Lista* vertice)
{
	int grau = 0;
	Lista* adjacente = vertice;

	while (adjacente != NULL)
	{
		adjacente = adjacente->prox;
		grau++;
	}

	return grau;
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
	Lista* grafo[MAX_VERTICES];
	int vertices, v, v1, v2;

	printf("GRAFO NAO-ORIENTADO\n");
	printf("____________________________________________________________\n");
	printf("Digite quantos vertices deseja no grafo (max.: %i):\n", MAX_VERTICES);
	scanf("%i", &vertices);

	for (v = 0; v < vertices; v++)
		grafo[v] = lst_cria();

	for (v1 = 0; v1 < vertices; v1++)
	{
		for (v2 = v1+1; v2 < vertices; v2++)
		{
			printf("Digite 1 caso haja a aresta (%i,%i), e 0 caso contrario:\n", v1, v2);
			scanf("%i", &v);
			if (v == 1)
			{
				grafo[v1] = lst_insere(grafo[v1], v2);
				grafo[v2] = lst_insere(grafo[v2], v1);
			}
		}
	}

	printf("____________________________________________________________\n");
	printf("Digite o vertice de cujo grau deseja obter (-1 = SAIR):\n");
	scanf("%i", &v);
	
	while(v != -1)
	{
		printf("O grau do vertice %i eh %i\n", v, grau_vertice(grafo[v]));
		printf("____________________________________________________________\n");
		printf("Digite o vertice de cujos graus deseja obter (-1 = SAIR):\n");
		scanf("%i", &v);
	}

	for (v = 0; v < vertices; v++)
		lst_libera(grafo[v]);

	return EXECUTADO_COM_EXITO;
}

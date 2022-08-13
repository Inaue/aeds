/**
 * @file   main.c
 * @brief  IMPLEMENTACAO DAS BUSCAS EM LARGURA E PROFUNDIDADE
 * @author Inaue Ferreira da Silva
 * @date   07-10-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*	CONSTANTES	*/
#define VERDADEIRO	(1 == 1)
#define FALSO		!VERDADEIRO
#define V_EXPLORANDO	0
#define VIZINHOS_EXPLOR	1
#define COMECO_BUSCA	0
#define FIM_BUSCA	1
#define NAO_PREENCHIDO	-1
#define V_EXPLORAR	NAO_PREENCHIDO
#define SEM_PREDECESSOR	NAO_PREENCHIDO

/*	ESTRUTURAS	*/
struct Info_bfs {
	int distancia;
	int estado;
	int predecessor;
};
typedef struct Info_bfs Info_bfs;

struct Info_dfs {
	int timestamp[2];
	int estado;
	int predecessor;
};
typedef struct Info_dfs Info_dfs;

/* 	FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
void	grafo_bfs		(Lista** grafo, int total_vertices, int v_inicial, Info_bfs* resultado);
void	grafo_dfs		(Lista** grafo, int total_vertices, int v_inicial, Info_dfs* resultado);
void	lst_print		(Lista* lst_imprimir);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*
void	grafo_bfs		(int** grafo, int total_vertices, int v_inicial, int** resultado)
{
	int predecessor, v;

	resultado[ESTADO][v_inicial] = V_EXPLORANDO;
	
	if (resultado[PREDECESSOR][v_inicial] == NAO_PREENCHIDO)
	{
		resultado[DISTANCIA][v_inicial] = 0;
	}
	else
	{
		predecessor = resultado[PREDECESSOR][v_inicial];
		resultado[DISTANCIA][v_inicial] = resultado[DISTANCIA][predecessor] + 1;	
	}

	for (v = 0; v < total_vertices; v++)
	{
		if ((grafo[v_inicial][v] == 1) && (resultado[ESTADO][v] == V_EXPLORAR))
		{
			resultado[PREDECESSOR][v] = v_inicial;
			grafo_bfs(grafo, total_vertices, v, resultado);
		}
	}

	resultado[ESTADO][v_inicial] = VIZI_EXPLORADOS;
}
*/

void	lst_print	(Lista* lst_imprimir)
{
	Lista* item = lst_imprimir;

	while(item != NULL)
	{
		printf("%i -> ", item->info);
		item = item->prox;
	}

	printf("/\n");

}

void	grafo_bfs		(Lista** grafo, int total_vertices, int v_inicial, Info_bfs* resultado)
{
	int v_explorando;
	FilaL* vertices_explorando = fila_cria_l();
	Lista* v_adjacente;

	fila_insere_l(vertices_explorando, v_inicial);
	resultado[v_inicial].estado		= V_EXPLORANDO; 
	resultado[v_inicial].predecessor	= SEM_PREDECESSOR;
	resultado[v_inicial].distancia		= 0;

	do {
		v_explorando = fila_retira_l(vertices_explorando);

		for (v_adjacente = grafo[v_explorando]; v_adjacente != NULL; v_adjacente = v_adjacente->prox)
		{
			if (resultado[v_adjacente->info].estado == V_EXPLORAR)
			{
				resultado[v_adjacente->info].predecessor	= v_explorando;
				resultado[v_adjacente->info].estado		= V_EXPLORANDO;
				resultado[v_adjacente->info].distancia		= resultado[v_explorando].distancia + 1;
				fila_insere_l(vertices_explorando, v_adjacente->info);
			}
		}

		resultado[v_explorando].estado = VIZINHOS_EXPLOR;
	} while (!fila_vazia_l(vertices_explorando));

	fila_libera_l(vertices_explorando);
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
	Lista** grafo;
	Info_bfs* resultado_busca_bfs;
	Info_dfs* resultado_busca_dfs;
	int vertices, v, v1, v2, origem, i, seed;

	printf("GRAFO ORIENTADO\n");
	printf("____________________________________________________________\n");
	printf("Digite quantos vertices deseja no grafo:\n");
	scanf("%i", &vertices);
	printf("Digite um numero inteiro qualquer:\n");
	scanf("%i", &seed);
	printf("Digite a origem da busca:\n");
	scanf("%i", &origem);
	srand(seed);
	grafo = (Lista**)malloc(vertices * sizeof(Lista*));
	resultado_busca_bfs = (Info_bfs*)malloc(vertices * sizeof(Info_bfs));
	resultado_busca_dfs = (Info_dfs*)malloc(vertices * sizeof(Info_dfs));

	for (v = 0; v < vertices; v++)
	{
		grafo[v] = lst_cria();
		resultado_busca_bfs[v].estado		= NAO_PREENCHIDO;
		resultado_busca_bfs[v].predecessor	= NAO_PREENCHIDO;
		resultado_busca_bfs[v].distancia	= NAO_PREENCHIDO;
	}

	for (v1 = 0; v1 < vertices; v1++)
	{
		for (v2 = 0; v2 < vertices; v2++)
		{
			if ((rand() % 2) == 1)
				grafo[v1] = lst_insere(grafo[v1], v2);
		}
	}

	printf("____________________________________________________________\n");
	printf("GRAFO RESULTANTE:\n");

	for (v = 0; v < vertices; v++)
	{
		printf("vertices 'destino' a partir do vertice %i: ", v);
		lst_print(grafo[v]);
	}

	printf("____________________________________________________________\n");
	printf("vertice\tdistancia\tpredecessor\testado\n");
	grafo_bfs(grafo, vertices, origem, resultado_busca_bfs);

	for (v = 0; v < vertices; v++)
		printf("%i\t%i\t\t%i\t\t%i\n", v, resultado_busca_bfs[v].distancia, resultado_busca_bfs[v].predecessor, resultado_busca_bfs[v].estado);

	free(grafo);
	free(resultado_busca_bfs);
	free(resultado_busca_dfs);

	return EXECUTADO_COM_EXITO;
}

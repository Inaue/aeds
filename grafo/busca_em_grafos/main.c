/**
 * @file   main.c
 * @brief  IMPLEMENTACAO DAS BUSCAS EM LARGURA E PROFUNDIDADE
 * @author Inaue Ferreira da Silva
 * @date   08-13-2022
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
#define COMECO_BUSCA	0
#define FIM_BUSCA	1
#define NAO_PREENCHIDO	-1

/*	ESTRUTURAS	*/
struct Info_bfs {
	int distancia;
	int visitado;
	int predecessor;
};
typedef struct Info_bfs Info_bfs;

struct Info_dfs {
	int timestamp[2];
	int visitado;
	int predecessor;
};
typedef struct Info_dfs Info_dfs;

/* 	FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
void	grafo_bfs		(Lista** grafo, int total_vertices, int v_inicial, Info_bfs* resultado);
void	grafo_dfs		(Lista** grafo, int total_vertices, int v_inicial, Info_dfs* resultado);
int	dfs_recursao		(Lista** grafo, int total_vertices, int v_inicial, Info_dfs* resultado);
void	lst_print		(Lista* lst_imprimir);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	dfs_recursao		(Lista** grafo, int total_vertices, int v_inicial, Info_dfs* resultado)
{
	int tempo;
	Lista* v_adjacente;

	resultado[v_inicial].visitado = VERDADEIRO;
	tempo = resultado[v_inicial].timestamp[COMECO_BUSCA] + 1;

	for (v_adjacente = grafo[v_inicial]; v_adjacente != NULL; v_adjacente = v_adjacente->prox)
	{
		if (!resultado[v_adjacente->info].visitado)
		{
			resultado[v_adjacente->info].timestamp[COMECO_BUSCA] = tempo;
			resultado[v_adjacente->info].predecessor = v_inicial;
			tempo = dfs_recursao(grafo, total_vertices, v_adjacente->info, resultado);
		}
	}

	resultado[v_inicial].timestamp[FIM_BUSCA] = tempo;
	return tempo + 1;
}

void	grafo_dfs		(Lista** grafo, int total_vertices, int v_inicial, Info_dfs* resultado)
{
	int tempo = dfs_recursao(grafo, total_vertices, v_inicial, resultado);

	for (v_inicial = 0; v_inicial < total_vertices; v_inicial++)
	{
		if (!resultado[v_inicial].visitado)
		{
			resultado[v_inicial].timestamp[COMECO_BUSCA] = tempo;
			tempo = dfs_recursao(grafo, total_vertices, v_inicial, resultado);
		}
	}
}

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
	resultado[v_inicial].visitado		= VERDADEIRO;
	resultado[v_inicial].predecessor	= NAO_PREENCHIDO;
	resultado[v_inicial].distancia		= 0;

	do {
		v_explorando = fila_retira_l(vertices_explorando);

		for (v_adjacente = grafo[v_explorando]; v_adjacente != NULL; v_adjacente = v_adjacente->prox)
		{
			if (!resultado[v_adjacente->info].visitado)
			{
				resultado[v_adjacente->info].predecessor	= v_explorando;
				resultado[v_adjacente->info].visitado		= VERDADEIRO;
				resultado[v_adjacente->info].distancia		= resultado[v_explorando].distancia + 1;
				fila_insere_l(vertices_explorando, v_adjacente->info);
			}
		}

		resultado[v_explorando].visitado = VERDADEIRO;
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
		resultado_busca_bfs[v].visitado			= FALSO;
		resultado_busca_bfs[v].predecessor		= NAO_PREENCHIDO;
		resultado_busca_bfs[v].distancia		= NAO_PREENCHIDO;
		resultado_busca_dfs[v].visitado			= FALSO;
		resultado_busca_dfs[v].predecessor		= NAO_PREENCHIDO;
		resultado_busca_dfs[v].timestamp[COMECO_BUSCA]	= NAO_PREENCHIDO;
		resultado_busca_dfs[v].timestamp[FIM_BUSCA]	= NAO_PREENCHIDO;
	}
	
	resultado_busca_dfs[origem].timestamp[COMECO_BUSCA] = 1;

	for (v1 = 0; v1 < vertices; v1++)
	{
		for (v2 = 0; v2 < vertices; v2++)
		{
			if ((rand() % 2) == 1)
				grafo[v1] = lst_insere(grafo[v1], v2);
		}
	}
	
	grafo_bfs(grafo, vertices, origem, resultado_busca_bfs);
	grafo_dfs(grafo, vertices, origem, resultado_busca_dfs);

	printf("____________________________________________________________\n");
	printf("GRAFO RESULTANTE:\n");

	for (v = 0; v < vertices; v++)
	{
		printf("vertices 'destino' a partir do vertice %i: ", v);
		lst_print(grafo[v]);
	}

	printf("____________________________________________________________\n");
	printf("RESULTADO DAS PESQUISAS\n");
	printf("____________________________________________________________\n");
	printf("BUSCA EM LARGURA:\n");
	printf("VERTICE\t\tDISTANCIA\tPREDECESSOR\tVISITADO\n");

	for (v = 0; v < vertices; v++)
	{
		printf("%i\t|\t", v);
		
		if (resultado_busca_bfs[v].distancia == -1)
			printf("-\t\t");
		else
			printf("%i\t\t", resultado_busca_bfs[v].distancia);
		
		if (resultado_busca_bfs[v].predecessor == -1)
			printf("-\t\t");
		else
			printf("%i\t\t", resultado_busca_bfs[v].predecessor);
		
		if (resultado_busca_bfs[v].visitado)
			printf("Sim\n");
		else
			printf("Nao\n");
	}

	printf("____________________________________________________________\n");
	printf("BUSCA EM PROFUNDIDADE:\n");
	printf("VERTICE\t\tTIMESTAMP\tPREDECESSOR\tVISITADO\n");

	for (v = 0; v < vertices; v++)
	{
		printf("%i\t|\t", v);
		printf("%i/%i\t\t", resultado_busca_dfs[v].timestamp[COMECO_BUSCA], resultado_busca_dfs[v].timestamp[FIM_BUSCA]);
		
		if (resultado_busca_dfs[v].predecessor == -1)
			printf("-\t\t");
		else
			printf("%i\t\t", resultado_busca_dfs[v].predecessor);
		
		if (resultado_busca_dfs[v].visitado)
			printf("Sim\n");
		else
			printf("Nao\n");
	}

	free(grafo);
	free(resultado_busca_bfs);
	free(resultado_busca_dfs);

	return EXECUTADO_COM_EXITO;
}

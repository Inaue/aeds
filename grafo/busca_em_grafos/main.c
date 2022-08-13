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
#define NAO_PREENCHIDO	-1
#define V_EXPLORAR	NAO_PREENCHIDO
#define V_EXPLORADO	1
#define VIZI_EXPLORADOS	2

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
void	grafo_bfs		(int** grafo, int total_vertices, int vertice_inicial, Info_bfs* guardar_resultado);
void	grafo_dfs		(int** grafo, int total_vertices, int vertice_inicial, Info_dfs* guardar_resultado);
void	lst_print		(Lista* lst_imprimir);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*
void	grafo_bfs		(int** grafo, int total_vertices, int vertice_inicial, int** guardar_resultado)
{
	int predecessor, v;

	guardar_resultado[ESTADO][vertice_inicial] = V_EXPLORADO;
	
	if (guardar_resultado[PREDECESSOR][vertice_inicial] == NAO_PREENCHIDO)
	{
		guardar_resultado[DISTANCIA][vertice_inicial] = 0;
	}
	else
	{
		predecessor = guardar_resultado[PREDECESSOR][vertice_inicial];
		guardar_resultado[DISTANCIA][vertice_inicial] = guardar_resultado[DISTANCIA][predecessor] + 1;	
	}

	for (v = 0; v < total_vertices; v++)
	{
		if ((grafo[vertice_inicial][v] == 1) && (guardar_resultado[ESTADO][v] == V_EXPLORAR))
		{
			guardar_resultado[PREDECESSOR][v] = vertice_inicial;
			grafo_bfs(grafo, total_vertices, v, guardar_resultado);
		}
	}

	guardar_resultado[ESTADO][vertice_inicial] = VIZI_EXPLORADOS;
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

void	grafo_bfs		(int** grafo, int total_vertices, int vertice_inicial, Info_bfs* guardar_resultado)
{
	FilaL* vertices_explorar = fila_cria_l();

	fila_insere_l(vertices_explorar, vertice_inicial);

	fila_libera_l(vertices_explorar);
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
	Info_dfs* resultado_busca_dfs;
	Info_bfs* resultado_busca_bfs;
	int vertices, v, v1, v2, i, seed;

	printf("GRAFO ORIENTADO\n");
	printf("____________________________________________________________\n");
	printf("Digite quantos vertices deseja no grafo:\n");
	scanf("%i", &vertices);
	printf("Digite um numero inteiro qualquer:\n");
	scanf("%i", &seed);
	srand(seed);

	grafo = (Lista**)malloc(vertices * sizeof(Lista*));

	for (v = 0; v < vertices; v++)
		grafo[v] = lst_cria();

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

	free(grafo);

	return EXECUTADO_COM_EXITO;
}

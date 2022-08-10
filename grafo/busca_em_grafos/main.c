/**
 * @file   main.c
 * @brief  IMPLEMENTACAO DAS BUSCAS EM LARGURA E PROFUNDIDADE
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
int** 	alocarMatrizInt		(int linhas, int colunas);
void	desalocarMatrizInt	(int** matriz, int linhas);
void	grafo_bfs		(int** grafo, int total_vertices, int vertice_inicial, int** guardar_resultado);
void	grafo_dfs		(int** grafo, int total_vertices, int vertice_inicial, int** guardar_resultado);

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

void	grafo_dfs		(int** grafo, int total_vertices, int vertice_inicial, int** guardar_resultado)
{

}

/**
 * @brief ALOCA ESPACO PARA MATRIZ DE INTEIROS
 *
 * @param linhas	QUANTIDADE DE LINHAS A ALOCAR
 * @param colunas	QUANTIDADE DE COLUNAS A ALOCAR
 * @return int**	ENDERECO DA MATRIZ
 */
int** alocarMatrizInt(int linhas, int colunas)
{
	int** ponteiroMatriz = (int**)malloc(linhas * sizeof(int*));
	int contadorLinhas, memoriaInsuficiente = FALSO;

	if (ponteiroMatriz != NULL)
	{
		for (contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++)
		{
			ponteiroMatriz[contadorLinhas] = malloc(sizeof(int) * colunas);
			memoriaInsuficiente = (memoriaInsuficiente || (ponteiroMatriz[contadorLinhas] == NULL));
		}

		if (memoriaInsuficiente)
		{
			for (contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++)
			{
				free(ponteiroMatriz[contadorLinhas]);
			}
			free(ponteiroMatriz);
			ponteiroMatriz = NULL;
		}
	}

	return ponteiroMatriz;
}

/**
 * @brief DESALOCA ESPACO DE MATRIZ DE INTEIROS
 *
 * @param matriz	MATRIZ
 * @param linhas	QUANTIDADE DE LINHAS DA MATRIZ
 */
void desalocarMatrizInt(int** matriz, int linhas)
{
	int contadorLinhas;
	if (matriz != NULL)
	{
		for (contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++)
			free(matriz[contadorLinhas]);
	}
	free(matriz);
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
	int** grafo;
	int** resultado_busca;
	int vertices, v, v1, v2, i, seed;

	printf("GRAFO ORIENTADO\n");
	printf("____________________________________________________________\n");
	printf("Digite quantos vertices deseja no grafo:\n");
	scanf("%i", &vertices);
	grafo = alocarMatrizInt(vertices, vertices);
	resultado_busca = alocarMatrizInt(3, vertices);
	printf("Digite um numero inteiro qualquer:\n");
	scanf("%i", &seed);
	srand(seed);

	for (i = 0; i < 3; i++)
	{
		for(v = 0; v < vertices; v++)
			resultado_busca[i][v] = NAO_PREENCHIDO;
	}

	for (v1 = 0; v1 < vertices; v1++)
	{
		for (v2 = 0; v2 < vertices; v2++)
			grafo[v1][v2] = rand() % 2;
	}

	printf("____________________________________________________________\n");
	printf("Matriz Resultante (vertice x vertice):\n");
	putchar('\t');

	for (v2 = 0; v2 < vertices; v2++)
		printf("%i\t", v2);
	
	putchar('\n');
	printf("  ______________________________________________________________________________________\n");
	
	for (v1 = 0; v1 < vertices; v1++)
	{
		printf("%i|\t", v1);

		for (v2 = 0; v2 < vertices; v2++)
			printf("%i\t", grafo[v1][v2]);
		
		putchar('\n');
	}
	
	desalocarMatrizInt(grafo, vertices);
	desalocarMatrizInt(resultado_busca, 3);

	return EXECUTADO_COM_EXITO;
}

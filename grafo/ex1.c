/**
 * @file   ex1.c
 * @brief  RESOLUCAO DO EXERCICIO DE GRAFOS
 * @author Inaue Ferreira da Silva
 * @date   07-10-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*	CONSTANTES	*/
#define VERDADEIRO	(1 == 1)
#define FALSO		!VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
int 	grau_entrada		(int** grafo, int total_vertices, int vertice_calcular);
int 	grau_saida		(int** grafo, int total_vertices, int vertice_calcular);
int** 	alocarMatrizInt		(int linhas, int colunas);
void	desalocarMatrizInt	(int** matriz, int linhas);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

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
 * @brief CALCULA O GRAU DE ENTRADA DE UM VERTICE DO GRAFO
 *
 * @param grafo			GRAFO
 * @param total_vertices	QUANTIDADE DE VERTICES DO GRAFO
 * @param vertice_calcular	O VERTICE DE CUJO GRAU SE DESEJA	
 * @return int	GRAU DE ENTRADA
 */
int 	grau_entrada	(int** grafo, int total_vertices, int vertice_calcular)
{
	int v, grau = 0;

	for (v = 0; v < total_vertices; v++)
		grau += grafo[v][vertice_calcular];

	return grau;
}

/**
 * @brief CALCULA O GRAU DE SAIDA DE UM VERTICE DO GRAFO
 *
 * @param grafo			GRAFO
 * @param total_vertices	QUANTIDADE DE VERTICES DO GRAFO
 * @param vertice_calcular	O VERTICE DE CUJO GRAU SE DESEJA	
 * @return int	GRAU DE SAIDA
 */
int 	grau_saida	(int** grafo, int total_vertices, int vertice_calcular)
{
	int v, grau = 0;

	for (v = 0; v < total_vertices; v++)
		grau += grafo[vertice_calcular][v];

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
	int** grafo;
	int vertices, v, v1, v2, seed;

	printf("GRAFO ORIENTADO\n");
	printf("____________________________________________________________\n");
	printf("Digite quantos vertices deseja no grafo:\n");
	scanf("%i", &vertices);
	grafo = alocarMatrizInt(vertices, vertices);
	printf("Digite um numero inteiro qualquer:\n");
	scanf("%i", &seed);
	srand(seed);

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
	
	printf("____________________________________________________________\n");
	printf("Digite o vertice de cujos graus deseja obter (-1 = SAIR):\n");
	scanf("%i", &v);
	
	while(v != -1)
	{
		printf("Grau de entrada do vertice %i:\t%i\n", v, grau_entrada(grafo, vertices, v));
		printf("Grau de saida do vertice %i:\t%i\n", v, grau_saida(grafo, vertices, v));
		printf("Digite o vertice de cujos graus deseja obter (-1 = SAIR):\n");
		scanf("%i", &v);
		printf("____________________________________________________________\n");
	}

	desalocarMatrizInt(grafo, vertices);

	return EXECUTADO_COM_EXITO;
}

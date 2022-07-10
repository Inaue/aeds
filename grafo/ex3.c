/**
 * @file   ex3.c
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
#define VERTICES	10

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
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
 * @brief FUNCAO PRINCIPAL
 *
 * @param argc NUMERO DE ARGUMENTOS
 * @param argv ARGUMENTOS
 * @return int CODIGO DE ERRO
 */
int main(int argc, char** argv)
{
	int** grafo;
	int v1, v2;

	printf("GRAFO ORIENTADO\n");
	printf("____________________________________________________________\n");
	grafo = alocarMatrizInt(VERTICES, VERTICES);

	for (v1 = 0; v1 < VERTICES; v1++)
	{
		for (v2 = v1+1; v2 < VERTICES; v2++)
		{
			printf("Digite 1 caso o servidor %i se comunique com o %i, e 0 caso contrario:\n", v1, v2);
			scanf("%i", &(grafo[v1][v2]));
		}
	}

	printf("____________________________________________________________\n");

	for (v1 = 0; v1 < VERTICES; v1++)
	{
		for (v2 = v1+1; v2 < VERTICES; v2++)
		{
			if (grafo[v1][v2] == 0)
				printf("Servidores %i e %i nao estao se comunicando!\n", v1, v2);
		}
	}

	desalocarMatrizInt(grafo, VERTICES);

	return EXECUTADO_COM_EXITO;
}

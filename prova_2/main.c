/**
 * @file   main.c
 * @brief  ARQUIVO PRINCIPAL DO PROGRAMA PARA A PROVA 1
 * @author Inaue Ferreira da Silva
 * @date   05-07-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
#include "fila2.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
void	interface_problema 	(void);
void	fila_insere_ordenado_l	(FilaL2 *l, int v);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INSERE ELEMENTO NA FILA DE PRIORIDADE EM ORDEM DE PRIORIDADE
 * @param l	Fila
 * @param v	valor a inserir
 */
void fila_insere_ordenado_l(FilaL2 *f, int v){
	Lista *novo; novo=(Lista *)malloc(sizeof(Lista));
	novo->info=v;
	Lista *ant=NULL;
	Lista *p=f->ini;
	while(p!=NULL && p->info>v){
		ant=p;
		p=p->prox;
	}
	if(ant==NULL){
		novo->prox=f->ini;
		f->ini=novo;
	}
	else{
		ant->prox=novo;
		novo->prox=p;
	}
}

/**
 * @brief INTERFACE DO USUARIO
 */
void interface_problema(void)
{
	int instrucoes, i, inst, num, saidaL, saidaP, saidaF, saidaFpri;
	int ehPilha, ehFila, ehFilaP;
	FILE* entrada = fopen("entrada.txt", "r");
	Pilha_vet* testeP;
	Fila2* testeF;
	FilaL2* testeFpri;

	while (VERDADEIRO)
	{
		ehPilha		= VERDADEIRO;
		ehFila		= VERDADEIRO;
		ehFilaP		= VERDADEIRO;
		testeP		= pilha_vet_cria();
		testeF		= fila_cria_vet();
		testeFpri	= fila_cria_l();

		fscanf(entrada, " %i", &instrucoes);

		if (feof(entrada))
			break;

		for (i = 0; i < instrucoes; i++)
		{
			fscanf(entrada, " %i %i", &inst, &num);

			if (inst == 1)
			{
				pilha_vet_push(testeP, num);
				fila_insere_vet(testeF, num);
				fila_insere_ordenado_l(testeFpri, num);
			}
			else
			{
				saidaP = pilha_vet_pop(testeP);
				saidaF = fila_retira_vet(testeF);
				saidaFpri = fila_retira_l(testeFpri);

				ehPilha	= ehPilha	&& (saidaP == num);
				ehFila	= ehFila	&& (saidaF == num);
				ehFilaP	= ehFilaP	&& (saidaFpri == num);
			}
		}

		if (	(ehPilha && ehFila) ||
			(ehPilha && ehFilaP) ||
			(ehFila && ehFilaP)	)
			printf("not sure\n");
		else if (ehPilha)
			printf("stack\n");
		else if (ehFila)
			printf("queue\n");
		else if (ehFilaP)
			printf("priority queue\n");
		else
			printf("impossible\n");

		pilha_vet_libera(testeP);
		fila_libera_vet(testeF);
		fila_libera_l(testeFpri);
	}
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
    interface_problema();

    return EXECUTADO_COM_EXITO;
}

/**
 * @file   main.c
 * @brief  Programa principal contendo a resolucao dos exercicios de listas
 * @author Inauê Ferreira da Silva
 * @date   04-29-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * @brief VERIFICA SE DUAS LISTAS CONTEM OS MESMOS ELEMENTOS NA MESMA ORDEM
 *
 * @param Lst1	1 LISTA
 * @param Lst2	2 LISTA
 * @return int	0 = LISTAS SAO DIFERENTES, 1 = LISTAS SAO IGUAIS
 */
int lst_iguais(Lista* Lst1, Lista* Lst2)
{
	Lista* Celula1;
	Lista* Celula2;

	int saoIguais = 1;

	for (	Celula1 = Lst1, Celula2 = Lst2;
		(Celula1 != NULL) && (Celula2 != NULL);
		Celula1 = Celula1->prox, Celula2 = Celula2->prox)
		saoIguais = saoIguais && (Celula1->info == Celula2->info);

	saoIguais = saoIguais && ((Celula1 == NULL) && (Celula2 == NULL));

	return saoIguais;
}

/**
 * @brief DESCOBRE QUAL E A POSICAO DO SOBREVIVENTE DO PROBLEMA DE JOSEPHUS
 *
 * @param pessoas	QUANTIDADE DE PESSOAS NA RODA
 * @param passos	QUANTIDADE DE SALTOS A CADA EXECUCAO
 * @return int		A POSICAO DO SOBREVIVENTE
 */
int josephus(int pessoas, int passos)
{
	int p, posicaoRemover, salvacao;
	Lista* RodaDePessoas = lst_cria();
	Lista* ContadorPessoa;
	Lista* FimLst;

	for (p = 0; p < pessoas; p++)
		RodaDePessoas = lst_insere(RodaDePessoas, (pessoas - p));
	
	RodaDePessoas = lcirc_transforma(RodaDePessoas);
	ContadorPessoa = RodaDePessoas;

	for (p = 1; RodaDePessoas->prox != RodaDePessoas; p++)
	{
		if ((p % passos) == 0)
		{
			posicaoRemover	= ContadorPessoa->info;
			ContadorPessoa	= ContadorPessoa->prox;

			if (posicaoRemover == RodaDePessoas->info)
			{
				FimLst = ContadorPessoa;
				
				while (FimLst->prox != RodaDePessoas)
					FimLst = FimLst->prox;
				FimLst->prox = RodaDePessoas->prox;
			}
			
			RodaDePessoas	= lst_retira(RodaDePessoas, posicaoRemover);
		}
		else
			ContadorPessoa = ContadorPessoa->prox;
	}

	salvacao = RodaDePessoas->info;
	free(RodaDePessoas);

	return salvacao;
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
 * @brief INTERFACE DO USUARIO PARA O PROBLEMA DA COMPARACAO DE LISTAS
 */
void comparar_2_listas()
{
	Lista* Lst1Usuario = lst_cria();
	Lista* Lst2Usuario = lst_cria();

	Lst1Usuario = lerLst(Lst1Usuario);
	Lst2Usuario = lerLst(Lst2Usuario);

	if (lst_iguais(Lst1Usuario, Lst2Usuario))
		printf("As listas sao identicas.\n");
	else
		printf("As listas nao sao identicas.\n");

	lst_libera(Lst1Usuario);
	lst_libera(Lst2Usuario);
}

/**
 * @brief INTERFACE DO USUARIO PARA A RESOLUCAO DO PROBLEMA DE JOSEPHUS
 */
void pobrema_de_josue()
{
	int totalPessoas, tamnhoDoSalto;
	
	printf("________________________________________________________________________\n");
	printf("Digite a quantidade de pessoas envolvidas no problema de Josephus:\n");
	scanf(" %i", &totalPessoas);

	printf("________________________________________________________________________\n");
	printf("Digite a quantidade de saltos a serem dados a cada execucao:\n");
	scanf(" %i", &tamnhoDoSalto);

	printf("Para se safar, bastar permanecer na %i posicao!\n", josephus(totalPessoas, tamnhoDoSalto));
	printf("________________________________________________________________________\n");
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
	comparar_2_listas();
	pobrema_de_josue();

	return EXIT_SUCCESS;
}

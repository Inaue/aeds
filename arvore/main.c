/**
 * @file   main.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE ARVORES
 * @author Inaue Ferreira da Silva
 * @date   06-10-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
void	demonstracao		(void);
Arv*	arv_insere_ordenado	(Arv* Arv_inserir, char dado);
void	arv_frequencia_c	(Arv* Analisar, int* histograma);
int	arv_cont_folha		(Arv* Contar);
int	arv_cont_galho1		(Arv* Contar);
int	arv_cont_galho2		(Arv* Contar);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INSERIR ELEMENTO NA ARVORE DE ACORDO COM OS VALORES JA INSERIDOS
 *
 * @param Arv_inserir	ARVORE AONDE INSERIR DADO
 * @param Arv_inserir	DADO
 * @return Arv*		NOVO ENDERECO DA ARVORE
 */
Arv* arv_insere_ordenado(Arv* Arv_inserir, char dado)
{
	if (Arv_inserir == NULL)
		return arv_cria(dado, arv_criavazia(), arv_criavazia());

	if (dado > Arv_inserir->info)
		Arv_inserir->dir = arv_insere_ordenado(Arv_inserir->dir, dado);
	else 
		Arv_inserir->esq = arv_insere_ordenado(Arv_inserir->esq, dado);

	return Arv_inserir;
}

/**
 * @brief CONTAR GALHOS COM EXATAMENTE 1 FILHO
 *
 * @param Contar	ENDERECO DA ARVORE A SER ANALISADA
 * @return int		QUANTIDADE DE GALHOS
 */
int arv_cont_galho1(Arv* Contar)
{
	if (Contar == NULL)
		return 0;

	if (	((Contar->esq != NULL) && (Contar->dir == NULL)) ||
		((Contar->esq == NULL) && (Contar->dir != NULL))	)
		return (1 + arv_cont_galho1(Contar->esq) + arv_cont_galho1(Contar->dir));

	return (arv_cont_galho1(Contar->esq) + arv_cont_galho1(Contar->dir));
}

/**
 * @brief CONTAR GALHOS COM EXATAMENTE 2 FILHO
 *
 * @param Contar	ENDERECO DA ARVORE A SER ANALISADA
 * @return int		QUANTIDADE DE GALHOS
 */
int arv_cont_galho2(Arv* Contar)
{
	if (Contar == NULL)
		return 0;

	if ((Contar->esq != NULL) && (Contar->dir != NULL))
		return (1 + arv_cont_galho2(Contar->esq) + arv_cont_galho2(Contar->dir));

	return (arv_cont_galho2(Contar->esq) + arv_cont_galho2(Contar->dir));
}

/**
 * @brief CONTAR FOLHAS
 *
 * @param Contar	ENDERECO DA ARVORE A SER ANALISADA
 * @return int		QUANTIDADE DE FOLHAS
 */
int arv_cont_folha(Arv* Contar)
{
	if (Contar == NULL)
		return 0;

	if ((Contar->esq == NULL) && (Contar->dir == NULL))
		return 1;

	return (arv_cont_folha(Contar->esq) + arv_cont_folha(Contar->dir));
}

/**
 * @brief PREENCHE HISTOGRAMA DE ACORDO COM A FREQUENCIA DE LETRAS NA ARVORE
 *
 * @param Analisar	ARVORE A ANALISAR
 * @param histograma	ENDERECO DO HISTOGRAMA A EDITAR
 */
void arv_frequencia_c(Arv* Analisar, int* histograma)
{
	int c;

	if (arv_vazia(Analisar))
		return;

	for (c = 0; c < 26; c++)
	{
		if (Analisar->info == ('a' + c))
		{
			histograma[c]++;
			break;
		}
	}

	arv_frequencia_c(Analisar->esq, histograma);
	arv_frequencia_c(Analisar->dir, histograma);
}

/**
 * @brief INTERFACE PARA O USUARIO DEMONSTRANDO AS FUNCOES EM FUNCIONAMENTO
 */
void demonstracao()
{
	Arv* avri = arv_criavazia();
	int c, meuHistograma[26] = { 0 };

	avri = arv_insere_ordenado(avri, 'c');
	avri = arv_insere_ordenado(avri, 'a');
	avri = arv_insere_ordenado(avri, 'b');
	avri = arv_insere_ordenado(avri, 'd');
	avri = arv_insere_ordenado(avri, 'a');
	avri = arv_insere_ordenado(avri, 'b');
	arv_frequencia_c(avri, meuHistograma);
	printf("_________________________________________________\n");

	for (c = 0; c < 26; c++)
		printf("Aparicoes da letra '%c': %i\n", ('a' + c), meuHistograma[c]);

	printf("_________________________________________________\n");
	printf("Total de Folha: \t\t%i\n", arv_cont_folha(avri));
	printf("Total de Galhos com 1 filho: \t%i\n", arv_cont_galho1(avri));
	printf("Total de Galhos com 2 filhos: \t%i\n", arv_cont_galho2(avri));
	printf("_________________________________________________\n");
	printf("Pre-ordem:\n");
	arv_imprime_preordem(avri);
	printf("\nSimetria:\n");
	arv_imprime_simetrica(avri);
	printf("\nPos-ordem:\n");
	arv_imprime_posordem(avri);
	printf("\n_________________________________________________\n");
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
    demonstracao();

    return EXECUTADO_COM_EXITO;
}

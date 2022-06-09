/**
 * @file   main.c
 * @brief  ARQUIVO PRINCIPAL DO PROGRAMA PARA A PROVA 1
 * @author Inaue Ferreira da Silva
 * @date   05-07-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include "pilhas.h"
#include "fila2.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int         main		(int argc, char** argv);
void        interface_problema 	(void);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INTERFACE DO USUARIO
 */
void interface_problema(void)
{
	int instrucoes, i, inst, num, saidaL, saidaP, saidaF, saidaFpri; 
	Pilha_vet* testeP;
	Fila2* testeF;
	FilaL2* testeFpri;

	while(VERDADEIRO)
	{
		testeP = pilha_vet_cria();
		testeF = fila_cria_vet();
		testeFpri = fila_cria_l();

		scanf("%i", &instrucoes);

		for (i = 0; i < instrucoes; i++)
		{
			scanf("%i %i", &inst, &num);

			if (inst == 1)
			{
				pilha_vet_push(testeP, num);
				fila_insere_vet(testeF, num);
				fila_insere_l(testeFpri, num);
			}
			else
			{
				saidaP = pilha_vet_pop(testeP);
				saidaF = fila_retira_vet(testeF);
				saidaFpri = fila_retira_l(testeFpri);

				printf("%i\n", saidaP);
				printf("%i\n", saidaF);
				printf("%i\n", saidaFpri);
			}
		}

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

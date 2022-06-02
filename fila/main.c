/**
 * @file   main.c
 * @brief  Programa principal contendo a resolucao dos exercicios de fila
 * @author Inauê Ferreira da Silva
 * @date   05-dd-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

/*	CONSTANTES	*/
#define INSERIR		'i'
#define REMOVER		'r'
#define SAIR		's'
#define MAX_PLACA	(15 + 1)


/*	FUNCOES		*/
/*	*	*	*	*	*	*	*	*	*	*	*	*/
void estacionamento();

/*	*	*	*	*	*	*	*	*	*	*	*	*/
/**
 * @brief INTERFACE DO USUARIO PARA A RESOLUCAO DO PROBLEMA DO ESTACIONAMENTO
 */
void estacionamento()
{
	FilaL *CarrosEstacionados = fila_cria_l();
	char operacao, placaCarro[MAX_PLACA];
	char* carroFrente;

	do
	{	
		printf("________________________________________________________________\n");
		printf("Digite a operacao que deseja realizar no estacionamento:\n");
		printf("[%c] Inserir Carro\n", INSERIR);
		printf("[%c] Remover Carro\n", REMOVER);
		printf("[%c] Sair\n", SAIR);
		printf("________________________________________________________________\n");
		scanf(" %c", &operacao);

		if (operacao == INSERIR)
		{
			printf("Insira a placa do novo carro (max.: %i):\n", (MAX_PLACA - 1));
			scanf(" %s", placaCarro);
			fila_insere_l(CarrosEstacionados, placaCarro);
			
			printf("Novo estado do estacionamento:\n");
			fila_imprime_l(CarrosEstacionados);
		}
		else if (operacao == REMOVER)
		{
			printf("Insira a placa do carro a remover (max.: %i):\n", (MAX_PLACA - 1));
			scanf(" %s", placaCarro);
			carroFrente = fila_retira_l(CarrosEstacionados);
			printf("%s\n", carroFrente);
			printf("Novo estado do estacionamento:\n");
			fila_imprime_l(CarrosEstacionados);
		}
	} while(operacao != SAIR);

	fila_libera_l(CarrosEstacionados);
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
	estacionamento();

	return EXIT_SUCCESS;
}

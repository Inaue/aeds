/**
 * @file   main.c
 * @brief  Programa principal contendo a resolucao dos exercicios de fila
 * @author Inauê Ferreira da Silva
 * @date   06-06-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

/*	CONSTANTES	*/
#define INSERIR		'i'
#define REMOVER		'r'
#define SAIR		's'
#define TAMANHO_PLACA	4


/*	FUNCOES		*/
/*	*	*	*	*	*	*	*	*	*	*	*	*/
void estacionamento();
int main(int argc, char** argv);

/*	*	*	*	*	*	*	*	*	*	*	*	*/

/**
 * @brief INTERFACE DO USUARIO PARA A RESOLUCAO DO PROBLEMA DO ESTACIONAMENTO
 */
void estacionamento()
{
	Fila *CarrosEstacionados = fila_cria_vet();
	char operacao;
	int carroUsuario, carroFrente;

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
			printf("Insira a placa do novo carro (inteiro de %i digitos):\n", TAMANHO_PLACA);
			scanf(" %i", &carroUsuario);
			printf("Antigo estado do estacionamento:\n");
			fila_imprime_vet(CarrosEstacionados);
			fila_insere_vet(CarrosEstacionados, carroUsuario);
			printf("Novo estado do estacionamento:\n");
			fila_imprime_vet(CarrosEstacionados);
		}
		else if (operacao == REMOVER)
		{
			printf("Insira a placa do carro a remover (inteiro de %i digitos):\n", TAMANHO_PLACA);
			scanf(" %i", &carroUsuario);
			printf("Antigo estado do estacionamento:\n");
			fila_imprime_vet(CarrosEstacionados);
			carroFrente = fila_retira_vet(CarrosEstacionados);

			while (carroFrente != carroUsuario)
			{
				fila_insere_vet(CarrosEstacionados, carroFrente);
				carroFrente = fila_retira_vet(CarrosEstacionados);
			}
			printf("Novo estado do estacionamento:\n");
			fila_imprime_vet(CarrosEstacionados);
		}
	} while(operacao != SAIR);

	fila_libera_vet(CarrosEstacionados);
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

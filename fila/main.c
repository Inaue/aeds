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
#define INSERIR	'i'
#define REMOVER	'r'
#define SAIR	's'

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
	char operacao, placaCarro[maxx];

	do
	{
		printf("Digite a operacao que deseja realizar no estacionamento:\n");
		printf("[%c] Inserir Carro\n", INSERIR);
		printf("[%c] Remover Carro\n", REMOVER);
		printf("[%c] Sair\n", SAIR);
		scanf("%c", &operacao);

		if (operacao == INSERIR)
		{
			printf("Insira a placa do novo carro:\n");
			fgets(placaCarro, maxx, stdin);
		}
		else if (operacao == REMOVER)
		{
			printf("Insira a placa do carro a remover:\n");
			fgets(placaCarro, maxx, stdin);
		}
	} while(operacao != SAIR);
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

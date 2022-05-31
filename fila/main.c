/**
 * @file   main.c
 * @brief  Programa principal contendo a resolucao dos exercicios de fila
 * @author Inauê Ferreira da Silva
 * @date   05-dd-2022
 */

#include <stdio.h>
#include <stdlib.h>
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
	char opr;

	do
	{
		printf("Digite a operacao que deseja realizar no estacionamento:\n");
		printf("[%c] Inserir Carro\n", INSERIR);
		printf("[%c] Remover Carro\n", REMOVER);
		printf("[%c] Sair\n", SAIR);
		scanf("%c", &opr);
	} while(opr != SAIR);
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

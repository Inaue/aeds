/**
 * @file   main.c
 * @brief  Programa principal contendo a resolucao dos exercicios de fila
 * @author Inauê Ferreira da Silva
 * @date   05-dd-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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
	return EXIT_SUCCESS;
}

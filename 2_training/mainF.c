/**
 * @file   mainF.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE FILAS
 * @author Inaue Ferreira da Silva
 * @date   02-06-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include "fila.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define INSERIR			'i'
#define REMOVER			'r'
#define SAIR			's'
#define TAMANHO_PLACA	4

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int     main	        (int argc, char** argv);
void	exec7		    (void);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief RESOLUCAO DO EXERCICIO 7
 */
void exec7()
{
	char operacao;
	Carro CarroUsuario;
	FilaL* Idosos		= fila_cria_l();
	FilaL* NaoIdosos	= fila_cria_l();

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
			scanf(" %i", &(CarroUsuario.placa));
			printf("Insira a idade do motorista:\n");
			scanf(" %i", &(CarroUsuario.idadeMotorista));
			printf("Antigo estado do estacionamento:\n");
			fila_imprime_l(Idosos);
			fila_imprime_l(NaoIdosos);
			
			if (CarroUsuario.idadeMotorista > 60)
				fila_insere_ordenado_l(Idosos, CarroUsuario);
			else
				fila_insere_l(NaoIdosos, CarroUsuario);
			
			printf("Novo estado do estacionamento:\n");
			fila_imprime_l(Idosos);
			fila_imprime_l(NaoIdosos);
		}
		else if (operacao == REMOVER)
		{
			printf("Insira a placa do carro a remover (inteiro de %i digitos):\n", TAMANHO_PLACA);
			scanf(" %i", &(CarroUsuario.placa));
			printf("Antigo estado do estacionamento:\n");
			fila_imprime_l(Idosos);
			fila_imprime_l(NaoIdosos);

			if (fila_busca_l(Idosos, CarroUsuario) == NULL)
				fila_retira_v_l(NaoIdosos, CarroUsuario);
			else
				fila_retira_v_l(Idosos, CarroUsuario);

			printf("Novo estado do estacionamento:\n");
			fila_imprime_l(Idosos);
			fila_imprime_l(NaoIdosos);
		}
	} while(operacao != SAIR);

	fila_libera_l(Idosos);
	fila_libera_l(NaoIdosos);
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
    exec7();

    return EXECUTADO_COM_EXITO;
}

/**
 * @file   main.c
 * @brief  ARQUIVO PRINCIPAL DO PROGRAMA PARA A PROVA 1
 * @author Inaue Ferreira da Silva
 * @date   05-07-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include "pilhas.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*  CONSTANTES  */
#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int         main	                (int argc, char** argv);
void        interface_estacao_trem  (void);
void        pilha_vet_ler           (Pilha_vet* Pilha_Ler, int total_elementos);
Pilha_vet*  pilha_vet_inverte       (Pilha_vet* Pilha_inverter);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief LE, DO USUARIO, UMA PILHA DE TAMANHO PRE-DETERMINADO
 *
 * @param Pilha_Ler         PILHA ONDE ARMAZENAR OS DADOS LIDOS
 * @param total_elementos   ELEMENTOS A SEREM LIDOS 
 */
void pilha_vet_ler(Pilha_vet* Pilha_Ler, int total_elementos)
{
    int e;
    char elemento;

    for (e = 0; e < total_elementos; e++)
    {
        scanf(" %c", &elemento);
        pilha_vet_push(Pilha_Ler, elemento);
    }
}

/**
 * @brief VIRA UMA PILHA DE TRAZ PARA FRENTE
 *
 * @param   Pilha_inverter  PILHA A SER INVERTIDA
 * @return  Pilha_vet*      PILHA INVERTIDA
 */
Pilha_vet* pilha_vet_inverte(Pilha_vet* Pilha_inverter)
{
    Pilha_vet* Pilha_invertida = pilha_vet_cria();

    while (!pilha_vet_vazia(Pilha_inverter))
        pilha_vet_push(Pilha_invertida, pilha_vet_pop(Pilha_inverter));
    
    pilha_vet_libera(Pilha_inverter);

    return Pilha_invertida;
}

/**
 * @brief INTERFACE DO USUARIO
 */
void interface_estacao_trem(void)
{
    int vagoes;
    char vagao_da_frente, vagao_desejado;
    Pilha_vet* Trilho_A;
    Pilha_vet* Trilho_I;//TRILHO INTERMEDIARIO (ENTRE 'A' E 'B')
    Pilha_vet* Trilho_B;

    scanf(" %i", &vagoes);

    while (vagoes > 0)
    {
        Trilho_A = pilha_vet_cria();
        Trilho_I = pilha_vet_cria();
        Trilho_B = pilha_vet_cria();

        pilha_vet_ler(Trilho_A, vagoes);
        pilha_vet_ler(Trilho_B, vagoes);
        Trilho_A        = pilha_vet_inverte (Trilho_A);
        Trilho_B        = pilha_vet_inverte (Trilho_B);
        vagao_desejado  = pilha_vet_pop     (Trilho_B);
        pilha_vet_push(Trilho_I, pilha_vet_pop(Trilho_A));
        putchar('I');
        
        /* 
         * PARA A CORRETA MANIPULACAO DAS PILHAS DE 'A' E 'B',
         * O ALGORITMO DEVE LER SEUS ELEMENTOS NA ORDEM INVERSA
         * A QUE FORAM INSERIDOS
         */

        while (!pilha_vet_vazia(Trilho_I))
        {// E (VAGOES DIFERENTES E 'Trilho_A' NAO VAZIO)
            vagao_da_frente = pilha_vet_pop(Trilho_I);

            while ( (vagao_da_frente == vagao_desejado) &&
                    !pilha_vet_vazia(Trilho_B)          &&
                    !pilha_vet_vazia(Trilho_I)              )
            {
                vagao_desejado  = pilha_vet_pop(Trilho_B);
                vagao_da_frente = pilha_vet_pop(Trilho_I);
                putchar('R');
            }

            if (vagao_da_frente == vagao_desejado)
            {
                if (!pilha_vet_vazia(Trilho_B))
                    vagao_desejado = pilha_vet_pop(Trilho_B);
                
                putchar('R');
            }
            else
            {
                if (pilha_vet_vazia(Trilho_A))
                {
                    printf(" Impossible");
                    break;
                }
                else
                    pilha_vet_push(Trilho_I, vagao_da_frente);
            }
            
            if (!pilha_vet_vazia(Trilho_A))
            {
                pilha_vet_push(Trilho_I, pilha_vet_pop(Trilho_A));
                putchar('I');
            }
        }

        putchar('\n');
        pilha_vet_libera(Trilho_A);
        pilha_vet_libera(Trilho_I);
        pilha_vet_libera(Trilho_B);
        scanf(" %i", &vagoes);
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
    interface_estacao_trem();

    return EXECUTADO_COM_EXITO;
}

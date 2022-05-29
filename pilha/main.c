/**
 * @file   main.c
 * @brief  RESOLUCAO DOS EXERCICIOS DA AULA DE PILHAS
 * @author Inaue Ferreira da Silva
 * @date   04-30-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <string.h>
#include "pilhas.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0
#define MEMORIA_INSUFICIENTE    1

/*  CONSTANTES  */

#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO
#define MAX_EXPRESS (63 + 1)

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
int     main	                    (int argc, char** argv);
void    getStr                      (char* str, int size);
int     parentesesBemFormados       (char* expressao);
void    verificarExpressaoUsuario   (void);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INTERFACE PARA O USUARIO INSERIR EXPRESSAO E VALIDA-LA
 */
void    verificarExpressaoUsuario   (void)
{
    char expressaoUsuario[MAX_EXPRESS];

    printf("________________________________________________________________________\n");
    printf("Digite uma expressao (max.: %i caracteres):\n", (MAX_EXPRESS - 1));
    getStr(expressaoUsuario, MAX_EXPRESS);

    if (parentesesBemFormados(expressaoUsuario))
        printf("Parenteses da expressao estao bem formados!\n");
    else
        printf("Parenteses da expressao estao mal formados!\n");
    
    printf("________________________________________________________________________\n");
}

/**
 * @brief VALIDA A FORMACAO DE PARENTESES DA EXPRESSAO
 *
 * @param   expressao   EXPRESSAO ANALISADA
 * @return  int         0/FALSO = MA FORMACAO, 1/VERDADEIRO = PARENTESES BEM FORMADOS
 */
int     parentesesBemFormados   (char* expressao)
{
    int caractere;
    int tamanhoExpressao            = strlen(expressao);
    Pilha_lst* parentesesAbertos    = pilha_lst_cria();

    for (caractere = 0; caractere < tamanhoExpressao; caractere++)
    {
        switch (expressao[caractere])
        {
        case '(': pilha_lst_push(parentesesAbertos, '('); break;
        case ')':
            if (pilha_lst_vazia(parentesesAbertos))
            {
                pilha_lst_libera(parentesesAbertos);
                return FALSO;
            }
            
            pilha_lst_pop(parentesesAbertos);
            break;
        }
    }
    
    if (pilha_lst_vazia(parentesesAbertos))
    {
        pilha_lst_libera(parentesesAbertos);
    
        return VERDADEIRO;
    }
    else
    {
        pilha_lst_libera(parentesesAbertos);
    
        return FALSO;
        
    }
}

/**
 * @brief OBTEM STRING DO USUARIO E SUBSTITUI '\n' POR '\0'
 *
 * @param str   STRING
 * @param size  TAMANHO MAXIMO
 */
void getStr(char* str, int size)
{
    fgets(str, size, stdin);
    str[strlen(str) - 1] = '\0';
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
    verificarExpressaoUsuario();

    return EXECUTADO_COM_EXITO;
}

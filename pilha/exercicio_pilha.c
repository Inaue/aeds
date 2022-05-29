/**
 * @file   exercicio_pilha.c
 * @brief  RESOLUCAO DOS EXERCICIOS DA AULA SOBRE PILHAS
 * @author Inauê Ferreira da Silva
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

/*  TYPEDEFS    */

/*  ESTRUTURAS  */

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
int     main	                    (int argc, char** argv);
int     parentesesBemFormados       (char* expressao);
void    verificarExpressaoUsuario   (void);
void    getStr                      (char* str, int size);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INFORMA SE OS PARENTESES FORAM CORRETAMENTE INSERIDOS NA EXPRESSAO
 *
 * @param expressao EXPRESSAO ANALISADA
 * @return int      0/FALSO = PARENTESES MAL FORMADOS, 1/VERDADEIRO = PARENTESES BEM FORMADOS
 */
int parentesesBemFormados(char* expressao)
{
    int c;
    int tamanhoExpressao = strlen(expressao);
    Pilha_lst* parentesesAbertos = pilha_lst_cria();

    for (c = 0; c < tamanhoExpressao; c++)
    {
        switch (expressao[c])
        {
        case '(': pilha_lst_push(parentesesAbertos, expressao[c]); break;
        case ')':
            if (pilha_lst_vazia(parentesesAbertos))
                return FALSO;
            
            pilha_lst_pop(parentesesAbertos);
            break;
        }
    }

    pilha_lst_libera(parentesesAbertos);

    return VERDADEIRO;
}

/**
 * @brief INTERFACE PARA O USUARIO INSERIR EXPRESSAO E VERIFICAR FORMACAO
 */
void verificarExpressaoUsuario(void)
{
    char expressaoUsuario[MAX_EXPRESS];

    printf("___________________________________________________________\n");
    printf("Digite uma expressao (max.: %i caracteres):\n", (MAX_EXPRESS - 1));
    getStr(expressaoUsuario, MAX_EXPRESS);

    if (parentesesBemFormados(expressaoUsuario))
        printf("Sequencia de parenteses bem formada!\n");
    else
        printf("Sequencia de parenteses mal formada!\n");
    
    printf("___________________________________________________________\n");
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


    return EXECUTADO_COM_EXITO;
}
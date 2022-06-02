/**
 * @file   mainP.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE PILHAS
 * @author Inaue Ferreira da Silva
 * @date   01-06-2022
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
void    exec4                       (void);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/**
 * @brief INTERFACE PARA O USUARIO INSERIR EXPRESSAO E VALIDA-LA
 */
void    exec4   (void)
{
    char expressaoUsuario[MAX_EXPRESS];

    printf("________________________________________________________________________\n");
    printf("Digite uma expressao (max.: %i caracteres):\n", (MAX_EXPRESS - 1));
    getStr(expressaoUsuario, MAX_EXPRESS);

    if (parentesesBemFormados(expressaoUsuario))
        printf("Expressao esta bem formada!\n");
    else
        printf("Expressao esta mal formada!\n");
    
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
    int tamanhoExpressao    = strlen(expressao);
    Pilha_lst* Aberturas    = pilha_lst_cria();

    for (caractere = 0; caractere < tamanhoExpressao; caractere++)
    {
        switch (expressao[caractere])
        {
        case '(': pilha_lst_push(Aberturas, '('); break;
        case '[': pilha_lst_push(Aberturas, '['); break;
        case '{': pilha_lst_push(Aberturas, '{'); break;
        case ')':
            if (    pilha_lst_vazia(Aberturas) ||
                    (pilha_lst_pop(Aberturas) != '('))
            {
                pilha_lst_libera(Aberturas);
                return FALSO;
            }
            break;
        case ']':
            if (    pilha_lst_vazia(Aberturas) ||
                    (pilha_lst_pop(Aberturas) != '['))
            {
                pilha_lst_libera(Aberturas);
                return FALSO;
            }
            break;
        case '}':
            if (    pilha_lst_vazia(Aberturas) ||
                    (pilha_lst_pop(Aberturas) != '{'))
            {
                pilha_lst_libera(Aberturas);
                return FALSO;
            }
            break;
        
        }
    }
    
    if (pilha_lst_vazia(Aberturas))
    {
        pilha_lst_libera(Aberturas);
    
        return VERDADEIRO;
    }
    else
    {
        pilha_lst_libera(Aberturas);
    
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
    exec4();

    return EXECUTADO_COM_EXITO;
}

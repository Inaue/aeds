/**
 * @file   mainP.c
 * @brief  RESOLUCAO DOS EXERCICIOS DE PILHAS
 * @author Inaue Ferreira da Silva
 * @date   01-06-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilhas.h"

/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0
#define MEMORIA_INSUFICIENTE    1

/*  CONSTANTES  */

#define VERDADEIRO  (1 == 1)
#define FALSO       !VERDADEIRO
#define MAX_EXPRESS (63 + 1)
#define MAX_FRASE   (63 + 1)

/*  FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
int     main	                (int argc, char** argv);
void    exec4                   (void);
void    exec5			(void);
void    exec6                   (void);
int 	soma_positivos		(int x[], int n);
void    getStr                  (char* str, int size);
int     parentesesBemFormados   (char* expressao);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int soma_positivos(int x[], int n)
{
	int i, somatoria = 0;
	Pilha_lst* Termos = pilha_lst_cria();

	for (i = n; i > 0; i--)
	{
		if (x[i] > 0)
			pilha_lst_push(Termos, x[i]);
	}

	while (!pilha_lst_vazia(Termos))
		somatoria += pilha_lst_pop(Termos);

	pilha_lst_libera(Termos);

	return somatoria;
}

void exec6()
{
	int* vetor;
	int numeros, i;

    	printf("________________________________________________________________________\n");
	printf("Digite quantos termos deseja inserir no vetor:\n");
	scanf(" %i", &numeros);
	vetor = (int*)malloc(numeros*sizeof(int));
	for(i = 0; i < numeros; i++)
	{
		printf("Digite o %i termo:\n", (i+1));
		scanf(" %i", &(vetor[i]));
	}

	printf("O retorno da funcao eh %i\n", soma_positivos(vetor, numeros));
    	printf("________________________________________________________________________\n");
	free(vetor);
}

/**
 * @brief RESOLUCAO DO EXERCICIO 5
 */
void	exec5	(void)
{
	char frase[MAX_FRASE], tamanho;
    	Pilha_lst* CaracteresFrase = pilha_lst_cria();
	int caractere, ePalindromo = VERDADEIRO;

    	printf("________________________________________________________________________\n");
	printf("Digite uma frase (max.: %i):\n", (MAX_FRASE - 1));
	getStr(frase, MAX_FRASE);
	tamanho = strlen(frase);

	for (caractere = 0; caractere < tamanho; caractere++)
    	{
       		if (isalnum(frase[caractere]))
     			pilha_lst_push(CaracteresFrase, frase[caractere]);
    	}

    for (caractere = 0; caractere < tamanho; caractere++)
    {
        if (isalnum(frase[caractere]))
            ePalindromo = ePalindromo && (pilha_lst_pop(CaracteresFrase) == frase[caractere]);
    }

    if (ePalindromo)
        printf("A frase digitada eh um palindromo!\n");
    else
        printf("A frase digitada nao eh um palindromo.\n");

    printf("________________________________________________________________________\n");

    pilha_lst_libera(CaracteresFrase);
}

/**
 * @brief RESOLUCAO DO EXERCICIO 4
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
    exec6();

    return EXECUTADO_COM_EXITO;
}

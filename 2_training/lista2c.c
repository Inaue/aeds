#include <stdio.h>
#include <stdlib.h>
#include "lista2c.h"

void lst2_circ_imprime(Lst2 *l){
	Lst2 *p=l;

	if(p!=NULL){
		do{
			printf("%d ", p->info);
			p=p->prox;
		} while(p!=l);
	}
	putchar('\n');
}

Lst2 *lst2_circ_transforma(Lst2 *l){
	Lst2 *p=l;
	
	if(l!=NULL){
		while(p->prox!=NULL)
			p=p->prox;

		p->prox=l;
		l->ant=p;
	}

	return l;
}

void lst2_circ_libera(Lst2 *l){
	Lst2 *t;
	Lst2 *p = l;

	while(p != l){
		t = p->prox;
		free(p);
		p=t;
	}
}

Lst2 *lst2_circ_insere_ordenada(Lst2 *l, int v){
	Lst2* novo = (Lst2*)malloc(sizeof(Lst2));
	Lst2* posInserir;

	novo->info=v;

	if(l==NULL)
	{
		novo->ant=novo;
		novo->prox=novo;
		
		return novo;
	}
	else
	{
		for (posInserir=l; !((posInserir->info<v) && (posInserir->prox->info>=v)) && (posInserir->prox!=l); posInserir=posInserir->prox);

		posInserir->prox->ant=novo;
		novo->prox=posInserir->prox;
		posInserir->prox=novo;
		novo->ant=posInserir;
	}

	if (l->info>novo->info)
		return novo;

	return l;
}

Lst2* lst2_cria()
{
	return NULL;
}
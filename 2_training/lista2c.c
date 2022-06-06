#include <stdio.h>
#include <stdlib.h>

/*  LISTA DUPLAMENTE ENCADEADA   */
struct lst2{
	int info;
	struct lst2 *ant;
	struct lst2 *prox;
};

typedef struct lst2 Lst2;

/*listas circulares*/
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

Lst2 *lst_circ_insere(Lst2 *l, int v){
	Lst2* novo = (Lst2*)malloc(sizeof(Lst2));
	Lst2* UltimoLst;

	novo->prox=l;
	novo->info=v;

	if(l==NULL)
		novo->ant=NULL;
	else
	{
		for (UltimoLst = l; UltimoLst->prox != l; UltimoLst = UltimoLst->prox);

		l->ant=novo;
	}

	return novo;
}

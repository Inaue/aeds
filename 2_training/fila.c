#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int incr(int i){
	return (i+1)%N;
}

Fila *fila_cria_vet(){
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere_vet(Fila *f, int v){
	int fim;
	if(f->n == N){
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->vet[fim] = v;
	f->n++;
}

int fila_retira_vet(Fila *f){
	int v;
	if(fila_vazia_vet(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	v=f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int fila_vazia_vet(Fila *f){
	return (f->n == 0);
}

void fila_libera_vet(Fila *f){
	free(f);
}


FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL *f,Carro v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	n->info=v;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

Carro fila_retira_l(FilaL *f){
	Lista *t;
	Carro v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(FilaL *f){
	return (f->ini == NULL);
}

void fila_libera_l(FilaL *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

Lista* fila_busca_l(FilaL *fila, Carro informacao){
	Lista *q;
	for(q=fila->ini; q!=NULL; q=q->prox){
		if(q->info.placa==informacao.placa){
			return q;
		}
	}
	return NULL;
}

void fila_imprime_vet(Fila *f){
	int i;
	for(i=0;i<f->n; i++) printf("%i \n", f->vet[(f->ini+i)%N]);
}

void fila_imprime_l(FilaL *f){
	Lista *q;
	for(q=f->ini; q!= NULL; q=q->prox)
		printf("\tPlaca : %i, Idade do Motorista : %i\n",q->info.placa, q->info.idadeMotorista);
}

void fila_insere_ordenado_l(FilaL *f, Carro v){
	Carro Inicio;

	if (fila_vazia_l(f))
		fila_insere_l(f, v);
	else if (	(f->ini == f->fim) &&
			(v.idadeMotorista > f->ini->info.idadeMotorista)	)
	{
		fila_insere_l(f, v);
		fila_insere_l(f, fila_retira_l(f));
	}
	else if (v.idadeMotorista > f->ini->info.idadeMotorista)
	{
		fila_insere_l(f, v);

		while (f->ini->info.placa != v.placa)
			fila_insere_l(f, fila_retira_l(f));
	}
	else
	{
		Inicio = f->ini->info;
		fila_insere_l(f, fila_retira_l(f));

		while(	(f->ini->info.idadeMotorista > v.idadeMotorista) &&
			(f->ini->info.placa != Inicio.placa)	)
			fila_insere_l(f, fila_retira_l(f));

		fila_insere_l(f, v);

		while(f->ini->info.placa != Inicio.placa)
			fila_insere_l(f, fila_retira_l(f));
	}
}

void fila_retira_v_l(FilaL *f, Carro v){
	Carro Inicio = f->ini->info;

	if (fila_vazia_l(f))
		return;
	else if ((f->ini==f->fim) && (f->ini->info.placa == v.placa))
		fila_retira_l(f);
	else if (f->ini->info.placa == v.placa)
		fila_retira_l(f);
	else
	{
		fila_insere_l(f, fila_retira_l(f));

		while ((f->ini->info.placa != v.placa) && (f->ini->info.placa != Inicio.placa))
			fila_insere_l(f, fila_retira_l(f));

		if(f->ini->info.placa == v.placa)
			fila_retira_l(f);

		while (f->ini->info.placa != Inicio.placa)
			fila_insere_l(f, fila_retira_l(f));
	}
}


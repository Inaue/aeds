#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila2.h"



static int incr(int i){
	return (i+1)%N;
}

Fila2 *fila_cria_vet(){
	Fila2 *f = (Fila2*) malloc(sizeof(Fila2));
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere_vet(Fila2 *f, int v){
	int fim;
	if(f->n==N){
		printf("Capacidade estourou\n");
		return;
	}
	fim=(f->ini + f->n) % N;
	f->vet[fim]=v;
	f->n++;
}

void fila_insere_ini_vet(Fila2*f, int v){
	int prec;
	if(f->n==N){
		printf("Capacidade estourou\n");
		return;
	}

	prec=(f->ini-1 + N)%N;
	f->vet[prec]=v;
	f->ini=prec;
	f->n++;
}

int fila_retira_fim_vet(Fila2 *f){
	int ult;
	int v;
	if(fila_vazia_vet(f)){
		printf("Fila vazia\n");
		exit(1);
	}
	ult=(f->ini + f->n -1) % N;
	v=f->vet[ult];
	f->n--;
	return v;
}

int fila_retira_vet(Fila2*f){
	int v;
	if(fila_vazia_vet(f)){
		printf("Fila2vazia!\n");
		exit(1);
	}
	v=f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int fila_vazia_vet(Fila2*f){
	return (f->n == 0);
}

void fila_libera_vet(Fila2*f){
	free(f);
}

// Funções de impressão

void fila_imprime_vet(Fila2*f){
	int i;
	for(i=0;i<f->n; i++) printf("%i \n", f->vet[(f->ini+i)%N]);
}


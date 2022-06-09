#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Pilhas com vetor
Pilha_vet *pilha_vet_cria() {
	Pilha_vet *p = (Pilha_vet *) malloc(sizeof(Pilha_vet));
	p->n = 0;

	return p;
}

void pilha_vet_push(Pilha_vet *p, int v) {
	if (p->n == N) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n++] = v;
}

int pilha_vet_pop(Pilha_vet *p) {
	if (pilha_vet_vazia(p)) {
		printf("Pilha vazia.");
		exit(1);
	}

	return p->vet[--p->n];
}

int pilha_vet_vazia(Pilha_vet *p) {
	return (p->n == 0);
}

void pilha_vet_libera(Pilha_vet *p) {
	free(p);
}

void pilha_vet_imprime(Pilha_vet *p){
	int i;

	for(i=p->n-1;i>=0;i--){
		printf("%i\n", p->vet[i]);
	}
}


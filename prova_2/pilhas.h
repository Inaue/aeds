#define N 1000

typedef struct pilha_vet {
	int n;
	char vet[N];
} Pilha_vet;

Pilha_vet *pilha_vet_cria();
void pilha_vet_push(Pilha_vet *p, char v);
char pilha_vet_pop(Pilha_vet *p);
int pilha_vet_vazia(Pilha_vet *p);
void pilha_vet_libera(Pilha_vet *p);
void pilha_vet_imprime(Pilha_vet *p);


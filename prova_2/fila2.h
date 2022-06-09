#define M 1000

struct fila{
	int n;
	int ini;
	int vet[M];
};

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

struct filal{
	Lista *ini;
	Lista *fim;
};



typedef struct fila Fila2;
typedef struct filal FilaL2;


Fila2 *fila_cria_vet();
void fila_insere_vet(Fila2 *f, int v);
int fila_retira_vet(Fila2 *f);
int fila_vazia_vet(Fila2 *f);
void fila_libera_vet(Fila2 *f);
void fila_insere_ini_vet(Fila2*f, int v);
int fila_retira_fim_vet(Fila2 *f);
void fila_imprime_vet(Fila2*f);

FilaL2 *fila_cria_l();
void fila_insere_l(FilaL2 *f, int v);
int fila_retira_l(FilaL2 *f);
int fila_vazia_l(FilaL2 *f);
void fila_libera_l(FilaL2 *f);
void fila_imprime_l(FilaL2 *f);
Lista* fila_busca_l(FilaL2 *fila, int informacao);
void fila_insere_ini_l(FilaL2 *fila, int v);
int fila_retira_fim_l(FilaL2 *fila);

#define N 10000

struct fila{
	int n;
	int ini;
	int vet[N];
};

struct carro
{
	int placa;
	int idadeMotorista;
};
typedef struct carro Carro;

struct lista{
	Carro info;
	struct lista *prox;
};
typedef struct lista Lista;

struct filal{
	Lista *ini;
	Lista *fim;
};



typedef struct fila Fila;
typedef struct filal FilaL;


Fila *fila_cria_vet();
void fila_insere_vet(Fila *f, int v);
int fila_retira_vet(Fila *f);
int fila_vazia_vet(Fila *f);
void fila_libera_vet(Fila *f);
void fila_imprime_vet(Fila *f);

FilaL *fila_cria_l();
void fila_insere_l(FilaL *f, Carro v);
Carro fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);
void fila_imprime_l(FilaL *f);
Lista* fila_busca_l(FilaL *fila, Carro informacao);
void fila_insere_ordenado_l(FilaL *f, Carro v);
void fila_retira_v_l(FilaL *f, Carro v);
#define N 1000

struct fila{
	int n;
	int ini;
	float vet[N];
};

typedef struct fila Fila2;
typedef struct filal FilaL2;


Fila2 *fila_cria_vet();
void fila_insere_vet(Fila2 *f, float v);
float fila_retira_vet(Fila2 *f);
int fila_vazia_vet(Fila2 *f);
void fila_libera_vet(Fila2 *f);
void fila_insere_ini_vet(Fila2*f, float v);
float fila_retira_fim_vet(Fila2 *f);
void fila_imprime_vet(Fila2*f);


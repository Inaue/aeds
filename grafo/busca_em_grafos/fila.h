#include "lista.h"

struct filal{
	Lista *ini;
	Lista *fim;
};



typedef struct fila Fila;
typedef struct filal FilaL;

FilaL *fila_cria_l();
void fila_insere_l(FilaL *f, int v);
int fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);

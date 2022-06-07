struct lst2{
	int info;
	struct lst2 *ant;
	struct lst2 *prox;
};

typedef struct lst2 Lst2;

void lst2_circ_imprime(Lst2 *l);
Lst2 *lst2_circ_transforma(Lst2 *l);
void lst2_circ_libera(Lst2 *l);
Lst2 *lst2_circ_insere_ordenada(Lst2 *l, int v);
Lst2 *lst2_cria(void);
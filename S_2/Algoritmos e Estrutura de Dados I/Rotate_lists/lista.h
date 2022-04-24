typedef struct reg celula;
struct reg {
    int conteudo;
    struct reg *prox;
};
void imprima(celula *le);
void insere_final(celula **p, int v);
void limpar(celula **ini);
void rotaciona(celula **ini, int qtde);
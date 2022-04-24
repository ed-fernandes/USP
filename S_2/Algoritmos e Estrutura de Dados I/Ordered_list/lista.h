typedef struct node {
    int id;
    char nome[50];
    struct node *prox;
} lista;
char *read_line(int *aux);
void limpar(lista **ini);
lista *cria();
void insere(lista **p);
void remover(lista **inicio);
void imprimir(lista *inicio) ;
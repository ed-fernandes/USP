typedef struct node {
    int valor;
    struct node *prox;
    struct node *ant;
} No;
typedef struct lista {
    int sinal;
    int tamanho;
    No *inicio;
    No *fim;
} lista;
char *read_line();
void insere_final(No **p, int v);
void imprime(lista *q);
lista *insere();
void libera(No **p);
int verifica(lista *num1, lista *num2);
void maiorque(lista *num1, lista *num2);
void igualdade(lista *num1, lista *num2);
void verificasoma(lista *num1, lista *num2);
void soma(lista *num1, lista *num2);
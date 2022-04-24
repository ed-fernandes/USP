typedef struct node link;
struct node {
    int id;
    int valor;
    link *esq;
    link *dir;
};
link *criaNo();
void inserirNo(link **arv, int id, int value, int esq, int dir);
int verifica(link *arv, int cont);
void limpa(link **arv);
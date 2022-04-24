struct No {
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;
char *read_line();
void inserir(No **pRaiz, int numero);
void emOrdem(No *pRaiz);
void preOrdem(No *pRaiz);
void posOrdem(No *pRaiz);
void criarArvore(No **pRaiz);
void limparArvore(No **pRaiz);
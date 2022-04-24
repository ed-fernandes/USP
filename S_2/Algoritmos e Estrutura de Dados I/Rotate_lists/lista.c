#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
// Método que imprime a lista ligada
void imprima(celula *le) {
    celula *p;
    for (p = le; p != NULL; p = p->prox) printf("%d ", p->conteudo);
    printf("\n");
}
// Método que insere um nó no final da lista a partir de um nó inicial;
void insere_final(celula **p, int v) {
    celula *aux, *q;
    q = (celula *)malloc(sizeof(celula));
    q->conteudo = v;
    q->prox = NULL;

    if (*p == NULL) {
        *p = q;
    } else {
        aux = *p;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = q;
    }
}
// Método para limpar lista ligada
void limpar(celula **ini) {
    celula *p;
    p = *ini;

    while (p != NULL) {
        *ini = (*ini)->prox;
        free(p);
        p = *ini;
    }
}
// Método para rotacionar lista ligada
void rotaciona(celula **ini, int qtde) {
    celula *p;
    int x = qtde;
    celula *f;

    while (x > 0) {
        p = *ini;

        while (p->prox->prox != NULL) {
            p = p->prox;
        }
        
        f = p->prox;
        p->prox = NULL;
        f->prox = *ini;
        x--;
        *ini = f;
    }
}
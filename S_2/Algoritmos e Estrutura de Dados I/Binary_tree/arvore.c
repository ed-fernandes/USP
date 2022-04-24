#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
link *criaNo() {
    link *p = malloc(sizeof(link));
    p->esq = NULL;
    p->dir = NULL;
    return p;
}
// método pra inserir um Nó
void inserirNo(link **arv, int id, int value, int esq, int dir) {
    if ((*arv) != NULL) {
        if ((*arv)->id == id || id == 0) {
            (*arv)->id = id;
            (*arv)->valor = value;
            if (esq != -1) {
                (*arv)->esq = criaNo();
                (*arv)->esq->id = esq;
            }
            if (dir != -1) {
                (*arv)->dir = criaNo();
                (*arv)->dir->id = dir;
            }
            return;
        } else {
            inserirNo(&(*arv)->esq, id, value, esq, dir);
            inserirNo(&(*arv)->dir, id, value, esq, dir);
        }
    }
}
// função recursiva que percorre a árvore e retorna a quantidade de vezes que a soma dos
// valores dos filhos é igual do pai
int verifica(link *arv, int cont) {
    int aux = cont;
    if (arv != NULL) {
        if (arv->esq != NULL && arv->dir != NULL) {
            int a = arv->valor;
            int b = arv->esq->valor + arv->dir->valor;
            if (a == b) {
                aux++;
            }
            aux = verifica(arv->esq, aux);
            aux = verifica(arv->dir, aux);
        } else if (arv->esq == NULL && arv->dir == NULL) {
            aux++;
        } else {
            if (arv->esq == NULL && arv->dir->valor == arv->valor) {
                aux++;
                aux = verifica(arv->dir, aux);
            }
            if (arv->dir == NULL && arv->esq->valor == arv->valor) {
                aux++;
                aux = verifica(arv->esq, aux);
            }
        }
    }
    return aux;
}
//método recursivo que limpa a árvore binária
void limpa(link **arv){
    if ((*arv) != NULL){
        limpa(&(*arv)->esq);
        limpa(&(*arv)->dir);
        free(*arv);
    }
}
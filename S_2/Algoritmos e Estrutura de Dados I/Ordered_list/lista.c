#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define INS "INSERE"
#define REM "REMOVE"
#define IMP "IMPRIMIR"
char *read_line(int *aux) {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != ' ' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\n' && *(vetorHeap + j) != '\r') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    if(vetorHeap[j]==EOF){
        *aux = 1;
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
void limpar(lista **ini) {
    lista *p;
    p = *ini;
    while (p != NULL) {
        *ini = (*ini)->prox;
        free(p);
        p = *ini;
    }
}
lista *cria() {
    lista *p = malloc(sizeof(lista));
    scanf("%d %[^\r\n]", &p->id, p->nome);
    p->prox = NULL;
    return p;
}
void insere(lista **p) {
    lista *q = cria();
    if (*p == NULL) {  // lista vazia
        *p = q;
    } else {
        lista *aux = *p;
        if (aux->id > q->id) {  // verifica o primeiro
            *p = q;
            q->prox = aux;
            return;
        } else if (aux->id == q->id) {
            printf("INVALIDO\n");
            return;
        }
        while (aux->prox != NULL) {  // percorre a lista
            if (aux->prox->id > q->id) {
                break;
            } else if (aux->prox->id == q->id) {
                printf("INVALIDO\n");
                return;
            }
            aux = aux->prox;
        }
        q->prox = aux->prox;
        aux->prox = q;
    }
}
void remover(lista **inicio) {
    int num;
    scanf("%d", &num);
    lista *p = *inicio;
    if(p!=NULL){
        if (p->id == num) {
            *inicio = (*inicio)->prox;
            free(p);
            return;
        }
        while (p->prox != NULL) {
            if (p->prox->id == num) {
                lista *aux = p->prox;
                p->prox = aux->prox;
                free(aux);
                return;
            }
            p = p->prox;
        }
    }
    printf("INVALIDO\n");
}
void imprimir(lista *inicio) {
    lista *p = inicio;
    int aux = 0;
    while (p != NULL) {
        printf("%d, %s; ", p->id, p->nome);
        p = p->prox;
        aux++;
    }
    if (aux == 0) printf("VAZIA");
    printf("\n");
}
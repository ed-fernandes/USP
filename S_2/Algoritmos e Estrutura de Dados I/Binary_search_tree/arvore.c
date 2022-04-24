#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// funcao para leitura de caracteres ate algum espaco, quebra de linha ou fim de arquivo
char *read_line() {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != ' ' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\n' && *(vetorHeap + j) != '\r') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    if(vetorHeap[j]=='\r'){
        getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
// metodo recusivo de insercao de No numa Arvore Binaria de Busca
void inserir(No **pRaiz, int numero) {
    if (*pRaiz == NULL) {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    } else {
        if (numero < (*pRaiz)->numero) {
            inserir(&(*pRaiz)->esquerda, numero);
        }
        if (numero > (*pRaiz)->numero) {
            inserir(&(*pRaiz)->direita, numero);
        }
    }
}
// Metodos de impressao
void emOrdem(No *pRaiz) {
    if (pRaiz != NULL) {
        emOrdem(pRaiz->esquerda);
        printf("%d ", pRaiz->numero);
        emOrdem(pRaiz->direita);
    }
}
void preOrdem(No *pRaiz) {
    if (pRaiz != NULL) {
        printf("%d ", pRaiz->numero);
        preOrdem(pRaiz->esquerda);
        preOrdem(pRaiz->direita);
    }
}
void posOrdem(No *pRaiz) {
    if (pRaiz != NULL) {
        posOrdem(pRaiz->esquerda);
        posOrdem(pRaiz->direita);
        printf("%d ", pRaiz->numero);
    }
}
void criarArvore(No **pRaiz) {
    *pRaiz = NULL;
}
// Liberar memoria
void limparArvore(No **pRaiz) {
    if ((*pRaiz) != NULL) {
        limparArvore(&(*pRaiz)->esquerda);
        limparArvore(&(*pRaiz)->direita);
        free(*pRaiz);
    }
}
#include "pessoas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 // funcao para ler cada linha reaproveitada de exemplos anteriores
char *read_line() {
    scanf("%*[\r\n]s");
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\r' && *(vetorHeap + j) != ' ') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
// função que insere uma pessoa na fila
pessoa *entra(int *qtde, pessoa *p) {
    (*qtde)++;
    p = realloc(p, *qtde * sizeof(pessoa));
    p[*qtde - 1].nome = read_line();
    scanf("%i %i", &p[*qtde - 1].idade, &p[*qtde - 1].condicao);

    if (p[*qtde - 1].idade >= 60 && p[*qtde - 1].condicao) {
        p[*qtde - 1].prioridade = 1;
    } else if (p[*qtde - 1].condicao) {
        p[*qtde - 1].prioridade = 2;
    } else if (p[*qtde - 1].idade >= 60) {
        p[*qtde - 1].prioridade = 3;
    } else {
        p[*qtde - 1].prioridade = 4;
    }
    return p;
}
// checando por ordem de prioridade na fila
void checarPrioridade(pessoa *p, int qtde) {
    if (qtde == 1) {
        return;
    }
    for (int i = qtde - 1; i > 0; i--) {
        if (p[i].prioridade < p[i - 1].prioridade) {
            pessoa aux;
            aux = p[i];
            p[i] = p[i - 1];
            p[i - 1] = aux;
        }
    }
}
// retirando pessoa da fila
pessoa *sai(int *qtde, pessoa *p) {

    if ((*qtde) != 0) {
        printf("%s %i %i\n", p[0].nome, p[0].idade, p[0].condicao);
        (*qtde)--;
        for (int i = 0; i < *qtde; i++) {
            pessoa aux;
            aux = p[i];
            p[i] = p[i + 1];
            p[i + 1] = aux;
        }
        free(p[*qtde].nome);
        p = realloc(p, *qtde * sizeof(pessoa));
    } else {
        printf("FILA VAZIA\n");
    }
    return p;
}
// limpando memória
void limpar(pessoa *p, int total) {
    for (int i = 0; i < total; i++) {
        free(p[i].nome);
    }
    free(p);
}
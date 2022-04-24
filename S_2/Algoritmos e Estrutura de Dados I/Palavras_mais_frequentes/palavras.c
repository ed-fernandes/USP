#include "palavras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *read_line(int *flinha, int *eof) {  // funcao para ler cada linha reaproveitada de exemplos anteriores
    scanf("%*[\r\n]s");
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\r' && *(vetorHeap + j) != ' ') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    if (vetorHeap[j] == '\n') {
        *flinha = 1;
    } else if (vetorHeap[j] == '\r') {
        *flinha = 1;
    } else if (vetorHeap[j] == EOF) {
        *eof = 1;
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}

void insertionSort(verbete *palavras, int qtde) {
    int x, y;
    verbete chave;
    for (x = 1; x < qtde; x++) {
        chave = palavras[x];
        y = x - 1;
        while (y >= 0 && palavras[y].cont < chave.cont) {
            palavras[y + 1] = palavras[y];
            y = y - 1;
        }
        palavras[y + 1] = chave;
    }
}
void calcularRepeticoes(verbete *palavras, int *qtde) {
    for (int i = 0; i < *qtde; ++i) {
        for (int j = i; j < *qtde; ++j) {
            if (strcmp(palavras[i].palavra, palavras[j].palavra) == 0 && palavras[j].controle == 0) {
                palavras[j].controle = 1;
                palavras[i].cont++;
            }
        }
    }
}

void ordenar(verbete *palavras, int qtde) {
    verbete auxiliar;
    auxiliar.palavra = NULL;
    for (int i = 0; i < qtde; ++i) {
        for (int j = i + 1; palavras[i].cont == palavras[j].cont; ++j) {
            if (strcmp(palavras[i].palavra, palavras[j].palavra) > 0) {
                auxiliar = palavras[i];
                palavras[i] = palavras[j];
                palavras[j] = auxiliar;
            }
        }
    }
}

void printString(verbete *palavras, int qtde, int printRep) {
    for (int i = 0; i < qtde; ++i) {
        printf("%s", palavras[i].palavra);
        if (printRep) {
            printf(" %d\n", palavras[i].cont);
        } else {
            printf("\n");
        }
    }
}
void limpar(verbete *palavras, int total) {
    for (int i = 0; i < total; i++) {
        free(palavras[i].palavra);
    }
    free(palavras);
}
#include "substring.h"

#include <stdio.h>
#include <stdlib.h>
char *read_line(int *tam) {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF) {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    *tam = j;
    if (vetorHeap[j] != EOF) {
        vetorHeap[j] = '\0';
    }
    return vetorHeap;
}
frase *criar() {
    frase *f = malloc(sizeof(frase));
    f->total = read_line(&f->tam_frase);
    f->errado = read_line(&f->tam_errado);
    f->certo = read_line(&f->tam_certo);
    return f;
}
void destruir(frase *f) {
    free(f);
    f = NULL;
}
int ultimo(frase *f) {
    if (f != NULL) {
        if (f->certo[f->tam_certo] == EOF) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}
void trocar(frase *f) {
    if(f->tam_frase!=0){
        for (int i = 0; i < f->tam_frase; i++) {
            int aux = 0;
            for (int j = 0; j < f->tam_errado; j++) {
                if (f->total[i] == f->errado[j]) {
                    i++;
                    aux++;
                } else {
                    i -= aux;
                    break;
                }
            }
            if (aux != f->tam_errado) {
                printf("%c", f->total[i]);
            } else {
                i--;
                f->certo[f->tam_certo] = '\0';
                printf("%s", f->certo);
            }
        }
        printf("\n");
    }
}
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *read_line(int *tamanho) {  // funcao para ler cada linha
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    int aux = 0;  // numero de caracteres
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '$') {
        aux++;
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    vetorHeap[j] = '\0';
    *tamanho = aux;
    return vetorHeap;
}
int main() {
    char *frase = NULL;                // frase completa
    char *palavra = NULL;              // palavra tabu
    int tamfrase = 0;                  // qtde de caracteres na frase
    int tampalavra = 0;                // qtde de de caracteres na palavra tabu
    palavra = read_line(&tampalavra);  // lendo ambas e informando o numero de caracteres em cada uma
    frase = read_line(&tamfrase);
    char *ponteiro = malloc(sizeof(tamfrase));  // ponteiro auxiliar para fins de comparação
    int vezes = 0;                           // qtde de vezes que a palavra é encontrada
    for (int k = 0; k < (tamfrase - tampalavra + 1); k++) {
        for (int i = 0; i < tampalavra; i++) {  // esse for vai rodar N vezes, onde N é o tamanho da palavra tabu
            ponteiro[i] = frase[k + i];            // ponteiro auxiliar recebe cada caracter da frase original
        }
        ponteiro[tampalavra] = '\0';
        if (strcmp(ponteiro, palavra) == 0) {
            vezes++;
        }
    }
    printf("A palavra tabu foi encontrada %d vezes\nFrase: ", vezes);
    for (int k = 0; k < tamfrase; k++) {
        for (int i = 0; i < tampalavra; i++) {
            if (k + i < tamfrase) {
                ponteiro[i] = frase[k + i];
            }
        }
        ponteiro[tampalavra] = '\0';
        if (strcmp(ponteiro, palavra) == 0) {  // palavra igual à parte analisada
            k = k + tampalavra - 1;
        } else {
            printf("%c", frase[k]);
        }
    }
    free(palavra);
    free(frase);
    free(ponteiro);
    return 0;
}
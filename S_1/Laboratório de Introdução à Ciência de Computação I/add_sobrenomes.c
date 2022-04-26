#include <stdio.h>
#include <stdlib.h>
char *read_line(int *ponteiro, int *espaco, int *tamanho) {  // funcao para retornar frase e modificar o endereço para o qual o ponteiro aponta
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    int aux = 0;
    int aux2 = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '$') {
        aux2++;
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));  // cria espaços para letras
        j++;
        *(vetorHeap + j) = getchar();
        if (vetorHeap[j] == ' ') {
            aux++;
        }
    }
    if (vetorHeap[j] == '$') {
        *ponteiro = 1;
    } else {
        *ponteiro = 0;
    }
    *espaco = aux;
    *tamanho = aux2;
    vetorHeap[j] = '\0';
    return vetorHeap;
}
int main() {
    int aux = 0, i = 0; // auxiliar, e qtde de linhas
    char **matrizHeap = malloc(sizeof(char *));
    int *espacos = malloc(sizeof(int));
    int *tamanhos = malloc(sizeof(int));
    while (aux != 1) {  // quando encontrar um $, ele vira 1, então para o loop
        espacos = realloc(espacos, (i + 1) * sizeof(int)); // realocando memória no ponteiro que indica a quantidade de espaços em cada linha
        tamanhos = realloc(tamanhos, (i + 1) * sizeof(int)); // realocando memória no ponteiro que indica a quantidade de caracteres em cada linha
        matrizHeap = realloc(matrizHeap, (i + 1) * sizeof(char *)); // realocando conforme a "quantidade" novas linhas
        matrizHeap[i] = read_line(&aux, &espacos[i], &tamanhos[i]);  // matriz recebe cada frase e passa como parametro o endereço da auxiliar
        i++;                                                         // numero de linhas
    }
    int whatever = i;
    for (int j = 0; j < whatever; j++) {
        printf("%s", matrizHeap[j]);
        if (j % 2 == 1) {                   // se for par tem q aparecer o ultimo nome do anterior
            int tamanho = tamanhos[j - 1];  // comprimento do vetor anterior
            int qtde = 0;                   // qtde de espaços no vetor em questão
            for (i = 0; i < tamanho; i++) {
                if (matrizHeap[j - 1][i] == ' ') {
                    qtde++;
                }
                if (qtde == espacos[j - 1]) {
                    printf("%c", matrizHeap[j - 1][i]);
                }
            }
            qtde = 0;
        }
        printf("\n");
    }
    for (int k = 0; k < whatever; k++) {
        free(matrizHeap[k]);
    }
    free(matrizHeap);
    free(espacos);
    free(tamanhos);
    return 0;
}
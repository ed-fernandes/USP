#include <stdio.h>
#include <stdlib.h>
void pad1(int padding) { // funcao auxiliar
    for (int i = 0; i < padding; i++) {
        printf("0 ");
    }
}
void pad2(int padding, int coluna){ // funcao auxiliar
    for (int i = 0; i < padding; i++) {
        pad1(2*padding + coluna);
        printf("\n");
    }
}
void printPad(int **matriz, int linha, int coluna, int padding){ // "Adiciona" bordas na matriz
    pad2(padding, coluna);//Adicionando bordas na matriz.
    for (int l = 0; l < linha; l++) {
        pad1(padding);
        for (int c = 0; c < coluna; c++) {
            printf("%d ",matriz[l][c]);
        }
        pad1(padding);
        printf("\n");
    }
    pad2(padding, coluna);
}
int main() {
    int linha, coluna;
    scanf("%d\n%d", &coluna, &linha);
    int **matrizHeap = malloc(linha * sizeof(int *));
    for (int l = 0; l < linha; l++) {//alimentando a matriz dinamicamente
        matrizHeap[l] = malloc(coluna * sizeof(int));
        for (int c = 0; c < coluna; c++) {
            scanf("%d", &matrizHeap[l][c]);
            getchar();
        }
    }
    int padding;
    scanf("%d", &padding);
    printPad(matrizHeap, linha, coluna, padding); //printando matriz com bordas
    printf("\n");
    for (int l = 0; l < linha; l++) { // printando matriz sem bordas
        for (int c = 0; c < coluna; c++) {
            printf("%d ",matrizHeap[l][c]);
        }
        printf("\n");
    }
    for (int i = 0; i < linha; i++) {
        free(matrizHeap[i]);
    }
    free(matrizHeap);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
int main(){
    int linha, coluna;
    scanf("%d\n", &coluna);
    linha = coluna;
    float **matrizHeap = malloc(linha * sizeof(float *));
    for (int l = 0; l < linha; l++) {//alimentando a matriz dinamicamente
        matrizHeap[l] = malloc(coluna * sizeof(float));
        for (int c = 0; c < coluna; c++) {
            scanf("%f", &matrizHeap[l][c]);
            getchar(); // pegando o espaço e o \n
        }
    }
    int **ataques = malloc(linha * sizeof(int*));
    for (int l = 0; l < linha; l++) {
        ataques[l] = malloc(2 * sizeof(int));
        for (int c = 0; c < 2; c++) {
            scanf("%d", &ataques[l][c]);
            getchar(); // pegando o espaço e o \n
        }
    }
    int whatever; // variavel não utilizada no problema (-1)
    scanf("%d",&whatever);
    int tipo = 0;
    scanf("%d",&tipo);
    int indice = 0;
    float *produto = malloc(linha * sizeof(float));
    for (int k = 0; k < linha; k++){
        produto[k] = matrizHeap[k][tipo] * ataques[k][0];
    }
    float maior = produto[0];
    for (int k = 0; k < linha; k++){ 
        if(maior<produto[k]){
            maior = produto[k];
            indice = k;
        }
    }
    printf("O melhor ataque possui indice %d e dano %.2f\n", indice, maior);
    for (int i = 0; i < linha; i++){
        free(matrizHeap[i]);
        free(ataques[i]);
    }
    free(matrizHeap);
    free(ataques);
    free(produto);
    return 0;
}
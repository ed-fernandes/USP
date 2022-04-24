#include "crivo.h"

#include <stdio.h>
#include <stdlib.h>
int primo(int num) {
    int resultado = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            resultado++;
            break;
        }
    }
    if (resultado == 0 && num != 1) {
        return num;
    } else {
        return 0;
    }
}
int *criar(int *quantidade) {
    scanf("%d", quantidade);
    int *vet = malloc(*quantidade * sizeof(int));
    for (int i = 0; i < *quantidade; i++) {
        scanf("%d", &vet[i]);
    }
    return vet;
}
int *calcular(int quantidade, int *vet) {
    int *vetPrimo = malloc(quantidade * sizeof(int));
    for (int i = 0; i < quantidade; i++) {
        int cont = 0;
        int aux = 1;
        while (cont != vet[i]) {
            if (primo(aux) != 0) {  // é primo
                cont++;
            }
            aux++;
        }
        vetPrimo[i] = primo(aux - 1);
        aux = 1;
    }
    return vetPrimo;
}
void imprimir(int n, int *vetor) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
}
void destruir(int *vetor) { 
    free(vetor); 
}
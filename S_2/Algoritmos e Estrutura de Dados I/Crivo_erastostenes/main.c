#include <stdio.h>
#include "crivo.h"
int main(){
    int n;
    int *vetor = criar(&n); // cria um vetor de n posicoes, e recebe seus valores
    vetor = calcular(n, vetor); // para toda posição k do vetor, retorna o k-ésimo primo 
    imprimir(n, vetor); // imprime o vetor
    destruir(vetor); // limpa memoria Heap do vetor
    return 0;
}
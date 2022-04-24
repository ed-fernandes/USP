#include <stdio.h>
#include <stdlib.h>
char *read_line(){
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while(*(vetorHeap+j) != '\n'){
        vetorHeap = realloc(vetorHeap, (j+2) * sizeof(char));
        j++;
        *(vetorHeap+j) = getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
int main(){
    int nLinhas;
    scanf("%d\n",&nLinhas);
    char **matrizHeap = malloc(nLinhas * sizeof(char *));
    for (int i = 0; i<nLinhas; i++){
		matrizHeap[i] = read_line();
    }
    int certas;
    scanf("%d",&certas);
    int vet[certas];
    for (int i = 0; i < certas; i++){
        scanf("%d",&vet[i]);
        printf("%s\n",matrizHeap[vet[i]]);
    }
    for (int k = 0; k < nLinhas; k++){
        free(matrizHeap[k]);
    }
    free(matrizHeap); // deixa os garoto brincar
    return 0;
}
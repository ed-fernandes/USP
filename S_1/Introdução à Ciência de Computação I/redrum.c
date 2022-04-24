#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
char *read_line(int *caracteres) {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF) {
        j++;
        vetorHeap = realloc(vetorHeap, (j + 1) * sizeof(char));
        *(vetorHeap + j) = getchar();
        if (isalnum(vetorHeap[j]) == 0 && vetorHeap[j] != ' ' && vetorHeap[j] != '/' && vetorHeap[j] != '\n') { // deixando apenas alfa numericos, espaços e barras
            vetorHeap = realloc(vetorHeap, j * sizeof(char));
            j--;
        }
    }
    vetorHeap[j] = '\0';
    *caracteres = j;
    return vetorHeap;
}
int palindromo(char palavra[], int tam, int posicao) { // logica do palindromo recursivo que acredito ser generalizada
    if (posicao < tam / 2) {
        if (toupper(palavra[posicao]) == toupper(palavra[tam - posicao - 1])) {
            return 1 * palindromo(palavra, tam, posicao + 1);
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}
int main() {
    char *frase = malloc(sizeof(char)); // frase normal
    int qtdechar = 0;
    frase = read_line(&qtdechar);
    char *fraseind = malloc(sizeof(char)); // frase sem espaço e barra 
    int qtdecharind = 0;
    for (int i = 0; i < qtdechar; i++) {
        if (frase[i] != ' ' && frase[i] != '/') {
            fraseind = realloc(fraseind, (qtdecharind + 1) * sizeof(char));
            fraseind[qtdecharind] = frase[i];
            qtdecharind++;
        }
    }
    fraseind[qtdecharind] = '\0';
    if(palindromo(frase,qtdechar,0)==1 && palindromo(fraseind,qtdecharind,0)==1){ // caso a frase normal e sua versao sem espaços e barras sejam palindromos, eh palindromo direto
        printf("Palindromo direto\n");
    }else if(palindromo(frase,qtdechar,0)==0 && palindromo(fraseind,qtdecharind,0)==1){ // caso apenas a sem barras e espaços seja palindromo, eh indireto
        printf("Palindromo indireto\n");
    }else{
        printf("Nao eh um palindromo\n"); 
    }
    free(frase);
    free(fraseind);
    return 0;
}
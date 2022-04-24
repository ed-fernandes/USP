#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
int main() {
    link *arvore = criaNo();
    int qtde;
    scanf("%d", &qtde);
    int aux = qtde;

    while (aux > 0) {
        aux--;
        int id, value, esq, dir;
        scanf("%d %d %d %d", &id, &value, &esq, &dir);
        inserirNo(&arvore, id, value, esq, dir);
    }

    aux = verifica(arvore, aux);

    if(aux==qtde){
        printf("VERDADEIRO");
    }else{
        printf("FALSO");
    }

   limpa(&arvore);
   
    return 0;
}
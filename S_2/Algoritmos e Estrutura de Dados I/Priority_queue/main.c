#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"
#define ENT "ENTRA"
#define SAI "SAI"
int main() {
    int acoes;
    scanf("%i", &acoes);

    int qtde = 0;
    char *acao;
    pessoa *pessoas = NULL;

    while (acoes > 0) {
        acao = read_line();
        if (strcmp(ENT, acao) == 0) { // pessoa entra
            pessoas = entra(&qtde, pessoas);
            checarPrioridade(pessoas, qtde);
        } else if (strcmp(SAI, acao) == 0) { //pessoa sai
            pessoas = sai(&qtde, pessoas);
        } else {
            printf("%s\n", acao); 
        }
        free(acao);
        acoes--;
    }

    limpar(pessoas, qtde);

    return 0;
}
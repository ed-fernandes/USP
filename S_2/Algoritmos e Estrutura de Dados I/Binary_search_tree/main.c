#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#define INS "insercao"
#define IMP "impressao"
#define POS "pos-ordem"
#define PRE "pre-ordem"
#define EM "em-ordem"

int main() {
    No *arvore;
    criarArvore(&arvore);
    char op;

    while (op != EOF) {

        op = getchar(); //operacao para controlar final do programa
        if(op==EOF){
            break;
        }else{
            ungetc(op, stdin);
        }

        char *operacao = read_line(); // lendo ate algum espaco

        if (!strcmp(operacao, INS)) { // insercao
            int x;
            scanf("%i", &x);
            inserir(&arvore, x);
        } else if (!strcmp(operacao, IMP)) { //impressao

            if (arvore == NULL) { // caso esteja vazia
                printf("VAZIA\n");
            } else {
                operacao = read_line();

                if (!strcmp(operacao, POS)) { //impressao pos-ordem
                    posOrdem(arvore);
                    printf("\n");
                } else if (!strcmp(operacao, PRE)) {//impressao pre-ordem
                    preOrdem(arvore);
                    printf("\n");
                } else if (!strcmp(operacao, EM)) {//impressao em-ordem
                    emOrdem(arvore);
                    printf("\n");
                }
            }
        }
        free(operacao); // limpando a palavra que indica operacao

    }

    limparArvore(&arvore); // limpando arvore

    return 0;
}
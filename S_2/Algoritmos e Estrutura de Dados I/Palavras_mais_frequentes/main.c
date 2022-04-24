#include <stdio.h>
#include <stdlib.h>
#include "palavras.h"
int main() {
    verbete *p = NULL;

    int eof = 0;
    int flinha = 0;
    int qtde = 0;

    int printQtde;
    while (!eof) {
        while (!flinha) {
            p = realloc(p, (qtde + 1) * sizeof(verbete));
            p[qtde].palavra = read_line(&flinha, &eof);
            p[qtde].cont = 0;
            p[qtde].controle = 0;
            qtde++;
        }
        scanf("%d", &printQtde);
        char c = getchar();
        if (c == EOF){
            eof = 1;
        } 

        if (printQtde > qtde) {
            printString(p, qtde, 0);
        }

        calcularRepeticoes(p, &qtde);
        insertionSort(p, qtde);

        int palavrasRepetidas = 0;
        for (int i = 0; i < qtde; ++i) {
            if (p[i].cont == 0) {
                palavrasRepetidas++;
            }
        }

        qtde -= palavrasRepetidas;
        p = realloc(p, qtde * sizeof(verbete));
        ordenar(p, qtde);

        if (qtde < printQtde) {
            printQtde = qtde;
        }

        printString(p, printQtde, 1);
        qtde = 0;
        flinha = 0;
        if(!eof){
            printf("\n");
        }
        
    }
    limpar(p, qtde);
    return 0;
}
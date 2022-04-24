#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define INS "INSERE"
#define REM "REMOVE"
#define IMP "IMPRIMIR"
int main() {
    lista *inicio = NULL;
    int aux = 0;
    char *op = read_line(&aux);
    while (aux==0) {
        if (!strcmp(op, INS)) {
            insere(&inicio);
        } else if (!strcmp(op, REM)) {
            remover(&inicio);
        } else if (!strcmp(op, IMP)) {
            imprimir(inicio);
        }
        op = read_line(&aux);
    }
    free(op);
    limpar(&inicio);
    return 0;
}
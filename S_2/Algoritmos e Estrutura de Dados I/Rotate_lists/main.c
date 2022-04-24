#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main() {
    int qtde;
    scanf("%d", &qtde);

    while (qtde > 0) {
        celula *le = NULL;
        int insercoes, rotacoes;
        scanf("%d\n%d", &insercoes, &rotacoes);

        while (insercoes > 0) {
            int x;
            scanf("%d", &x);
            insere_final(&le, x);
            insercoes--;
        }

        rotaciona(&le, rotacoes);
        imprima(le);
        limpar(&le);
        qtde--;
    }

    return 0;
}
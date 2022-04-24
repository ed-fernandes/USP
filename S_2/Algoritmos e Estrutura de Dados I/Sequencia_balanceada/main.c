#include <stdio.h>
#include <stdlib.h>
#include "balanceado.h"
int main() {
    
    char atual = getchar();

    while (atual != EOF) {
        pilha p1;
        p1.topo = 0;
        while (atual != '\n' && atual != '\r' && atual != EOF) {

            while(atual==' '){ //igonorar espaços entre os caracteres
                atual=getchar();
            }

            p1 = coloca(p1, atual);

            if (verifica(p1) == 0) {  // encontrou um fechamento => (), [], {}, ""

                p1 = retira(p1);

            }
            atual = getchar();

            if (atual == '\r') {
                getchar();
                continue;
            }

        }
        if (p1.topo != 0) { // sobrou caracteres após todos os fechamentos sequenciais
            printf("NÃO BALANCEADO\n");
        } else {
            printf("BALANCEADO\n");
        }

        destruir(p1);
        atual = getchar();
        if (atual == EOF) {
            continue;
        }
    }
    return 0;
}
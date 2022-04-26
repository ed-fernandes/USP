#include <stdio.h>
#include <stdlib.h>
int main() {
    double *pilha = malloc(sizeof(double));
    int p = 0;
    char caractere;
    caractere = getchar();
    double aux = 0;
    while (caractere != '\n' && caractere != EOF) {
        pilha = realloc(pilha, (p + 1) * sizeof(double));
        if (caractere == '-') {
            aux = pilha[p - 2] - pilha[p-1];
            pilha = realloc(pilha, (p - 1) * sizeof(double));
            pilha[p - 2] = aux;
            p = p-2;
        } else if (caractere == '+') {
            aux = pilha[p - 1] + pilha[p-2];
            pilha = realloc(pilha, (p - 1) * sizeof(double));
            pilha[p - 2] = aux;
            p = p-2;
        } else if (caractere == '*') {
            aux = pilha[p - 1] * pilha[p-2];
            pilha = realloc(pilha, (p - 1) * sizeof(double));
            pilha[p - 2] = aux;
            p = p-2;
        } else if (caractere == '/') {
            aux = pilha[p - 2] / pilha[p-1];
            pilha = realloc(pilha, (p - 1) * sizeof(double));
            pilha[p - 2] = aux;
            p = p-2;
        } else if (caractere == ' ') {
            p--;
        } else {
            ungetc(caractere, stdin);
            scanf("%lf",&pilha[p]);
        }
        p++;
        caractere = getchar();
    }
    printf("Resultado: %.6lf\n",pilha[0]);
    free(pilha);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int *moeda(int valor) {
    int *ponteiro = malloc(6 * sizeof(int));
    if (valor >= 100) {
        ponteiro[0] = (int)(valor / 100);  // qtde reais
        valor = valor - ponteiro[0] * 100;
    } else {
        ponteiro[0] = 0;
    }
    if (valor >= 50) {
        ponteiro[1] = (int)(valor / 50);
        valor = valor - ponteiro[1] * 50;
    } else {
        ponteiro[1] = 0;
    }
    if (valor >= 25) {
        ponteiro[2] = (int)(valor / 25);
        valor = valor - ponteiro[2] * 25;
    } else {
        ponteiro[2] = 0;
    }
    if (valor >= 10) {
        ponteiro[3] = (int)(valor / 10);
        valor = valor - ponteiro[3] * 10;
    } else {
        ponteiro[3] = 0;
    }
    if (valor >= 5) {
        ponteiro[4] = (int)(valor / 5);
        valor = valor - ponteiro[4] * 5;
    } else {
        ponteiro[4] = 0;
    }
    ponteiro[5] = valor;
    return ponteiro;
}
int main() {
    int valor;
    scanf("%d", &valor);
    int *moedas = malloc(6 * sizeof(int));
    moedas = moeda(valor);
    printf("O valor consiste em %d moedas de 1 real\n", moedas[0]);
    printf("O valor consiste em %d moedas de 50 centavos\n", moedas[1]);
    printf("O valor consiste em %d moedas de 25 centavos\n",moedas[2]);
    printf("O valor consiste em %d moedas de 10 centavos\n", moedas[3]);
    printf("O valor consiste em %d moedas de 5 centavos\n", moedas[4]);
    printf("O valor consiste em %d moedas de 1 centavo\n", moedas[5]);
    free(moedas);
    return 0;
}
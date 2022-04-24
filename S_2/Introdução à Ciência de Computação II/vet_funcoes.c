#include <stdio.h>
#define N 100

int main() {
    int numeros[N], quantidade[N], total = 0;  // pior caso onde recebem N numeros diferentes, o vetor qtde possui N posicoes
    int atual, aux = 0;

    while (aux < 100) {  // zerando o vetor quantidade com uma variavel auxiliar
        quantidade[aux] = 0;
        aux++;
    }

    // achei que uma solução iterativa seria mais concisa do que usar funções devido à simplicidade do problema.
    while (scanf("%d", &atual) != EOF) {  // lendo ate o fim do arquivo
        aux = 1;
        for (int i = 0; i < total; i++) {  // total = quantidade de numeros digitados
            if (atual == numeros[i]) {     // se o numero digitado ja existir
                quantidade[i]++;           // incrementar sua quantidade
                aux = 0;                   // reutilizando a variavel auxiliar qualquer
                total--;
                break;
            }
        }
        if (aux != 0) {  // caso o numero nao tenha sido digitado antes
            numeros[total] = atual;
            quantidade[total]++;
        }
        total++;
    }

    for (int i = 0; i < total; i++) {
        printf("%d (%d)\n", numeros[i], quantidade[i]);
    }

    return 0;
}

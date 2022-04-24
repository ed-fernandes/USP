#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignum.h"
//Função que lê o que foi digitado até encontrar espaço ou quebra de linha
char *read_line() {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != ' ' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\n') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
        if(vetorHeap[j]=='\r'){
            *(vetorHeap + j) = getchar();
        }
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
//Método que insere um nó no final da lista a partir de um nó inicial;
void insere_final(No **p, int v) {
    No *aux, *q;
    q = (No *)malloc(sizeof(No));
    q->valor = v;
    q->prox = NULL;
    if (*p == NULL) {
        q->ant = NULL;
        *p = q;
    } else {
        aux = *p;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = q;
    }
}
// método para imprimir lista, incluindo seu caso negativo;
void imprime(lista *q) {
    No *aux = q->inicio;
    if (q->sinal == 0) {
        printf("-");
    }
    while (aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}
// função que retorna um número em forma de linked list
lista *insere() {
    lista *pronta = malloc(sizeof(lista));
    pronta->tamanho = 0;
    No *inicio = NULL;
    char aux = getchar();
    // verifica casos negativos e zero à esquerda
    if (aux == '-') {
        pronta->sinal = 0;
        aux = getchar();
    } else {
        pronta->sinal = 1;
    }
    while (aux == '0') {
        aux = getchar();
    }
    //Insere na lista todos os números até encontrar espaço ou quebra de linha
    while (aux != ' ' && aux != '\n' && aux!= '\r') {
        int aux2 = aux - '0';
        insere_final(&inicio, aux2);
        pronta->tamanho++;
        aux = getchar();
        if(aux=='\r'){
            aux = getchar();
        }
    }

    //Caso especial do 00000 ou -00000
    if (inicio == NULL) {
        inicio = (No *)malloc(sizeof(No));
        inicio->valor = 0;
        inicio->ant = NULL;
        inicio->prox = NULL;
        pronta->sinal = 1;
    }
    //fazendo o duplo ligamento entre as listas
    No *final = inicio;
    while (final->prox != NULL) {
        No *aux = final;
        final = final->prox;
        final->ant = aux;
    }
    //Alimentando a struct
    pronta->inicio = inicio;
    pronta->fim = final;
    //retornando a struct com todos os dados
    return pronta;
}
// metodo para liberar memória Nó a Nó
void libera(No **p) {
    No *q;
    while (*p != NULL) {
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}
// Função auxiliar na verificação de casos de maior que e menor que
int verifica(lista *num1, lista *num2) {
    if (num1->tamanho > num2->tamanho) {
        return 1;  
    } else if (num1->tamanho < num2->tamanho) {
        return 0;
    } else {
        int aux = 0;
        while (aux < num1->tamanho) {
            if (num1->inicio->valor > num2->inicio->valor) {
                return 1;
            } else if (num1->inicio->valor < num2->inicio->valor) {
                return 0;
            }
            num1->inicio = num1->inicio->prox;
            num2->inicio = num2->inicio->prox;
            aux++;
        }
        return 0;
    }
}
// Método que verifica Maior que e Menor que
// Para obter o resultado de Menor que basta passar como argumento o maior numero, nesse caso (num2,num1)
void maiorque(lista *num1, lista *num2) {
    if (num1->sinal == 1 && num2->sinal == 0) {
        printf("1\n");
    } else if (num1->sinal == 0 && num2->sinal == 1) {
        printf("0\n");
    } else if (num1->sinal == 1 && num2->sinal == 1) {
        if (verifica(num1, num2)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    } else {
        if (!verifica(num1, num2)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}
// Método que verifica igualdade em diferentes casos entre duas listas ligadas
void igualdade(lista *num1, lista *num2) {
    if (num1->sinal == num2->sinal && num1->tamanho == num2->tamanho) {
        int aux = 0;
        while (aux < num1->tamanho) {
            if (num1->inicio->valor != num2->inicio->valor) {
                printf("0\n");
                return;
            }
            num1->inicio = num1->inicio->prox;
            num2->inicio = num2->inicio->prox;
            aux++;
        }
        printf("1\n");
    } else {
        printf("0\n");
    }
}
//Metodo que verifica a soma de duas listas assumindo que o num1 é maior que num2;
void verificasoma(lista *num1, lista *num2) {
    int tamanho = 0;
    int carry = 0;
    while (tamanho < num2->tamanho) {
        // printf("[%d] [%d]\n", num1->fim->valor, num2->fim->valor);
        int aux = num1->fim->valor + num2->fim->valor;
        // printf("%d\n", aux);
        if (aux >= 10) {
            if (num1->fim->ant != NULL) {
                carry = 1;
                num1->fim->valor = aux - 10;
            } else {
                carry = 0;
                num1->fim->valor = aux;
            }
            // printf("vai um fica %d\n",aux-10);
        } else {
            num1->fim->valor += num2->fim->valor;
        }
        if (num1->fim->ant != NULL) {
            num1->fim = num1->fim->ant;
        }
        if (num2->fim->ant != NULL) {
            num2->fim = num2->fim->ant;
        }
        num1->fim->valor += carry;
        carry = 0;
        tamanho++;
    }
    imprime(num1);
}
void soma(lista *num1, lista *num2) {
    if (num1->tamanho >= num2->tamanho) {
        verificasoma(num1, num2);
    } else {
        verificasoma(num2, num1);
    }
}
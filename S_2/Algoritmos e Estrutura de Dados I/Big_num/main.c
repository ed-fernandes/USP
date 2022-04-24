#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignum.h"
#define SUM "SUM"
#define BIG "BIG"
#define SML "SML"
#define EQL "EQL"
int main() {
    int qtde; //quantidade de linhas
    scanf("%d\n", &qtde);

    while (qtde > 0) {

        char *operacao = read_line(); //lendo a operação a ser executada com os dois números
        lista *num1 = insere(); //inserindo os números em forma de linked list
        lista *num2 = insere();

        if(!strcmp(operacao, SUM)){ // casos das operações
            soma(num1, num2);
        }else if(!strcmp(operacao, EQL)){
            igualdade(num1,num2);
        }else if(!strcmp(operacao, BIG)){
            maiorque(num1, num2);
        }else if(!strcmp(operacao, SML)){
            maiorque(num2,num1);
        }

        libera(&num1->inicio); //liberando memória para a próxima iteração
        libera(&num2->inicio);
        free(num1);
        free(num2);
        free(operacao);

        qtde--;
    }
    return 0;
}
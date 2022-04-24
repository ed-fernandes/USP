#include <stdio.h>
    int main(void){
        float n,m;
        scanf("%f", &n);
        m = 2*(n-80);
        if (n <= 80){
            printf("Velocidade dentro do limite permitido.\n");
        }else {
            printf("Limite de velocidade excedido! Multado no valor de R$%.2f!", m);
        }
        return 0;
    }
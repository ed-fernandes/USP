#include "balanceado.h"

#include <stdio.h>
#include <stdlib.h>
int cheia(pilha px){
    if(px.topo != Tam_MAX){
        return 1;
    }else{
        return 0;
    }
}
pilha coloca(pilha px, char novo) { // coloca o caractere no topo da pilha
    if(cheia(px)!=0){
        px.linha[px.topo] = novo;
        px.topo += 1;
        return px;
    }else{
        return px;
    }
}
pilha retira(pilha px) { // reduz a pilha em 2 posições pois encontrou um "par" de chaves, colchetes, parênteses ou aspas
    px.topo -= 2;        // Apesar de não remover os termos anteriores, para efeitos de contagem eles não serão considerados
    return px;
}
int verifica(pilha px) {
    if (px.topo > 1) {
        
        if (px.linha[px.topo - 1] == col2 && px.linha[px.topo - 2] == col1) { 
            return 0;
        }
        if (px.linha[px.topo - 1] == cha2 && px.linha[px.topo - 2] == cha1) {
            return 0;
        }
        if (px.linha[px.topo - 1] == par2 && px.linha[px.topo - 2] == par1) {
            return 0;
        }
        if (px.linha[px.topo - 1] == aspas && px.linha[px.topo - 2] == aspas) {
            return 0;
        }
    } else {
        return 1;
    }
}
void destruir(pilha px) {
    px.topo = 0;
}
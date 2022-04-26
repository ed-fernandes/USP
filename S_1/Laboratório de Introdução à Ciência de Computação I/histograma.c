#include <stdio.h>
int verifica (int b0,int b1,int b2,int b3,int b4){ // função recursiva para identificar qual numero é maior
    if(b0>b1 && b0 > b2 && b0 > b3 && b0 > b4){
        return b0;
    }else {
        return verifica(b1,b2,b3,b4,b0); 
    }
}
int main(){
    int vet[25];
    int n = 0;
    int cont[5];
    int aux = 0;
    while (aux < 5){ // aux para zerar o vetor que representa a quantidade de cada cor
        cont[aux] = 0;
        aux++;
    }
    while (n<25){ 
        scanf("%d",&vet[n]); // recebendo valores
        if(vet[n]==0){ // verificando em qual cor cada valor se encaixa
            cont[0]++;
        }else if(vet[n]==1){
            cont[1]++;
        }else if(vet[n]==2){
            cont[2]++;
        }else if(vet[n]==3){
            cont[3]++;
        }else{
            cont[4]++;
        }
        n++;
    }
    aux = 0;
    while (aux < 5){
        printf("%d: |",aux);
        for (int i = 0; i < cont[aux]; i++){ // prin
            printf("#");
        }
        printf("\n");
        aux++;
    }
    int maior = verifica(cont[0],cont[1],cont[2],cont[3],cont[4]); // identificando qual o maior valor dentre as cores
    for (int k = 0; k < 5; k++){
        if(maior==cont[k]){ // verificando a qual cor pertence o maior valor
            maior = k;
        }
    }
    aux = 0;
    while (aux < 25){
        if(vet[aux]==maior){
            printf("%d\n",aux); // printando os indices que a maior cor
        }
        aux++;
    }
    return 0;
}
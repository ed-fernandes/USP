#include <stdio.h>
    int main(void){
        int perdeu,ganhou;
        scanf("%d %d", &perdeu, &ganhou);
        int pesoperdido = perdeu*5;
        int pesoganhado = ganhou*3;
        int final = pesoperdido - pesoganhado;
        if(final >= 30){
            printf("P");
        }else if(final < 0){
            printf("R");
        }else{
            printf("B");
        }
        return 0;
    }
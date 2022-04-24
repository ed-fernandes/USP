#include <stdio.h>
int main(void){
    char vet[6];
    int k,x = 0,y = 0;
    for (k = 0; k < 6; k++){
        scanf("%c",&vet[k]);
        if(vet[k]=='W'){
            y=y+1;
        }else if(vet[k]=='S'){
            y=y-1;
        }else if(vet[k]=='A'){
            x=x-1;
        }else if(vet[k]=='D'){
            x=x+1;
        }
       // printf("%c\n", vet[k]);
    }
    printf("%d %d\n", x, y);
}

    
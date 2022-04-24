#include <stdio.h>
int main(void){
    int vet[512];
    for (int i = 0; i < 512; i++){
        scanf("%d",&vet[i]);
    }
    int k = 0;
    printf("Saida do programa:\n");
    while(k<512){
        if(vet[k]==0){
            break;
        }else if(vet[k]==1){
            vet[vet[k+3]] = vet[vet[k+1]]+vet[vet[k+2]];
            k += 4;
        }else if(vet[k]==2){
            vet[vet[k+3]] = vet[vet[k+1]]*vet[vet[k+2]];
            k += 4;
        }else if(vet[k]==3){
            if(vet[vet[k+1]]<vet[vet[k+2]]){
                vet[vet[k+3]] = 1;
            }else{
                vet[vet[k+3]] = 0;
            }
            k += 4;
        }else if(vet[k]==4){
            if(vet[vet[k+1]]==vet[vet[k+2]]){
                vet[vet[k+3]] = 1;
            }else{
                vet[vet[k+3]] = 0;
            }
            k += 4;
        }else if(vet[k]==5){
            k = vet[vet[k+1]];
        }else if(vet[k]==6){
            if(vet[vet[k+1]]!=0){
                k = vet[vet[k+2]];
            }else{
                k += 3;
            }
        }else if(vet[k]==7){
            vet[vet[k+2]] = vet[vet[k+1]];
            k += 3;
        }else if(vet[k]==8){
            int aux = vet[vet[k+1]];
            printf("%c",aux);
            k += 2;
        }else if(vet[k]==9){
            printf("%d",vet[vet[k+1]]);
            k += 2;
        }
    }
    printf("\nEstado final da fita:\n");
    for (int y = 0; y < 512; y++){
        printf("%d\n",vet[y]);
    }
    return 0;
}
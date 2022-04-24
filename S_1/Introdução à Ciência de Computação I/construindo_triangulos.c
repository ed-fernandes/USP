#include <stdio.h>
int main(void){
    char j;
    int n,i,k,w;
    scanf("%d %c",&n,&j);
    if (n>25||n<=0){
        printf("Altura invalida\n");
    } else{
        for (i = 0; i < n; i++){
            for (k = i; k < n-1; k++){
                printf(" ");
            }
            for (w = i; w < (3*i+1); w++){
                printf("%c",j);
            }
            printf("\n");
        }
    }
    return 0;
}
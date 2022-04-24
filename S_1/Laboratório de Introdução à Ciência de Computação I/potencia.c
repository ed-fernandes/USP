#include <stdio.h>
int main(void){
    int a,b;
    scanf("%d %d", &a, &b);
    int aux=1,k;
    for (k = 0;k < b; k++){
        aux = aux*a;
    }
    printf("%d\n", aux);
}

    
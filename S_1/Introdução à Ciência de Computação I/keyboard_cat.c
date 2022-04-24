#include <stdio.h>
int main(void){
    int n = 49;
    char letras[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%c ", &letras[i]);
    }
    int e;
    scanf("%d",&e);
    int mens[e];
    for (int q = 0; q < e-1; q++){
        scanf("%d ",&mens[q]);
    }
    scanf("%d",&mens[e-1]);
    
    for (int u = 0; u < e; u++){
        if(letras[mens[u]]=='_'){
            printf(" ");
        }else if(letras[mens[u]]=='E'){
            printf("\n");
        }else{
        printf("%c", letras[mens[u]]);
        }
    }
    return 0;
}

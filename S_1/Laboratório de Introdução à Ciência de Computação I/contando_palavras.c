#include <stdio.h>
int main(){
    int x = 0;
    int n = 35000;
    char texto[n]; // vetor que recebe os caracteres
    int vet[n]; // vetor inteiro equivalente pq eu prefiro trabalhar com numeros , onde 1 = caractere, 2 = espaço, 3 = pula linha
    int lin = 0; //qtde de linhas
    int palavra = 0; //qtde de palavras
    while( scanf("%c",&texto[x])!=EOF){ // enquanto ouver entrada,
        vet[x]= 0; // zerando a posicao do Vetor numerico caso dê algum problema
        if(texto[x]=='\n'){ // onde tem \r equivale a 3
            vet[x] = 3;
        }else if(texto[x]=='\r'){ // nao considera pula linha
            vet[x] = 4;
        }
        else if(texto[x]==' '||texto[x]=='\t'){ // onde tem espaço vale 2
            vet[x] = 2;
        }else{
            vet[x] = 1; // onde não tem espaço ou linha, considerar caractere
        }
       //  printf("[%d] %c =  %d \n",x, texto[x],vet[x]); 
        x++;
    }

    for (int i = 0; i < x; i++){
        if(vet[i]==3){ // se encontrar pula linhas (3), incrementar linha
            lin++;
        }else if(vet[i]==1){ // se encontrar caracter e o próximo for um espaço ou linha, incrementar palavra
            if(vet[i+1]!=1){
                palavra++;
            }
        }
    }
    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", lin, palavra, x);
    return 0;

}
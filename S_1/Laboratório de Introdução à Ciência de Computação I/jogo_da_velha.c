#include <stdio.h>
int main(){
    char entrada[3][3];
    for (int x = 0; x < 3; x++){
        scanf("%c %c %c\n",&entrada[x][0],&entrada[x][1],&entrada[x][2]); // recebendo os valores em char
    }
    int m[3][3];
    for (int j = 0; j < 3; j++){ // setando numa matriz equivalente em valores inteiros

        for (int k = 0; k < 3; k++){

            if(entrada[j][k]=='o'){

                m[j][k] = 0;

            }else if(entrada[j][k]=='x'){

                m[j][k] = 1;

            }else{

                m[j][k] = -1;

            }
        }
    }

    int cont = 10; // varivael estado onde 10 é aleatório

    if(cont != 0 && cont != 1){ // verifica onde tem "-" para identificar a possibilidade de jogo em andamento
            for (int q = 0; q < 3; q++){

                for (int w = 0; w < 3; w++){

                    if(m[q][w] == -1){

                        cont = -1; 
                        break;
                    }

                }
                
            }
            
        }
    for (int i = 0; i < 3; i++){
        if(m[i][0] == m[i][1] && m[i][1]==m[i][2] && m[i][0]!=-1){ // verifica se algum venceu marcando as horizontais

            cont = m[i][0];

        }
        if(m[0][i] == m[1][i] && m[1][i]==m[2][i] && m[0][i]!=-1){ // verifica se algum venceu marcando as verticais

            cont = m[0][i];

        }
    }
    if(m[0][0]==m[1][1] && m[1][1]==m[2][2] && m[0][0] != -1){ // verifica diagonal decrescente 

        cont= m[0][0];

    }else if(m[2][0] == m[1][1] && m[1][1]==m[0][2] && m[2][0] != -1){ // verifica diagonal crescente

        cont = m[2][0];

    }
    if(cont == 0){
        printf("o ganhou");
    }else if(cont == 1){
        printf("x ganhou");
    }else if(cont == -1){
        printf("em jogo");
    }else{
        printf("empate");
    }
    return 0;
}
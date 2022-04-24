#include <stdio.h>
#include <stdlib.h>
int main() {

//Definição de variaveis
int i, j, linhaA, colunaA, linhaB, colunaB, x;
//Entrada de dados
int semente;
scanf("%d %d\n%d %d\n%d", &linhaA,&colunaA,&linhaB,&colunaB,&semente);
srand(semente);
int matrizA[linhaA][colunaA], matrizB[linhaB][colunaB], matrizC[linhaA][colunaB], aux = 0;

if(colunaA == linhaB) {

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaA; j++) {
			matrizA[i][j] = (rand() % 50) - 25;
		}
	}

	for(i = 0; i < linhaB; i++) {        
		for(j = 0; j < colunaB; j++) {
			matrizB[i][j] = (rand() % 50) - 25;
		}
	}

	// Imprime as matrizes definidas

	for(i = 0; i < linhaA; i++) {        
		for(j = 0; j < colunaA; j++) {
		//	printf("%d ", matrizA[i][j]);
		}
	//	printf("\n\n");
	}

	for(i = 0; i < linhaB; i++) {
		for(j = 0; j < colunaB; j++) {
		//	printf("%d ", matrizB[i][j]); 
		}
	//	printf("\n\n");
	}


	//Processamento e saida em tela  =  PRODUTO DAS MATRIZES
	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			matrizC[i][j] = 0;
			for(x = 0; x < linhaB; x++) {
				aux +=  matrizA[i][x] * matrizB[x][j];
			}

			matrizC[i][j] = aux;
			aux = 0;
		}
	}
	
	for(i = 0; i < linhaA; i++) {
        printf("Linha %d: ",i);
		for(j = 0; j < colunaB; j++) {
			printf("%d ", matrizC[i][j]);
		}
        printf(" ");
		printf("\n");
	}
	printf("\n");
} else {
	printf("Valores invalidos para a multiplicacao.");
}
if(semente == 0 && (colunaA == linhaB)){
    printf("Valores invalidos para a multiplicacao.");
}
    return 0;
}
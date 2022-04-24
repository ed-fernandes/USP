#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nLinhas, nColunas;  // variavel global pois não será necessário modificar no decorrer do código, e para facilitar acesso nas funcoes
char *read_line() {     // funcao para ler linha
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF) {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
int moore(int linha, int coluna, char **matriz) {
    int viz = -1;                  // facilitar contagem
    for (int k = 0; k < 3; k++) {  // para rodar 3^2 vezes, os 9 quadrados incluindo a própria celula uma vez
        for (int l = 0; l < 3; l++) {
            int lin = linha - k + 1; // auxiliar que varia de coluna-1 a coluna+1, facilita nos índices
            int col = coluna - l + 1;
            if (lin < 0) {  // casos aonde estão fora dos limites dados
                lin = lin + nLinhas;
            } else if (lin > nLinhas - 1) {
                lin = lin - nLinhas;
            }
            if (col < 0) {
                col = col + nColunas;
            } else if (col > nColunas - 1) {
                col = col - nColunas;
            }
            if (matriz[lin][col] == 'x' || matriz[lin][col] == 'm') {  // acho uma viva ou "quase-morta"
                viz++;
            }
        }
    }
    if (matriz[linha][coluna] == '.' || matriz[linha][coluna] == 'v') {
        return viz + 1;  // caso ela esteja morta, acrescentar o -1 pois ela não entrou na condicao
    } else if (matriz[linha][coluna] == 'x' || matriz[linha][coluna] == 'm') {
        return viz;  // caso ela esteja viva, o -1 serve para retirar ela mesma da contagem;
    } else {
        return 0;
    }
}
int neumann(int linha, int coluna, char **matriz) {
    int viz = -2;
    for (int i = 0; i < 5; i++) {  // para rodar 10 vezes, incluindo a própria célula duas vezes
        int col = coluna + i - 2; //auxiliar que varia de coluna-2 a coluna+2, facilita nos índices
        if (col < 0) {
            col = col + nColunas;
        } else if (col > nColunas) {
            col = col - nColunas;
        }
        if (matriz[linha][col] == 'x' || matriz[linha][col] == 'm') {
            viz++;
        }
        int lin = linha + i - 2;
        if (lin < 0) {
            lin = lin + nLinhas;
        } else if (lin > nLinhas - 1) {
            lin = lin - nLinhas;
        }
        if (matriz[lin][coluna] == 'x' || matriz[lin][coluna] == 'm') {
            viz++;
        }
    }
    if (matriz[linha][coluna] == '.' || matriz[linha][coluna] == 'v') {
        return viz + 2;  // +2 pois a célula é contada duas vezes
    } else if (matriz[linha][coluna] == 'x' || matriz[linha][coluna] == 'm') {
        return viz;
    } else {
        return 0;
    }
}
int main() {
    int geracao;
    char tipo;
    scanf("%d %d\n%d\n%c", &nLinhas, &nColunas, &geracao, &tipo);
    int erro = 0;
    if (geracao < 0) {
        erro = 1;
    } else if (tipo != 'M' && tipo != 'N') {
        erro = 1;
    } else if (nLinhas <= 0) {
        erro = 1;
    } else if (nColunas <= 0) {
        erro = 1;
    }
    if (erro == 1) {
        printf("Dados de entrada apresentam erro.");
    } else {
        getchar();  // pegar o \n
        char **matrizHeap = malloc((nLinhas) * sizeof(char *));
        for (int i = 0; i < nLinhas; i++) {
            matrizHeap[i] = read_line();
        }
        int vez = 0;
        while (vez < geracao) {
            int vizinhanca = 0;
            for (int k = 0; k < nLinhas; k++) {
                for (int j = 0; j < nColunas; j++) {
                    if (tipo == 'M') {
                        vizinhanca = moore(k, j, matrizHeap);
                    } else {
                        vizinhanca = neumann(k, j, matrizHeap);
                    }
                    if (matrizHeap[k][j] == 'x') {  // viva
                        if (vizinhanca < 2) {
                            matrizHeap[k][j] = 'm'; // crio um estado quase-morto (estava vivo mas vai morrer)
                        } else if (vizinhanca > 3) {
                            matrizHeap[k][j] = 'm';
                        } else {
                            matrizHeap[k][j] = 'x';
                        }
                    } else {  // morta
                        if (vizinhanca == 3) {
                            matrizHeap[k][j] = 'v'; // crio um estado semi-morto (estava morto mas vai reviver)
                        }
                    }

                    vizinhanca = 0;
                }
            }
            for (int m = 0; m < nLinhas; m++) {
                for (int j = 0; j < nColunas; j++) {
                    if (matrizHeap[m][j] == 'v') {
                        matrizHeap[m][j] = 'x';
                    }
                    if (matrizHeap[m][j] == 'm') {
                        matrizHeap[m][j] = '.';
                    }
                }
            }
            vez++;
        }
        for (int j = 0; j < nLinhas; j++) {
            printf("%s\n", matrizHeap[j]);
        }
        for (int k = 0; k < nLinhas; k++) {
            free(matrizHeap[k]);
        }
        free(matrizHeap);  // deixa os garoto brincar
    }
    return 0;
}
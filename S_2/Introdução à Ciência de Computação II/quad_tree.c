#include <stdio.h>
int verificaMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    int aux = matriz[0][0];
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (aux != matriz[i][j]) {
                return 0;                 // Valores da matriz sendo diferentes
            }
        }
    }
    return 1;                            // Valores da matriz sendo iguais
}
void travessia(int linha, int coluna, int matriz[linha][coluna]) {
    if (verificaMatriz(linha, coluna, matriz) == 1) {
        printf("%d ", matriz[0][0]);
    } else {
        printf("-1 ");
        int matrizAux[linha/2][coluna/2];

        for (int i = 0; i < linha/2; i++) {         //Primeira parte da imagem
            for (int j = 0; j < coluna/2; j++) {
                matrizAux[i][j] = matriz[i][j];
            }
        }
        travessia(linha/2, coluna/2, matrizAux);    //Repetindo os passos pra ela

        for (int i = 0; i < linha/2; i++) {         //Segunda parte da imagem
            for (int j = coluna/2; j < coluna; j++) {
                matrizAux[i][j - coluna/2] = matriz[i][j];
            }
        }
        travessia(linha/2, coluna/2, matrizAux);

        for (int i = linha/2; i < linha; i++) {     //Terceira
            for (int j = 0; j < coluna/2; j++) {
                matrizAux[i - linha/2][j] = matriz[i][j];
            }
        }
        travessia(linha/2, coluna/2, matrizAux);

        for (int i = linha/2; i < linha; i++) {     //Quarta
            for (int j = coluna/2; j < coluna; j++) {
                matrizAux[i - linha/2][j - coluna/2] = matriz[i][j];
            }
        }
        travessia(linha/2, coluna/2, matrizAux);
    }
}
int main() {
    int lin, col;
    scanf("%d %d", &lin, &col);
    int matriz[lin][col];
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    travessia(lin, col, matriz);
    printf("\n");
    return 0;
}
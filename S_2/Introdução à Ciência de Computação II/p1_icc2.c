#include <stdio.h>
#include <stdlib.h>
/*
Nome : Eduardo Barroso Ribeiro Fernandes
N° USP : 12681733
Disciplina : SCC0201
*/
int **alloc_matrix(int m) {
    int **mat = malloc(sizeof(int *) * m);
    srand(m);

    int in = 0;
    // aloca matriz ordenada
    for (int i = 0; i < m; i++) {
        mat[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            if (i == j)
                in += (rand() % 3) + 1;
            else
                in += rand() % 3;
            mat[i][j] = in;
        }
    }
    // desordena matriz triangular superior
    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            int swaps = (int)((m - j) / 2.0) + 1;
            for (int t = 1; t <= swaps; t++) {
                int a = (rand() % (m - j)) + j;
                int b = (rand() % (m - j)) + j;
                int tmp = mat[i][a];
                mat[i][a] = mat[i][b];
                mat[i][b] = tmp;
            }
        }
    }
    return mat;
}
int main() {
    int m;
    scanf("%d", &m);

    int **mat = malloc(sizeof(int *) * m);
    mat = alloc_matrix(m);
    int tamanho = ((m - 2) * (m + 1)) / 2, aux = 0; // calculo do tamanho do vetor necessario para armazenar os valores desordenados
    int vetor[tamanho];
    for (int i = 0; i < m - 2; i++) {  // a penultima e ultima linha estao ja estao ordenadas
        for (int j = i + 1; j < m; j++) {
            vetor[aux] = mat[i][j];
            aux++;
        }
    }

    // utilizando o insertion sort
    int j;
    for (int k = 1; k <= tamanho - 1; k++){
        aux = vetor[k];
        j = k - 1;
        while (j >= 0 && aux < vetor[j]) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }

    aux = 0;
    for (int i = 0; i < m - 2; i++) {  // devolvendo valores ordenados na matriz
        for (int j = i + 1; j < m; j++) {
            mat[i][j] = vetor[aux];
            aux++;
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
 
    // limpando
    
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
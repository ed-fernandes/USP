#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funcao para ler cada linha digitada dinamicamente
char *read_line() {
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

// funcao para ler cada linha do arquivo dinamicamente
char *read_lineArquivo(FILE *arquivo, int *espacos) {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0, aux = 0;
    *vetorHeap = fgetc(arquivo);
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF) {
        if (vetorHeap[j] == '.') {
            aux++;
        }
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = fgetc(arquivo);
    }
    *espacos = aux;
    vetorHeap[j] = '\0';
    return vetorHeap;
}

// procedimento para printar labirinto
void showLab(char **labirinto, int linha) {
    for (int j = 0; j < linha; j++) {
        printf("%s\n", labirinto[j]);
    }
    printf("\n");
}

// funcao recursiva para percorrer labirinto
char **percorrer(char **labirinto, int x0, int y0, int linha, int *estado) {
    if (*estado == 0) { // estado = 0 indica que nao chegou na borda
        labirinto[x0][y0] = '*';
        if (labirinto[x0 - 1][y0] == '.') {  // cima
            percorrer(labirinto, x0 - 1, y0, linha, estado);
        } else if (!labirinto[x0 - 1][y0]) {
            *estado = 1; // estado = 1 indica que chegou na borda do labirinto
        }
        if (labirinto[x0][y0 + 1] == '.') {  // direita
            percorrer(labirinto, x0, y0 + 1, linha, estado);
        } else if (!labirinto[x0][y0 + 1]) {
            *estado = 1;
        }
        if (x0 == linha - 1) { // caso isolado para borda horizontal inferior
            *estado = 1;
        } else {
            if (labirinto[x0 + 1][y0] == '.') {  // baixo
                percorrer(labirinto, x0 + 1, y0, linha, estado);
            } else if (!labirinto[x0 + 1][y0]) {
                *estado = 1;
            }
        }
        if (labirinto[x0][y0 - 1] == '.') {  // esquerda
            percorrer(labirinto, x0, y0 - 1, linha, estado);
        } else if (!labirinto[x0][y0 - 1]) {
            *estado = 1;
        }
    }
    return labirinto;
}

int main() {

    // abertura e tratamento de erro na leitura do arquivo
    char *titulo = read_line();
    FILE *arquivo = fopen(titulo, "r");
    if (!arquivo) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    //insercao dos dados do arquivo na memoria Stack
    int linha;
    fscanf(arquivo, "%d ", &linha);
    int coluna;
    fscanf(arquivo, "%d", &coluna);
    fgetc(arquivo);
    int x0;
    fscanf(arquivo, "%d ", &x0);
    int y0;
    fscanf(arquivo, "%d", &y0);
    fgetc(arquivo);

    //insercao dos dados do arquivo na memoria Heap
    char **labirinto = malloc(sizeof(char *));
    int j = 0;
    int espacos = 0;
    while (!feof(arquivo)) {
        labirinto[j] = read_lineArquivo(arquivo, &espacos);
        labirinto = realloc(labirinto, (j + 2) * sizeof(char *));
        j++;
    }
    fclose(arquivo);

    //chamada recursiva inicial da funcao que percorre o labirinto
    int estado = 0;
    labirinto = percorrer(labirinto, x0, y0, linha, &estado);
    showLab(labirinto, linha);

    // obtendo dados do problema
    int pessoas = 0, validos = 0, visitados = 0;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (labirinto[i][j] == '#') {
                pessoas++;
            } else if (labirinto[i][j] == '*') {
                visitados++;
            } else if (labirinto[i][j] == '.') {
                validos++;
            }
        }
    }

    //printando as informacoes do problema
    printf("Voce escapou de todos! Ninguem conseguiu te segurar!\n");
    printf("Veja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n", pessoas);
    printf("----Numero total de caminhos validos:   %d\n", validos + visitados);
    printf("----Numero total de caminhos visitados: %d\n", visitados);
    double exploracao = (double)visitados / (double)(visitados + validos) * 100;
    printf("----Exploracao total do labirinto: %.1lf%%\n", floor(exploracao));

    //liberando memoria alocada dinamicamente
    for (int j = 0; j < linha; j++) {
        free(labirinto[j]);
    }
    free(titulo);
    free(labirinto);
    
    return 0;
}
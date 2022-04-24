/*
Nome : Eduardo Barroso Ribeiro Fernandes
N° USP : 12681733
Código do Curso: SCC0201 - Introdução à Ciência de Computação II
Título : Trabalho 1 Campo Minado
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Função para ler cada linha de um arquivo, retornar a linha e passar por referência a quantidade de caracteres
*/
char *read_lineArquivo(FILE *arquivo, int *coluna) {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = fgetc(arquivo);
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF) {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = fgetc(arquivo);
    }
    vetorHeap[j] = '\0';
    if (j != 0) {
        *coluna = j;
    }
    return vetorHeap;
}

/*
Função para abrir o arquivo e retornar uma matriz dinamica com seu conteúdo,
além de passar por referência a quantidade de linhas e de colunas
*/
char **abrirAquivo(char *nomearquivo, int *lin, int *col) {
    nomearquivo[7] = '\0';
    FILE *arquivo = fopen(nomearquivo, "r");
    if (!arquivo) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    char **matrizHeap = malloc(sizeof(char *));
    int j = 0, k = 0;
    while (!feof(arquivo)) {
        matrizHeap[j] = read_lineArquivo(arquivo, &k);
        matrizHeap = realloc(matrizHeap, (j + 2) * sizeof(char *));
        j++;
    }
    *lin = j - 1;
    *col = k;
    fclose(arquivo);
    return matrizHeap;
}

// Procedimento para printar a matriz dinâmica
void mostrarCampo(char **MatrizHeap, int linha) {
    for (int i = 0; i < linha; i++) {
        printf("%s\n", MatrizHeap[i]);
    }
}

/*
Função para setar as dicas referentes ao campo minado
*/
char **setarDicas(char **MatrizHeap, int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cont = 0;
            if (i < linha - 1 && j < coluna) {
                if (MatrizHeap[i + 1][j + 1] == '*') {
                    cont++;
                }
            }
            if (i < linha - 1) {
                if (MatrizHeap[i + 1][j] == '*') {
                    cont++;
                }
            }
            if (i < linha - 1 && j > 0) {
                if (MatrizHeap[i + 1][j - 1] == '*') {
                    cont++;
                }
            }
            if (j < coluna) {
                if (MatrizHeap[i][j + 1] == '*') {
                    cont++;
                }
            }
            if (j > 0) {
                if (MatrizHeap[i][j - 1] == '*') {
                    cont++;
                }
            }
            if (i > 0) {
                if (MatrizHeap[i - 1][j] == '*') {
                    cont++;
                }
            }
            if (i > 0 && j < coluna) {
                if (MatrizHeap[i - 1][j + 1] == '*') {
                    cont++;
                }
            }
            if (i > 0 && j > 0) {
                if (MatrizHeap[i - 1][j - 1] == '*') {
                    cont++;
                }
            }
            if (cont > 0 && MatrizHeap[i][j] != '*') {
                MatrizHeap[i][j] = cont + '0';
            }
        }
    }
    return MatrizHeap;
}
/*
Procedimento que imprime o campo minado de forma oculta, revelando apenas a dica que o Usuário escolheu
*/
void dica(char **matrizHeap, int linha, int coluna, int x, int y) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (i == x && j == y) {
                printf("%c", matrizHeap[x][y]);
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}
/*
Função recursiva que percorre o campo minado até encontrar todas as bordas e dicas
*/
char **revelarCampo(char **matrizHeap, char **matrizOculta, int linha, int coluna, int i, int j) {
    if (matrizOculta[i][j] == '.') { // verifica se a posição já foi selecionada
        return matrizOculta;
    }
    if (i >= 0 && i < linha && j >= 0 && j < coluna) {
        if (matrizHeap[i][j] != '*') {
            matrizOculta[i][j] = matrizHeap[i][j];
            if (matrizOculta[i][j] != '*' && matrizOculta[i][j] != '.') {  // verifica se chegou numa dica
                return matrizOculta;
            }
        }
        if (i < linha - 1) {  // cima
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i + 1, j);
        }
        if (j < coluna - 1) {  // direita
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i, j + 1);
        }
        if (i > 0) {  // baixo
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i - 1, j);
        }
        if (j > 0) {  // esquerda
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i, j - 1);
        }
        if (i < linha - 1 && j > 0) { // diagonal inferior esquerda
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i + 1, j - 1);
        }
        if (i > 0 && j > 0) { // diagonal superior esquerda
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i - 1, j - 1);
        }
        if (i > 0 && j < coluna - 1) { // diagonal superior direita
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i - 1, j + 1);
        }
        if (i < linha - 1 && j < coluna - 1) { //diagonal inferior direita
            revelarCampo(matrizHeap, matrizOculta, linha, coluna, i + 1, j + 1);
        }
    }
    return matrizOculta;
}
// Função para tratar o controle do Usuário
char **controleUsuario(char **matrizHeap, int linha, int coluna, int x, int y) {
    matrizHeap = setarDicas(matrizHeap, linha, coluna);
    if (matrizHeap[x][y] != '.' && matrizHeap[x][y] != '*') {  // Usuário selecionou uma dica
        dica(matrizHeap, linha, coluna, x, y);
    } else if (matrizHeap[x][y] == '*') { 
        // Usuário selecionou uma bomba
        mostrarCampo(matrizHeap, linha); // Fim de jogo revelando o campo
    } else if (matrizHeap[x][y] == '.') { 
        // Usuário selecionou um espaço vazio
        // Uma matriz dinâmica com as mesmas dimensões é criada e preenchida com 'X'
        char **matrizOculta = malloc(linha * sizeof(char *));
        for (int i = 0; i < linha; i++) {
            matrizOculta[i] = malloc((coluna+1) * sizeof(char));
        }
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                matrizOculta[i][j] = 'X';
            }
            matrizOculta[i][coluna] = '\0';
        }

        // Chamada recursiva e mostrando o campo após as etapas
        matrizOculta = revelarCampo(matrizHeap, matrizOculta, linha, coluna, x, y);
        mostrarCampo(matrizOculta, linha);
        return matrizOculta;
    }
    return matrizHeap;
}
int main() {

    // Criando variáveis e recebendo os dados
    int operacao;
    scanf("%d", &operacao);
    char nome[7];
    scanf("%s", nome);
    int linha, coluna;
    char **campominado = malloc(sizeof(char *));

    // Abrindo o arquivo .board com os campos minados
    campominado = abrirAquivo(nome, &linha, &coluna);


    if (operacao == 1) {  
        // Mostrar campo minado
        mostrarCampo(campominado, linha);
    } else if (operacao == 2) {  
        // Mostrar campo minado com dicas
        campominado = setarDicas(campominado, linha, coluna);
        mostrarCampo(campominado, linha);
    } else if (operacao == 3) {  
        // Controle do Usuário
        int x, y;
        scanf("%d %d", &x, &y);
        campominado = controleUsuario(campominado, linha, coluna, x, y);
    }

    //limpando memória Heap
    for (int i = 0; i < linha; i++) {
        free(campominado[i]);
    }
    free(campominado);
    return 0;
}
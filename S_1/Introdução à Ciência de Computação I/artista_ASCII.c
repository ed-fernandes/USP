#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// funcao para ler uma entrada de char (frase)
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
// funcao para ler cada linha de um arquivo
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
    *coluna = j;
    return vetorHeap;
}
// funcao para abrir arquivo e setar numa matrizHeap
char **abrirAquivo(char *nomearquivo, int *lin, int *col) {
    FILE *arquivo = fopen(nomearquivo, "r");
    if (!arquivo) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    char **desenho = malloc(sizeof(char *));
    int j = 0, k = 0;
    while (!feof(arquivo)) {
        desenho[j] = read_lineArquivo(arquivo, &k);
        desenho = realloc(desenho, (j + 2) * sizeof(char *));
        j++;
    }
    *lin = j;
    *col = k;
    fclose(arquivo);
    return desenho;
}
// funcao recursiva para desenhar na matrizHeap
char **pintura(char **matrizHeap, int linha, int coluna, char pixelnovo, char pixelantigo, int matlinha, int matcoluna) {
    if (linha >= 0 && linha <= (matlinha - 1) && coluna >= 0 && coluna <= (matcoluna - 1)) {
        if (matrizHeap[linha][coluna] == pixelantigo && linha >= 0 && coluna >= 0) {
            matrizHeap[linha][coluna] = pixelnovo;
            if (coluna >= 1) {
                if (matrizHeap[linha][coluna - 1] == pixelantigo) {
                    matrizHeap = pintura(matrizHeap, linha, coluna - 1, pixelnovo, pixelantigo, matlinha, matcoluna);
                }
            }
            if (coluna <= (matcoluna - 2)) {
                if (matrizHeap[linha][coluna + 1] == pixelantigo) {
                    matrizHeap = pintura(matrizHeap, linha, coluna + 1, pixelnovo, pixelantigo, matlinha, matcoluna);
                }
            }
            if (linha >= 1) {
                if (matrizHeap[linha - 1][coluna] == pixelantigo) {
                    matrizHeap = pintura(matrizHeap, linha - 1, coluna, pixelnovo, pixelantigo, matlinha, matcoluna);
                }
            }
            if (linha <= (matlinha - 2)) {
                if (matrizHeap[linha + 1][coluna] == pixelantigo) {
                    matrizHeap = pintura(matrizHeap, linha + 1, coluna, pixelnovo, pixelantigo, matlinha, matcoluna);
                }
            }
        }
    }
    return matrizHeap;
}
// funcao para moldurar arte
void enquadra_arte(char *nome_do_arquivo_da_arte, int altura_do_quadro, int largura_do_quadro) {
    FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
    if (f_arte_ptr == NULL) {
        printf(
            "Erro na abertura do arquivo, "
            "Você esqueceu de fechar o arquivo antes? "
            "Ou deu free na string com o nome sem querer?\n");

        exit(EXIT_FAILURE);
    }

    int qtd_espc_comeco;
    const char *apoio;
    if (largura_do_quadro % 2 == 0) {
        qtd_espc_comeco = largura_do_quadro / 2;
        apoio = "/\\";
    } else {
        qtd_espc_comeco = largura_do_quadro / 2 + 1;
        apoio = "Ʌ";
    }

    for (int i = 0; i < qtd_espc_comeco; i++) printf(" ");
    printf("%s\n", apoio);
    printf("╭");
    for (int i = 0; i < largura_do_quadro; i++) printf("—");
    printf("╮\n");
    for (int i = 0; i < altura_do_quadro; i++) {
        printf("|");
        for (int j = 0; j < largura_do_quadro; j++) {
            char pixel_atual = fgetc(f_arte_ptr);
            printf("%c", pixel_atual);
        }
        printf("|");

        char quebra = fgetc(f_arte_ptr);
        if (quebra != EOF) printf("%c", quebra);
    };
    fclose(f_arte_ptr);

    printf("\n╰");
    for (int i = 0; i < largura_do_quadro; i++) printf("—");
    printf("╯\n");
}
//metodo para realizar escrita do arquivo apos etapas finais
void escreverArquivo(char **matrizHeap, char *nome, int linha, int coluna) {
    FILE *arquivo = fopen(nome, "w+");
    for (int i = 0; i < linha; i++) {
        fwrite(matrizHeap[i], sizeof(char), coluna, arquivo);
        if (i < (linha - 1)) {
            fwrite("\n", sizeof(char), 1, arquivo);
        }
    }
    fclose(arquivo);
}
int main() {
    char *nomeArte;
    nomeArte = read_line();
    int mudancas;
    scanf("%d\n", &mudancas);
    int coordenadas[mudancas][2];
    char pixel[mudancas];
    for (int i = 0; i < mudancas; i++) {
        scanf("%c %d %d ", &pixel[i], &coordenadas[i][0], &coordenadas[i][1]);
    }
    char **matrizHeap = malloc(sizeof(char *));
    int linha = 0, coluna = 0;
    matrizHeap = abrirAquivo(nomeArte, &linha, &coluna);
    printf("Arte inicial:\n");
    for (int k = 0; k < linha; k++) {
        printf("%s\n", matrizHeap[k]);
    }
    for (int p = 0; p < mudancas; p++) {
        matrizHeap = pintura(matrizHeap, 
        coordenadas[p][0], coordenadas[p][1], 
        pixel[p], 
        matrizHeap[coordenadas[p][0]][coordenadas[p][1]], 
        linha, 
        coluna);
        printf("\nArte apos a etapa %d:\n", p);
        for (int k = 0; k < linha; k++) {
            printf("%s\n", matrizHeap[k]);
        }
    }
    escreverArquivo(matrizHeap, nomeArte, linha, coluna);
    printf("\nArte enquadrada:\n");
    enquadra_arte(nomeArte, linha, coluna);
    for (int l = 0; l < linha; l++) {
        free(matrizHeap[l]);
    }
    free(matrizHeap);
    free(nomeArte);
    return 0;
}
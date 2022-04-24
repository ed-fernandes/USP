#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {  // definindo estrutura de cada musica
    char *titulo;
    char *artista;
    int tempo;  // pensei em colocar unsigned short int, mas tive problemas com a máscara formatação posteriormente.
} Musica;
void freeAll(Musica *playlist, int musicas) { // facilitar na liberação de memoria
    for (int i = 0; i < musicas; i++) {
        free(playlist[i].artista);
        free(playlist[i].titulo);
    }
    free(playlist);
}
void binaryToNum(char *binFilename) {  // funcao dada
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double)ch * accumulator;
        accumulator += 0.01;
    }
    fclose(fp);
    printf("%lf\n", binValue);
}
char *read_line() {  // funcao para ler cada linha reaproveitada de exemplos anteriores
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
void addMusica(Musica *track) {  // adicionar cada parâmetro de uma musica por deferenciação
    (*track).titulo = read_line();
    (*track).artista = read_line();
    scanf("%d", &(*track).tempo);
    printf("Musica %s de %s adicionada com sucesso.\n", (*track).titulo, (*track).artista);
}
void imprimeMusica(Musica *track) {  // printar cada parâmetro de uma musica por deferenciação
    printf("'%s'\n", (*track).titulo);
    printf("Artista: %s\n", (*track).artista);
    printf("Duracao: %d segundos\n\n", (*track).tempo);
}
int main() {
    Musica *playlist = NULL;
    int musicas = 0, operacao, aux = 1;  // variáveis respectivamentes para quantidade de musicas, estado do gerenciador de playlist, e uma auxiliar.
    char *nome = malloc(sizeof(char));   // alocando dinamicamente o nome da playlist
    nome = read_line();                  // nome inicial
    while (scanf("%d", &operacao) != EOF && operacao != 7) {
        getchar();                                                     // consumir \n da funcao read_line
        if (operacao == 1 && musicas != 15) {                          // adicionar musica
            musicas++;                                                 // numero de musicas
            playlist = realloc(playlist, (musicas) * sizeof(Musica));  // realocando o tamanho da playlist
            addMusica(&playlist[musicas - 1]);
        } else if (operacao == 2 || musicas == 15) {  // printar playlist
            if (musicas == 15) {
                printf("Playlist cheia!\n");
                operacao = 5;
            }
            printf("---- Playlist: %s ----\nTotal de musicas: %d\n\n", nome, musicas);
            for (int k = 0; k < musicas; k++) {
                if (k + 1 == aux) {
                    printf("=== NOW PLAYING ===\n");
                }
                printf("(%d). ", k + 1);
                imprimeMusica(&playlist[k]);
            }
            if (musicas == 15) {
                break;
            }
        } else if (operacao == 3) {  // proxima musica
            aux++;
            if (aux > musicas) {
                aux = aux - musicas;
            }
        } else if (operacao == 4) {  // musica anterior
            aux--;
            if (aux < 1) {
                aux = musicas;
            }
        } else if (operacao == 5) {      // salvar arquivo em binario
            char *titulo = read_line(); 
            FILE *arquivoBinario = fopen(titulo, "wb");
            int aux = strlen(nome);  // tamanho do nome da Playlist a ser salva
            fwrite(&aux, sizeof(int), 1, arquivoBinario);
            fwrite(nome, sizeof(char), aux, arquivoBinario);  // titulo da playlist
            fwrite(&musicas, sizeof(int), 1, arquivoBinario);
            for (int w = 0; w < musicas; w++) {  // rodar isso de acordo com a quantidade de musicas
                int aux1 = strlen(playlist[w].titulo);
                int aux2 = strlen(playlist[w].artista);
                fwrite(&aux1, sizeof(int), 1, arquivoBinario);
                fwrite(playlist[w].titulo, aux1 * sizeof(char), 1, arquivoBinario);
                fwrite(&aux2, sizeof(int), 1, arquivoBinario);
                fwrite(playlist[w].artista, aux2 * sizeof(char), 1, arquivoBinario);
                fwrite(&playlist[w].tempo, sizeof(int), 1, arquivoBinario);
                // usei as auxiliares pois tive problemas com conversão de tipos e o código não executava no runcodes apesar de rodar na minha maquina.
            }
            fprintf(stdout, "Playlist %s salva com sucesso.\n", titulo);
            fclose(arquivoBinario);
            binaryToNum(titulo); 
            free(titulo);
        } else if (operacao == 6) {  // carregar arquivo em binario
            char *titulo = read_line();
            FILE *arquivoLeitura = fopen(titulo, "rb");
            if (!arquivoLeitura) {
                fprintf(stdout, "Arquivo %s nao existe.\n", titulo);
                operacao = 7;
                break;
            } else {
                freeAll(playlist, musicas);
                int aux = 0;
                fread(&aux, sizeof(int), 1, arquivoLeitura);
                free(nome);
                nome = malloc((aux) * sizeof(char));
                fread(nome, sizeof(char), aux, arquivoLeitura);
                nome[aux] = '\0';
                fread(&musicas, sizeof(int), 1, arquivoLeitura);
                playlist = malloc(musicas * sizeof(Musica));
                for (int w = 0; w < musicas; w++) {
                    int aux1 = 0;
                    int aux2 = 0;
                    fread(&aux1, sizeof(int), 1, arquivoLeitura);
                    playlist[w].titulo = malloc(aux1 * sizeof(char));
                    fread(playlist[w].titulo, sizeof(char), aux1, arquivoLeitura);
                    fread(&aux2, sizeof(int), 1, arquivoLeitura);
                    playlist[w].artista = malloc(aux2 * sizeof(char));
                    fread(playlist[w].artista, sizeof(char), aux2, arquivoLeitura);
                    fread(&playlist[w].tempo, sizeof(int), 1, arquivoLeitura);
                }
                fprintf(stdout, "Playlist %s carregada com sucesso.\n", titulo);
            }
            fclose(arquivoLeitura);
            binaryToNum(titulo);
            free(titulo);
        }
    }
    freeAll(playlist, musicas);
    return 0;
}

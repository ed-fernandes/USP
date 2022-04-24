#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { // definindo estrutura de cada musica
    char *titulo;
    char *artista;
    unsigned short int tempo;
} Musica;
char *read_line() { // funcao para ler cada linha
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
void addMusica(Musica *track) { // adicionar cara parametro de uma musica
    (*track).titulo = read_line();
    (*track).artista = read_line();
    scanf("%hu", &(*track).tempo);
    printf("Musica %s de %s adicionada com sucesso.\n", (*track).titulo, (*track).artista);
}
void imprimeMusica(Musica *track) {  // printar cada valor formatado
    printf("'%s'\n", (*track).titulo);
    printf("Artista: %s\n", (*track).artista);
    printf("Duracao: %hu segundos\n\n", (*track).tempo);
}
int main() {
    Musica *playlist = NULL;
    int musicas = 0, operacao, aux = 1;
    char *nome = malloc(sizeof(char)); // alocando dinamicamente o nome da playlist
    nome = read_line();
    while (scanf("%d", &operacao) != EOF && operacao != 5) {
        getchar();            // consumir \n da funcao read_line
        if (operacao == 1 && musicas !=15) {  // adicionar musica
            musicas++;  // numero de musicas
            playlist = realloc(playlist, (musicas) * sizeof(Musica)); // realocando o tamanho da playlist 
            addMusica(&playlist[musicas - 1]); 
        } else if (operacao == 2 || musicas == 15) {
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
			if(musicas==15){
				break;
			}
        } else if (operacao == 3) { // proxima musica
            aux++;
            if (aux > musicas) {
                aux = aux - musicas;
            }
        } else if (operacao == 4) { // musica anterior
            aux--;
            if (aux < 1) {
                aux = musicas;
            }
        }
        operacao = 0;
    }

    for (int i = 0; i < musicas; i++) { 
        free(playlist[i].artista);
        free(playlist[i].titulo);
    }
    free(playlist);  // deixa os garoto brincar 8)
    return 0;
}

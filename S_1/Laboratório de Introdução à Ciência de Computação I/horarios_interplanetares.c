#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *read_line() {  // funcao para ler dinamicamente o nome do planeta
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
long long unsigned int *rotacao(long long unsigned int segundos,int i) {  // funcao para ler os dias, horas, minutos e segundos do planeta
    long long unsigned int tempo = segundos;
    long long unsigned int *result = malloc(4 * sizeof(long long unsigned int));
    long long unsigned int dia;
    if (i == 1) {  // venus
        dia = 20995200;
    } else if (i == 2) {  // mercurio
        dia = 5068800;
    } else if (i == 3) {
        dia = 35760;  // jupiter
    } else {          // terra
        dia = 86400;
    }
    if (tempo >= dia) {
        result[0] = (int)(tempo / dia);  // qtde de dias
        tempo = tempo - result[0] * dia;
    } else {
        result[0] = 0;
    }
    if (tempo >= 3600) {
        result[1] = (int)(tempo / 3600);  // qtde de horas
        tempo = tempo - result[1] * 3600;
    } else {
        result[1] = 0;
    }
    if (tempo >= 60) {
        result[2] = (int)(tempo / 60);  // qtde de minutos
        tempo = tempo - result[2] * 60;
    } else {
        result[2] = 0;
    }
    if (tempo > 0) {
        result[3] = tempo;  // qtde de segundos
    } else {
        result[3] = 0;
    }
    return result;
}
int main() {
    long long unsigned int segundos;
    char *palavra = malloc(sizeof(char));
    scanf("%llu ", &segundos);
    long long unsigned int *tempo = malloc(4 * sizeof(long long unsigned int));
    palavra = read_line();
    if ((strcmp(palavra, "Venus") == 0)) {
        tempo = rotacao(segundos, 1);
    } else if ((strcmp(palavra, "Mercurio") == 0)) {
        tempo = rotacao(segundos, 2);
    } else if ((strcmp(palavra, "Jupiter") == 0)) {
        tempo = rotacao(segundos, 3);
    } else {  // Terra
        tempo = rotacao(segundos, 4);
    }
    printf("%llu segundos no planeta %s equivalem a:\n", segundos, palavra);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", tempo[0], tempo[1], tempo[2],
           tempo[3]);
    free(palavra);
    free(tempo);
    return 0;
}
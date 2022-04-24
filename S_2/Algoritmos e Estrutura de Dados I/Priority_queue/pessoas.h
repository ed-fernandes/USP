#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct infos {
    char *nome;
    int condicao;
    int idade;
    int prioridade;
} pessoa;
char *read_line();
pessoa *entra(int *qtde, pessoa *p);
void checarPrioridade(pessoa *p, int qtde);
pessoa *sai(int *qtde, pessoa *p);
void limpar(pessoa *p, int total);
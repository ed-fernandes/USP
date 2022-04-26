#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    char caractere = getchar();
    double *valores = malloc(sizeof(double));
    char *operacoes = malloc(sizeof(char));
    int qtdeoperacoes = 0, qtdevalores = 0;
    while (caractere != EOF) {
        while (caractere != '\n' && caractere != EOF) {
            if (isdigit(caractere) != 0) {  // numero
                ungetc(caractere, stdin);
                valores = realloc(valores, (qtdevalores + 1) * sizeof(double));
                scanf("%lf", &valores[qtdevalores]);
                qtdevalores++;
            } else if (caractere == '+') {  // soma
                operacoes = realloc(operacoes, (qtdeoperacoes + 1) * sizeof(char));
                operacoes[qtdeoperacoes] = caractere;
                qtdeoperacoes++;
            } else if (caractere == '-') {  // subtracao
                operacoes = realloc(operacoes, (qtdeoperacoes + 1) * sizeof(char));
                operacoes[qtdeoperacoes] = caractere;
                qtdeoperacoes++;
            } else if (caractere == '*') {  // multiplicacao
                operacoes = realloc(operacoes, (qtdeoperacoes + 1) * sizeof(char));
                operacoes[qtdeoperacoes] = caractere;
                qtdeoperacoes++;
            } else if (caractere == '/') {  // divisao
                operacoes = realloc(operacoes, (qtdeoperacoes + 1) * sizeof(char));
                operacoes[qtdeoperacoes] = caractere;
                qtdeoperacoes++;
            } else {
                if (caractere == ')') {
                    qtdeoperacoes--;
                    qtdevalores--;
                    if (operacoes[qtdeoperacoes] == '+') {  // soma
                        valores[qtdevalores - 1] = valores[qtdevalores - 1] + valores[qtdevalores];
                    }
                    if (operacoes[qtdeoperacoes] == '-') {  // sub
                        valores[qtdevalores - 1] = valores[qtdevalores - 1] - valores[qtdevalores];
                    }
                    if (operacoes[qtdeoperacoes] == '*') {  // multi
                        valores[qtdevalores - 1] = valores[qtdevalores - 1] * valores[qtdevalores];
                    }
                    if (operacoes[qtdeoperacoes] == '/') {  // div
                        valores[qtdevalores - 1] = valores[qtdevalores - 1] / valores[qtdevalores];
                    }
                    valores = realloc(valores, (qtdevalores) * sizeof(double));
                    operacoes = realloc(operacoes, (qtdeoperacoes) * sizeof(char));
                }
            }
            caractere = getchar();
        }
        qtdeoperacoes = 0;
        qtdevalores = 0;
        printf("%.6lf\n", valores[0]);
        caractere = getchar();
    }
    free(valores);
    free(operacoes);
    return 0;
}
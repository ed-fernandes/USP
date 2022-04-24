#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "skiplist.h"
#define INS "insercao"
#define ALT "alteracao"
#define REM "remocao"
#define BUS "busca"
#define IMP "impressao"
int main() {
    Skiplist *dicionario = createSkiplist(15, 0.5);
    char controle = getchar();

    while (controle != EOF) {
        ungetc(controle, stdin);

        string_t operacao = malloc(10 * sizeof(char));
        string_t palavra = malloc(50 * sizeof(char));
        scanf("%s%*c", operacao);

        if (!strcmp(operacao, INS)) {

            string_t definicao = malloc(140 * sizeof(char));
            scanf("%s%*c", palavra);
            scanf("%[^\r\n]%*[\r\n]", definicao);

            if (!insertSkiplist(dicionario, palavra, definicao)) {
                printf("OPERACAO INVALIDA\n");
            }

            free(definicao);

        } else if (!strcmp(operacao, ALT)) {

            string_t definicao = malloc(140 * sizeof(char));
            scanf("%s%*c", palavra);
            scanf("%[^\r\n]%*[\r\n]", definicao);

            if (!change(dicionario, palavra, definicao)) {
                printf("OPERACAO INVALIDA\n");
            }

            free(definicao);

        } else if (!strcmp(operacao, REM)) {

            scanf("%s%*[\r\n]", palavra);

            if (!removeSkiplist(dicionario, palavra)) {
                printf("OPERACAO INVALIDA\n");
            }

        } else if (!strcmp(operacao, BUS)) {

            scanf("%s%*[\r\n]", palavra);
            node *def = searchSkiplist(dicionario, palavra);

            if (!def) {
                printf("OPERACAO INVALIDA\n");
            } else {
                printf("%s %s\n", def->key, def->def);
            }

        } else if (!strcmp(operacao, IMP)) {

            scanf("%s%*[\r\n]", palavra);
            printList(dicionario, palavra[0]);

        }
        
        free(operacao);
        free(palavra);
        controle = getchar();
    }

    freeSkiplist(dicionario);

    return 0;
}
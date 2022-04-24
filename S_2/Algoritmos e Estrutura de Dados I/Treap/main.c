#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treap.h"
#define INS "insercao"
#define IMP "impressao"
#define REM "remocao"
#define BUS "buscar"
#define POS "posordem"
#define PRE "preordem"
#define EMO "ordem"
int main() {
    TreapNode *root = NULL;
    int n;
    scanf("%d", &n);
    while (n >= 0) {
        char *line = read_line();
        if (!strcmp(line, INS)) {  // Inserção
            int a, b;
            scanf("%d %d", &a, &b);
            if (!search(root, a)) { // Caso não haja nenhum elemento
                root = insert(root, a, b);
            } else {
                printf("Elemento ja existente\n");
            }
        } else if (!strcmp(line, REM)) {  // Remoção
            int a;
            scanf("%d", &a);
            if (!search(root, a)) { // Caso não haja nenhuma chave
                printf("Chave nao localizada\n");
            } else {
                root = deleteNode(root, a);
            }
        } else if (!strcmp(line, BUS)) {  // Busca
            int a;
            scanf("%d", &a);
            if (!search(root, a)) {
                printf("0\n");
            } else {
                printf("1\n");
            }
        } else if (!strcmp(line, IMP)) {  // Impressão
            char *print = read_line();
            if (!strcmp(print, PRE)) { // Pré-ordem
                preOrder(root);
                printf("\n");
            } else if (!strcmp(print, EMO)) { //Em ordem
                inOrder(root);
                printf("\n");
            } else if (!strcmp(print, POS)) { // Pós-ordem
                postOrder(root);
                printf("\n");
            } else{
                levelOrder(root); // Por nível ou largura
                printf("\n");
            }
            free(print);
        }
        free(line);
        n--;
    }
    freeTree(&root);
    return 0;
}
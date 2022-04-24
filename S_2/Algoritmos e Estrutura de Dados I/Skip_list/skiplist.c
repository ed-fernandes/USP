#include "skiplist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// função que retorna uma palavra lida
string_t read_word() {
    string_t vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != ' ' && *(vetorHeap + j) != '\n' && *(vetorHeap + j) != '\r') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    if (vetorHeap[j] == '\r') {
        getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
// função que retorna uma linha digitada
string_t read_line() {
    string_t vetorHeap = malloc(sizeof(char));
    int j = 0;
    scanf("%*[\r\n]s");
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != EOF && *(vetorHeap + j) != '\n' && *(vetorHeap + j) != '\r') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    if (vetorHeap[j] == '\r') {
        getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
// criação de um novo nó
node *newNode(string_t str1, int level, string_t str2) {
    node *new = malloc(sizeof(node));
    new->key = malloc(50 * sizeof(char));
    new->def = malloc(140 * sizeof(char));
    if (new != NULL) {
        strcpy(new->key, str1);
        strcpy(new->def, str2);
        new->next = malloc((level + 2) * sizeof(node));
        for (int i = 0; i < level + 2; i++) {
            new->next[i] = NULL;
        }
    }
    return new;
}
// Criação de uma nova skiplist
Skiplist *createSkiplist(int maxLevel, double p) {
    Skiplist *sk = malloc(sizeof(Skiplist));
    if (sk != NULL) {
        sk->maxLevel = maxLevel;
        sk->p = p;
        sk->level = 0;
        sk->start = newNode("", maxLevel, "");
    }
    return sk;
}
// liberação de memória da skiplist
void freeSkiplist(Skiplist *sk) {
    if (sk == NULL) {
        return;
    }
    node *no, *temp;
    temp = sk->start->next[0];
    while (temp != NULL) {
        no = temp;
        temp = temp->next[0];
        free(no->key);
        free(no->def);
        free(no->next);
        free(no);
    }
    free(sk->start->next);
    free(sk->start->key);
    free(sk->start->def);
    free(sk->start);
    free(sk);
}
// busca de uma chave na skiplist
node *searchSkiplist(Skiplist *sk, string_t key) {
    if (sk == NULL) {
        return NULL;
    }
    node *tempo = sk->start;
    // Percorrendo nós e descendo de nível
    for (int i = sk->level; i >= 0; i--) {
        while (tempo->next[i] != NULL && strcmp(tempo->next[i]->key, key) < 0) {
            tempo = tempo->next[i];
        }
    }
    // Recebendo a chave no nível 0
    tempo = tempo->next[0];
    if (tempo != NULL && strcmp(tempo->key, key) == 0) {
        return tempo;
    } else {
        return NULL;
    }
}
// Inserção de uma nova chave e descrição na Skiplist
int insertSkiplist(Skiplist *sk, string_t str1, string_t str2) {
    if (sk == NULL) {
        return 0;
    }
    node **aux;
    node *temp = sk->start;

    aux = malloc((sk->maxLevel + 1) * sizeof(node *));
    for (int i = 0; i <= sk->maxLevel; i++) {
        aux[i] = NULL;
    }
    // Descendo de nível e avançando nós, até guardar no vetor auxiliar
    for (int i = sk->level; i >= 0; i--) {
        while (temp->next[i] != NULL && strcmp(temp->next[i]->key, str1) < 0) {
            temp = temp->next[i];
        }
        aux[i] = temp;
    }

    temp = temp->next[0];
    // Criando e inserindo nó
    if (temp == NULL || strcmp(temp->key, str1) != 0) {
        int novoNivel = randLevel(sk);
        node *novo = newNode(str1, novoNivel, str2);
        if (novo == NULL) {
            free(aux);
            return 0;
        }
        // Correção de nível
        if (novoNivel > sk->level) {
            for (int i = sk->level + 1; i <= novoNivel; i++) {
                aux[i] = sk->start;
            }
            sk->level = novoNivel;
        }

        for (int i = 0; i <= novoNivel; i++) {
            novo->next[i] = aux[i]->next[i];
            aux[i]->next[i] = novo;
        }

        free(aux);
        return 1;
    }
    return 0;
}
// Sorteio de level de cada No
int randLevel(Skiplist *sk) {
    double r = (double)rand() / RAND_MAX;
    int nivel = 0;
    while (r < sk->p && nivel < sk->maxLevel) {
        nivel++;
        r = (double)rand() / RAND_MAX;
    }
    return nivel;
}
// Remoção de uma chave na skiplist
int removeSkiplist(Skiplist *sk, string_t str1) {
    if (sk == NULL) {
        return 0;
    }

    node *temp = sk->start;
    node **aux;

    aux = malloc((sk->maxLevel + 1) * sizeof(node *));
    for (int i = 0; i <= sk->maxLevel; i++) {
        aux[i] = NULL;
    }

    for (int i = sk->level; i >= 0; i--) {
        while (temp->next[i] != NULL && strcmp(temp->next[i]->key, str1) < 0) {
            temp = temp->next[i];
        }
        aux[i] = temp;
    }
    temp = temp->next[0];
    // Se achar a chave a ser removida
    if (temp != NULL && strcmp(temp->key, str1) == 0) {
        for (int i = 0; i <= sk->level; i++) {
            if (aux[i]->next[i] != temp) {
                break;
            }
            aux[i]->next[i] = temp->next[i];
        }
        // Removendo níveis sem nós
        while (sk->level > 0 && sk->start->next[sk->level] == NULL) {
            sk->level--;
        }
        free(temp->def);
        free(temp->key);
        free(temp->next);
        free(temp);
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}
// Impressão de todos as chaves iniciadas por um char
void printList(Skiplist *sk, char begin) {
    int bool = 0;
    node *p = sk->start;
    while (p != NULL) {
        if (p->key[0] == begin) {
            bool = 1;
            printf("%s %s\n", p->key, p->def);
        }
        p = p->next[0];
    }
    if (!bool) {
        printf("NAO HA PALAVRAS INICIADAS POR %c\n", begin);
    }
}
// alteração da descrição de uma chave específica
int change(Skiplist *sk, string_t str1, string_t str2) {
    node *p = searchSkiplist(sk, str1);
    if (p == NULL) {
        return 0;
    }
    strcpy(p->def, str2);
    return 1;
}
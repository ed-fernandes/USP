#include "polinomios.h"

#include <stdio.h>
#include <stdlib.h>
list *createList() {
    list *l;
    l = malloc(sizeof(list));
    l->start = NULL;
    l->end = NULL;
    l->lenght = 0;

    return l;
}

void insertList(list *l, int x) {
    if (l != NULL) {
        node *p = malloc(sizeof(node));
        p->info = x;
        p->prox = NULL;
        if (l->start == NULL) {
            l->start = p;
        } else {
            l->end->prox = p;
        }
        l->end = p;
        l->lenght++;
    }
}
void plusPol(list *p1, list *p2) {
    node *pol1 = p1->start;
    node *pol2 = p2->start;
    while (pol1 != NULL && pol2 != NULL) {
        pol1->info = pol1->info + pol2->info;
        pol1 = pol1->prox;
        pol2 = pol2->prox;
    }
    if (p1->lenght < p2->lenght) {
        while (pol2 != NULL) {
            insertList(p1, pol2->info);
            pol2 = pol2->prox;
        }
    }
}
void readPol(list *p1) {
    char c;
    while ((c = getchar()) != ')') {
        if (c != '(' && c != ',' && c != '\r' && c != '\n') {
            ungetc(c, stdin);
            int n;
            scanf("%d ", &n);
            insertList(p1, n);
        }
    }
}

void printList(list *l) {
    node *p = l->start;
    while (p->prox != NULL) {
        printf("%d,", p->info);
        p = p->prox;
    }
    printf("%d", p->info);
}
void freeList(list *l) {
    if (l != NULL) {
        node *p = l->start;
        while (p != NULL) {
            l->start = p->prox;
            free(p);
            p = l->start;
        }
        free(l);
    }
}
#include "treap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Função para leitura de cada palavra
char *read_line() {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    scanf("%*[\r\n]s");
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != ' ' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\n' && *(vetorHeap + j) != '\r') {
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
// Função para rotação direita da árvore
TreapNode *rightRotate(TreapNode *y) {
    TreapNode *x = y->left, *T2 = x->right;

    x->right = y;
    y->left = T2;
    return x;
}
// Função para rotação esquerda da árvore
TreapNode *leftRotate(TreapNode *x) {
    TreapNode *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;
    return y;
}
// Criação de novo Nó na árvore
TreapNode *newNode(int key, int prior) {
    TreapNode *temp = malloc(sizeof(TreapNode));
    temp->key = key;
    temp->priority = prior;
    temp->left = temp->right = NULL;
    return temp;
}
// Inserção na Treap por ordem de chave e prioridade
TreapNode *insert(TreapNode *root, int key, int prior) {
    if (!root) {
        return newNode(key, prior);
    }

    if (key <= root->key) {
        root->left = insert(root->left, key, prior);

        if (root->left->priority > root->priority) {
            root = rightRotate(root);
        }
    } else {
        root->right = insert(root->right, key, prior);

        if (root->right->priority > root->priority) {
            root = leftRotate(root);
        }
    }
    return root;
}
// Busca na Treap
TreapNode *search(TreapNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}
//Remoção de Nó na treap
TreapNode *deleteNode(TreapNode *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else if (root->left == NULL) {
        TreapNode *temp = root->right;
        free(root);
        root = temp;
    } else if (root->right == NULL) {
        TreapNode *temp = root->left;
        free(root);
        root = temp;
    } else {
        root = leftRotate(root);
        root->left = deleteNode(root->left, key);
    }
    return root;
}
// Impressão pré-ordem
void preOrder(TreapNode *root) {
    if (root != NULL) {
        printf("(%d, %d) ", root->key, root->priority);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Impressão em ordem
void inOrder(TreapNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("(%d, %d) ", root->key, root->priority);
        inOrder(root->right);
    }
}
// Impressão pós-ordem
void postOrder(TreapNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("(%d, %d) ", root->key, root->priority);
    }
}
// Impressão por level ou largura da Treap
void levelOrder(TreapNode *root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
    }
}
// Método para impressão de cana nível da árvore
void printCurrentLevel(TreapNode *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("(%d, %d) ", root->key, root->priority);
    } else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
// Cálculo da altura da árvore
int height(TreapNode *node) {
    if (node == NULL) {
        return 0;
    } else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight) {
            return (lheight + 1);
        } else {
            return (rheight + 1);
        }
    }
}
// Liberar memória da árvore
void freeTree(TreapNode **root) {
    if ((*root) != NULL) {
        freeTree(&(*root)->left);
        freeTree(&(*root)->right);
        free(*root);
    }
}
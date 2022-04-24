struct No {
    int key, priority;
    struct No *left, *right;
};
typedef struct No TreapNode;
char *read_line();
TreapNode *rightRotate(TreapNode *y);
TreapNode *leftRotate(TreapNode *x);
TreapNode *newNode(int key, int prior);
TreapNode *insert(TreapNode *root, int key, int prior);
TreapNode *search(TreapNode *root, int key);
TreapNode *deleteNode(TreapNode *root, int key);
void preOrder(TreapNode *root);
void inOrder(TreapNode *root);
void postOrder(TreapNode *root);
void levelOrder(TreapNode *root);
void printCurrentLevel(TreapNode *root, int level);
int height(TreapNode *node);
void freeTree(TreapNode **root);
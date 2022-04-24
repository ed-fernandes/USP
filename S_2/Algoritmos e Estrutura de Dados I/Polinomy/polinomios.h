typedef struct no node;
struct no {
    int info;
    node *prox;
};
typedef struct lista {
    node *start;
    node *end;
    int lenght;
} list;
list *createList();
void insertList(list *l, int x);
void plusPol(list *p1, list *p2);
void readPol(list *p1);
void printList(list *l);
void freeList(list *l);
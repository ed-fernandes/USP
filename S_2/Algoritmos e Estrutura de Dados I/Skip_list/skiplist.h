typedef struct Skiplist_t Skiplist;
typedef struct No node;
typedef char *string_t;
typedef struct No {
    string_t key, def;
    struct No **next;
}No;
struct Skiplist_t {
    int maxLevel, level;
    double p;
    node *start;
};
string_t read_word();
string_t read_line();
node *newNode(string_t str1, int level, string_t str2);
Skiplist *createSkiplist(int maxLevel, double p);
void freeSkiplist(Skiplist *sk);
node *searchSkiplist(Skiplist *sk, string_t key);
int insertSkiplist(Skiplist *sk, string_t str1, string_t str2);
int randLevel(Skiplist *sk);
int removeSkiplist(Skiplist *sk, string_t str1);
void printList(Skiplist *sk, char begin);
int change(Skiplist *sk, string_t str1, string_t str2);
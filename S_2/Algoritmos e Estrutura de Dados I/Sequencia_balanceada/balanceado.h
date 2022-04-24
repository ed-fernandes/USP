#define col1 '['
#define col2 ']'
#define par1 '('
#define par2 ')'
#define cha1 '{'
#define cha2 '}'
#define aspas '"'
#define Tam_MAX 1000
typedef struct {
    char linha[Tam_MAX];
    int topo;
} pilha;
pilha coloca(pilha px, char novo);
pilha retira(pilha px);
int verifica(pilha px);
void destruir(pilha px);
int cheia(pilha px);
typedef struct {
    char *palavra;
    int cont;
    int controle;
} verbete;
char *read_line(int *flinha, int *eof);
void insertionSort(verbete *palavras, int qtde);
void calcularRepeticoes(verbete *palavras, int *qtde);
void ordenar(verbete *palavras, int qtde);
void printString(verbete *palavras, int qtde, int printRep);
void limpar(verbete *palavras, int total);
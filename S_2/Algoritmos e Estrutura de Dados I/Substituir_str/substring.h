typedef struct {
    char *total;
    char *errado;
    char *certo;
    int tam_frase;
    int tam_errado;
    int tam_certo;
} frase;
char *read_line(int *tam);
frase *criar();
void destruir(frase *f);
int ultimo(frase *f);
void trocar(frase *f);
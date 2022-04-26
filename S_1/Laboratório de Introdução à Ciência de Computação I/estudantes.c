#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {  // definindo estrutura de cada musica
    char *id;
    char *nome;
    char *curso;
    int idade;
} Estudantes;
char *read_line() {  // funcao para ler cada linha
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF) {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }
    vetorHeap[j] = '\0';
    return vetorHeap;
}
void addAluno(Estudantes *aluno) {  // adicionar cara parametro de uma musica
    (*aluno).id = read_line();
    (*aluno).nome = read_line();
    (*aluno).curso = read_line();
    scanf("%d\n", &(*aluno).idade);
}
void imprimeAluno(Estudantes *aluno) {  // printar cada valor formatado
    printf("Nome: %s\n", (*aluno).nome);
    printf("Curso: %s\n", (*aluno).curso);
    printf("N USP: %s\n", (*aluno).id);
    printf("IDADE: %d\n\n", (*aluno).idade);
}
int main() {
    Estudantes *lista = NULL;
    int qtde = 0;
    char aux = getchar();
    while (aux != '-') {  // pra achar "-1", basta que ache "-" primeiro
        ungetc(aux, stdin);
        lista = realloc(lista, (qtde + 1) * sizeof(Estudantes));
        addAluno(&lista[qtde]);
        qtde++;
        aux = getchar();
    }
    getchar(); //  1, resto do "-1"
    getchar(); // \n
    aux = getchar(); //proxima operacao
    int encontrou = 0;
    char *linha = malloc(sizeof(char));
    while (aux != '-') {  // -1
        if (aux == '1') {
            getchar(); // pegar o \n
            linha = read_line();
            for (int i = 0; i < qtde; i++) {
                if (strcmp(linha,lista[i].id)==0) { // compara o que foi digitado com o que tem na Struct
                    imprimeAluno(&lista[i]);
                    encontrou = 1;
                }
            }
            if (encontrou != 1) {
                printf("Aluno nao cadastrado %s\n",linha);
            }
        } else if (aux == '2') { 
            getchar();
            linha = read_line();
            for (int i = 0; i < qtde; i++) {
                if (strcmp(linha,lista[i].curso)==0) {
                    imprimeAluno(&lista[i]);
                }
            }
        } else if (aux == '3') {
            getchar(); 
            for (int i = 0; i < qtde; i++) {
                imprimeAluno(&lista[i]);
            }
        }
        aux = getchar(); // pega a proxima operacao
    }
    free(linha);
    free(lista);
    return 0;
}
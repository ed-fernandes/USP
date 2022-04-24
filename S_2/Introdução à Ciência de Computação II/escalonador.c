#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int id;
    int tempo;
    int volume;
    int prioridade;
} lista;
// funcao que cria um vetor de structs e retorna o mesmo
lista *inserir(int *cont, int *qtde) {
    lista *p = malloc(sizeof(lista));
    char control = getchar();
    int aux = 0;
    int total = 0;
    while (aux < 4) {
        ungetc(control, stdin);
        scanf("%d %d %d %d", &p[aux].id, &p[aux].tempo, &p[aux].volume, &p[aux].prioridade);
        total += p[aux].volume;
        if (p[aux].id == p[aux - 1].id) {
            p[aux].id++;
        }
        p = realloc(p, (aux + 2) * sizeof(lista));
        aux++;
        control = getchar();
    }
    *cont = aux;
    *qtde = total;
    return p;
}
// metodo de ordenação via prioridade adaptado a struct 
void insertionSort(lista *array, int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step].prioridade;
        int aux1 = array[step].id;
        int aux2 = array[step].tempo;
        int aux3 = array[step].volume;
        int j = step - 1;
        while (key > array[j].prioridade && j >= 0) {
            array[j + 1].prioridade = array[j].prioridade;
            array[j + 1].id = array[j].id;
            array[j + 1].tempo = array[j].tempo;
            array[j + 1].volume = array[j].volume;
            --j;
        }
        array[j + 1].prioridade = key;
        array[j + 1].id = aux1;
        array[j + 1].tempo = aux2;
        array[j + 1].volume = aux3;
    }
}
int main() {
    int tamanho = 0;
    int total = 0;


    lista *p = inserir(&tamanho, &total);
    insertionSort(p, tamanho);
    // Com o vetor devidamente ordenado por prioridade, começam as iterações

    int posicao = 0;
    int time = 1;

    while (total > 0) {

        //Verifica se algum processo é "elegível" de acordo com o seu tempo final e inicial
        if (p[posicao].tempo <= time && p[posicao].volume > 0) {
            p[posicao].volume--;
            total--;
            if (p[posicao].volume == 0) {
                printf("%d %d\n", p[posicao].id, time);
            }
            time++;
        }
        //Loop para o início
        if (posicao < tamanho - 1) {
            posicao++;
        } else {
            posicao = 0;
        }

    }


    free(p);

    return 0;
}
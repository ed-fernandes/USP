#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Funcao que retorna os valores do arquivo
*/
unsigned char *read_wav_data(char *fname, int *tamanho) {
    FILE *fp = fopen(fname, "rb");
    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    *tamanho = buf4[0] | buf4[1] << 8 | buf4[2] << 16 | buf4[3] << 24;

    unsigned char *data = malloc(sizeof(*data) * (*tamanho));

    int i = 0;
    while (i < *tamanho) {
        fread(&data[i++], sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
    return data;
}
// funcao para salvar audio em um arquivo comprimido

void salvarArquivo(unsigned char *audio, int tamanho, char *nome) {
    FILE *fp1 = fopen(nome, "rb");
    unsigned char cabecalho[44];
    fread(cabecalho, sizeof(cabecalho), 1, fp1);
    fclose(fp1);
    FILE *fp2 = fopen("comprimido.wav", "wb");

    for (int i = 0; i < 44; i++) {
        fwrite(&cabecalho[i], sizeof(unsigned char), 1, fp2);
    }
    for (int i = 0; i < tamanho; i++) {
        fwrite(&audio[i], sizeof(unsigned char), 1, fp2);
    }

    fclose(fp2);
}
//transformada discreta de Fourier

double complex *DFT(unsigned char *audio, int length) {
    double complex *coef = (double complex *)calloc(length, sizeof(double complex));

    for (int k = 0; k < length; k++) {
        for (int n = 0; n < length; n++) {
            coef[k] += audio[n] * cexp((-2.0 * M_PI * (((k + 1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
    }
    return coef;
}
//Inversa da transformada discreta de Fourier

unsigned char *IDFT(double complex *coef, int length) {
    unsigned char *audio = (unsigned char *)calloc(length, sizeof(unsigned char));

    for (int n = 0; n < length; n++) {
        double complex aux = 0;
        for (int k = 0; k < length; k++) {
            aux += coef[k] * cexp((2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
        audio[n] = (int)(creal(aux) / length * 1.0);
    }
    return audio;
}
// funcao para ler cada linha digitada

char *read_line() {
    char *vetorHeap = malloc(sizeof(char));
    int j = 0;
    *vetorHeap = getchar();
    while (*(vetorHeap + j) != '\n' && *(vetorHeap + j) != EOF && *(vetorHeap + j) != '\r') {
        vetorHeap = realloc(vetorHeap, (j + 2) * sizeof(char));
        j++;
        *(vetorHeap + j) = getchar();
    }

    vetorHeap[j] = '\0';
    return vetorHeap;
}
// metodo de ordenação do vetor
void bubble_sort(double vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
void printarT(double vetor[], int t) {
    for (int i = 0; i < t; i++) {
        printf("%d\n", (int)sqrt(vetor[i]));
    }
}

int main() {
    char *nomearq = read_line();
    int T;
    scanf("%d", &T);
    int tamanho = 0;
    unsigned char *audio = read_wav_data(nomearq, &tamanho);
    printf("%d\n", tamanho);
    double complex *transformada = DFT(audio, tamanho);


    double vetaux[tamanho];
    int cont = 0;
    for (int i = 0; i < tamanho; i++) {
        double a = creal(transformada[i]);
        double b = cimag(transformada[i]);
        vetaux[i] = (a * a + b * b);
        if (a <= 0 && b <= 0) {
            cont++;
        }
    }


    bubble_sort(vetaux, tamanho); // vetor ordenado por "magnitude", sem a raiz quadrada
    printf("%d\n", cont);
    printarT(vetaux, T);
    double min = sqrt(vetaux[T - 1]); // pega o menor valor do vetor ordenado


    for (int i = 0; i < tamanho; i++) {
        double a = creal(transformada[i]);
        double b = cimag(transformada[i]);
        if (sqrt(a * a + b * b) < min) {
            transformada[i] = 0;
        }
    }


    audio = IDFT(transformada, tamanho);
    salvarArquivo(audio, tamanho, nomearq);


    free(audio);
    free(nomearq);
    free(transformada);
    return 0;
}
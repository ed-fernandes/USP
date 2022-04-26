#include <stdio.h>
#include<stdlib.h>
#define INCREMENTA_VALOR '+'
#define DECREMENTA_VALOR '-'
#define INCREMENTA_INDICE '>'
#define DECREMENTA_INDICE '<'
#define IMPRIME '.'
#define WHILE_INICIO '['
#define WHILE_FIM ']'
int main(){
    char atual;
    FILE *arquivo = fopen("arquivobf.c", "w+");
    fprintf(arquivo,"#include <stdio.h>\nint main(){\n\tchar mem[30000];\n\tfor(int j = 0; j < 30000; j++){\n\t\tmem[j] = 0;\n\t}\n\tint i = 0;\n\n");
    while ((atual = getchar()) != EOF){
        switch (atual){
        case INCREMENTA_VALOR:
            fprintf(arquivo, "\tmem[i]++;\n");
            break;
        case DECREMENTA_VALOR:
            fprintf(arquivo, "\tmem[i]--;\n");
            break;
        case INCREMENTA_INDICE:
            fprintf(arquivo, "\ti++;\n");
            break;
        case DECREMENTA_INDICE:
            fprintf(arquivo, "\ti--;\n");
            break;
        case IMPRIME:
            fprintf(arquivo, "\tputchar(mem[i]);\n");
            break;
        case WHILE_INICIO:
            fprintf(arquivo, "\n\twhile(mem[i]){\n");
            break;
        case WHILE_FIM:
            fprintf(arquivo, "\t\n\t}\n\n");
            break;
        default:
            break;
        }
    }
    fprintf(arquivo, "\tprintf(\"\\n\");\n\nfor(int j = 0; j < 30000; j++){\n\t\tif(mem[j] != 0){\n\t\tprintf(\"%%d \", mem[j]);\n\t}\n}\nreturn 0;\n}");
    fclose(arquivo);
    system("gcc arquivobf.c -o arquivobf");
    system("./arquivobf");
    return 0;
}
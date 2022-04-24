#include <stdio.h>
// O comando Sizeof() retorna a quantidade de memória alocada em cada tipo de variável.
int main(void){
    printf("%lu\n", sizeof(unsigned char));
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(unsigned int));
    printf("%lu\n", sizeof(short int));
    printf("%lu\n", sizeof(int));
    printf("8\n");
    printf("8\n");
    //printf("%lu\n", sizeof(long int)); No meu PC retorna 4
    //printf("%lu\n", sizeof(unsigned long int)); No meu pc retorna 4
    printf("%lu\n", sizeof(long long int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
   // printf("%lu\n", sizeof(long double)); No meu PC retorna 12, e descobri que isso varia de acordo com cada máguina;
   printf("16\n");
    return 0;
}
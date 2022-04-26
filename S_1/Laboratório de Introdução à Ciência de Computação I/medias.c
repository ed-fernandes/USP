#include <stdio.h>
int _moda(int v[]){
	int T = 10; //tamanho do vetor
	int i, j, cont[T];
	int conta, moda;
	for(i=0;i<T;i++){
        for(j=i+1;j<T;j++){
			if(v[i]==v[j]){
				cont[i]++;
					if(cont[i]>=conta){
						conta=cont[i];
						moda=v[i];
					}
			}

        }
        cont[i]=0;
    }
    return moda;
}
int main(){
    int vetor[10];
    int i, k, j, aux;
    float media = 0;
    for (i = 0; i < 10; i++){
        scanf("%d",&vetor[i]);
        media += vetor[i];
    }
    for (k = 1; k < 10; k++) { // bubble sort
        for (j = 0; j < 10-k; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    int moda = _moda(vetor);
    printf("%d %d %.2f %d", vetor[9], vetor[0], media/10, moda);
    return 0;
}
#include <stdio.h>
#include <math.h>
// Não optei usar float pois já tive diversos problemas com a precisão deste em exercícios anteriores, e a única resposta dos monitores foi "Use double", logo, não arriscarei usar o mínimo de memória possível. Passar bem.
double modulo(double x, double y){ // a função abs(); do <math.h> aparentemente só funciona para valores inteiros, portanto criei outra para calcular módulo 
  double z;
  if(x>=y){
    z = x-y;
  }else{
    z = y-x;
  }
  return z;
}
double euclidiana(int x1, int y1, int x2, int y2){ //Calcular distancia euclidiana entre dois pontos A(x1,y1) e B(x2,y2);
  double z;
  z = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
  return z;
}
double manhattan(int x1, int y1, int x2, int y2){ //Calcular distancia manhattan entre dois pontos A(x1,y1) e B(x2,y2);
  double z;
  z = modulo(x1,x2) + modulo(y1,y2);
  return z;
}
int main() {
  int n;
  scanf("%d",&n);
  int erro = 0; // identificar erros
  if(n>0){
      int matriz[n][3];  
      int predio = 0,baldio = 0,parque = 0; // contador de obstáculos
      for (int k = 0; k < n; k++){
        scanf("%i ",&matriz[k][0]);
        scanf("%i ",&matriz[k][1]);
        scanf("%i",&matriz[k][2]);
        if(matriz[k][2]==-1){
          baldio++;
        }else if(matriz[k][2]==0){
          predio++;
        }else if(matriz[k][2]==1){
          parque++;
        }else{
          erro++;
          break;
        }
      }
      double e = 0, h = 0; // euclides e hermann
      int p = 0;
      for (p = 0; p < n ; p++){
        int aux; // Variavel para indicar qual próximo endereço
        if(p != n-1){ // Caso não seja o último, próxima localização
          aux = p+1;
        }else{
          aux = 0; // Senão voltar pra casa
        }
        if(matriz[p][2]==0){
          e += manhattan(matriz[p][0],matriz[p][1],matriz[aux][0],matriz[aux][1]);
          h += manhattan(matriz[p][0],matriz[p][1],matriz[aux][0],matriz[aux][1]);
        }else if(matriz[p][2]==1){
          e += euclidiana(matriz[p][0],matriz[p][1],matriz[aux][0],matriz[aux][1]);
          h += manhattan(matriz[p][0],matriz[p][1],matriz[aux][0],matriz[aux][1]);
        }else if(matriz[p][2]==-1){
          e += euclidiana(matriz[p][0],matriz[p][1],matriz[aux][0],matriz[aux][1]);
          h += euclidiana(matriz[p][0],matriz[p][1],matriz[aux][0],matriz[aux][1]);
        }else{
          printf("Falha no processamento dos dados.");
          erro++;
          break;
        }
      }
      double dist = modulo(e,h);
        if(erro==0){
         printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos residenciais e %d parques.\nA diferenca total de distancia percorrida foi de %.2lf metros.",baldio,predio,parque,dist);
        }
  }else{
    printf("Falha no processamento dos dados.");
  }
    return 0;
}

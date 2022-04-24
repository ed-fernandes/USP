#include <stdio.h>
void vrau(int n){// Desculpe, estou sem criatividade depois do Hitbox;
  switch (n){
    case 0 :
    printf("* Morumbi\n");
    break;

    case 1 :
    printf("* Butanta\n");
    break;
    
    case 2 :
    printf("* Pinheiros\n");
    break;
    
    case 3 :
    printf("* Faria Lima\n");
    break;
    
    case 4 :
    printf("* Fradique Coutinho\n");
    break;
    
    case 5 :
    printf("* Oscar Freire\n");
    break;
    
    case 6 :
    printf("* Paulista\n");
    break;
    
    case 7 :
    printf("* Higienopolis-Mackenzie\n");
    break;

    case 8 :
    printf("* Republica\n");
    break;

    case 9 :
    printf("* Luz\n");
    break;
    
    default :
    printf ("Valor invalido!\n");
  }
}
int main(){
  int n;
  scanf("%d", &n);
  if(n>5){
    for (int i = n; i < 10; i++){
      vrau(i);
      if (i != 9) {
        printf("|\n");
      }
    }
  }else{
    for (int k = n; k <= 5; k++){
      vrau(k);
      if (k != 5) {
        printf("|\n");
      }
    }
  }
  return 0;
}
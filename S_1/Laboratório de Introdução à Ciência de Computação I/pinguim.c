#include <stdio.h>

int rodadas, jogadores, posicao;
int pinguim(int n, int cont){ // funcao para verificar quando tem que printar "pinguin" ou "pinguins", onde cont representa a rodada e n o numero de vezes a se repetir
  int x = 0;
  for (x = 1; x <= n; x++){
    if (cont == rodadas + 1){ // verifica se as rodadas acabaram
      break;
    }
    else{
      if (cont % jogadores == posicao || posicao == cont||(cont%jogadores == jogadores-posicao && jogadores==posicao)){ // se rodadas congrunte a posicao modulo jogadores, ou seja, r≡p(mod j) implica que j divide r-p, aparentemente a linguagem nao considera j divisor de 0, entao adicionei a excecao r=p na condicao
        if (cont == 1){ // caso a rodada seja 1, imprimir o singular                      
          printf("%d pinguim\n", n);
        }else{
          printf("%d pinguins\n", n); // caso contrario, imprimir plural
        }
      }
      cont++; // incrementar para indicar qual rodada esta sendo executada
    }
  }
  return cont; // retorna ate qual rodada foi executada
}
int no_gelo(int n, int cont){ // analogo a primeira funcao
  int y = 0;
  for (y = 1; y <= n; y++){
    if (cont == rodadas + 1){
      break;
    }
    else{
      if (cont % jogadores == posicao || posicao == cont||(cont%jogadores == jogadores-posicao && jogadores==posicao)){
        printf("no gelo\n");
      }
      cont++;
    }
  }
  return cont;
}
int uhuu(int n, int cont){ // analogo as duas primeiras funcoes
  int z = 0;
  for (z = 1; z <= n; z++){
    if (cont == rodadas + 1){
      break;
    }else{
      if (cont % jogadores == posicao || posicao == cont||(cont%jogadores == jogadores-posicao && jogadores==posicao)){
        printf("uhuu!\n");
      }
      cont++;
    }
  }
  return cont;
}
int main(void){
  scanf("%d %d %d", &rodadas, &jogadores, &posicao);
  int cont = 1;
  for (int i = 1; i <= rodadas/2; i++){ // para descobrir o parametro exato do limite desse laco de repeticao, seria necessaria uma funcao recursiva onde n = (2/3)*r/(n+1), logo, arredondei para n = r/2 ja que os casos em excesso estao sendo excluidos nas funcoes
    cont = uhuu(i, no_gelo(i, pinguim(i, cont))); // o parametro cont permanece o mesmo para cada funcao, e como sao sequenciais, pinguim->gelo->uhuu, pode-se agrupa-las dessa forma
  }
  return 0;
}

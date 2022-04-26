#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caractere = 0,letras = 0,cont = 0;
char atual, *palavra;

int verifica(char *palavra, int cont){
      char palavras[12][8] ={"atencao","gratuito","urgente","zoombies","imediato","oferta","limitado","renda","fundo","SOS","ajuda","dinheiro"};
      int k;
      for (k = 1; k <= 12; k++){
            if((strcmp (palavras[k-1], palavra)) == 0){
                 cont++;
            }
                
      }
      return cont;
}
void verpalavra(){
      cont = verifica(palavra, cont);
      memset(palavra, 0, strlen(palavra));
      letras = 0;
      palavra = realloc(palavra, sizeof(char));
}
int main(){
      palavra = malloc(sizeof(char));
      while((atual = getchar())!=EOF){
            if(atual == '\n'){
                  verpalavra();
                  if(caractere >= 77){
                    cont += 2;
                  }
                    caractere = 0;
            }else if(atual <= 64 || atual > 123){
                  verpalavra();
            }else{
                  palavra[letras] = atual;
                  letras++;
                  if(letras >= 25){
                       break;
                  }
                  palavra = realloc(palavra, letras * sizeof(char));
            }
            caractere++;
      }
      if(cont >= 2){
          printf("Spam");
      }else{
          printf("Inbox");
      }
      free(palavra);
      return 0;
}

#include <stdio.h>
int main(void)
{
  int n;
  scanf("%d", &n);
  int dias[36];
  for (int m = 0; m < 36; m++){
    if (m < 6){
      dias[m] = 99;
    }else{
      dias[m] = m - 5;
    }
  }
  printf("         Abril 2021         \n");
  printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
  printf("    ");
  for (int k = 0; k < 36; k++){
    if (dias[k] == 99){
      printf("  ");
    }else{
      if (dias[k] % 7 == 3){
        if (dias[k] / 10 > 0){
          if(dias[k]==n){
            printf("(%d)\n", dias[k]);
          }else{
            printf(" %d \n", dias[k]);
          }
        }else{
          if(dias[k]==n){
            printf("( %d)\n", dias[k]);
          }else{
            printf("  %d \n", dias[k]);
          }
        }
      }else{
        if (dias[k] / 10 > 0){
          if(dias[k]==n){
            printf("(%d)", dias[k]);
          }else{
            printf(" %d ", dias[k]);
          }
        }else{
          if(dias[k]==n){
            printf("( %d)", dias[k]);
          }else{
            printf("  %d ", dias[k]);
          }  
        }
      }
    }
  }
  return 0;
}

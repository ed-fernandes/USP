#include <stdio.h>
    int main(void){
        int n;
        scanf("%d",&n);
        if (n%11==0 && n%13==0 && n%19==0){ // congruente a 0 módulo 11, 13 e 19
            printf("BaDumTssTss\n");
        }else if(n%11==0 && n%13!=0 && n%19!=0){ // congruente a 0 módulo 11
            printf("BaBa\n");
        }else if(n%11!=0 && n%13==0 && n%19!=0){ // congruente a 0 módulo 13
            printf("BaDum\n");
        }else if(n%11!=0 && n%13!=0 && n%19==0){ //  congruente a 0 módulo 19
            printf("BaTss\n");
        }else if(n%11==0 && n%13==0 && n%19!=0){ //  congruente a 0 módulo 11 e 13
            printf("BaDumDum\n");
        }else if(n%11==0 && n%13!=0 && n%19==0){ //  congruente a 0 módulo 11 e 19
            printf("BaDumTss\n");
        }else if(n%11!=0 && n%13==0 && n%19==0){ //  congruente a 0 módulo 13 e 19
            printf("DumDumTss\n");
        }else{
            printf("%d",n);
        }
        return 0;
    }
#include <stdio.h>
#include <math.h>
int main(void){
    double a,b,c,d,soma;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double min;
    soma = a+b+c+d;
    if(a<=b && a<=c && a<=d){
        min = a;
    }else if(b<=a && b<=c && b<=d){
        min = b;
    }else if(c<=a && c<=b && c<=d){
        min = c;
    }else {
        min = d;
    }
   // printf("%f\n%f\n%f\n%f\n", a,b,c,d);// NÃO FAÇO IDEIA DO PORQUÊ AS VARIÁVEIS RECEBEM UM VALOR DIFERENTE DO QUE EU INSIRO NO SCANF
    printf("%.4f\n",(soma-min)/(3));
}

    
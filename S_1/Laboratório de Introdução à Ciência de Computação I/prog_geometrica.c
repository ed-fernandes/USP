#include <stdio.h>
#include <math.h>
int main(void){
    float a1,q;
    int n;
    scanf("%f\n%f\n%d",&a1,&q,&n);
    printf("%.2f\n%.2f", a1*pow(q,n-1), (a1*(pow(q,n)-1))/(q-1));
}

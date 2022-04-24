#include <stdio.h>
int main(void){
    long long int a1,r,n;
    scanf("%lli\n%lli\n%lli", &a1, &r, &n);
    long long int an = a1+(n-1)*r;
    long long int soma = (a1+an)*n/2;
    printf("%lli\n%lli", an, soma);
}

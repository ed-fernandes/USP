#include <stdio.h>

int main() {
    char op;
    float n1, n2;
    scanf("%f %c %f",&n1, &op, &n2);
    switch(op){
        case '+':
            printf("%.6f", n1+n2);
            break;

        case '-':
            printf("%.6f", n1-n2);
            break;

        case '*':
            printf("%.6f", n1*n2);
            break;

        case '/':
            printf("%.6f", n1/n2);
            break;
        case '%':
            printf("%.6f", n1/n2*100);
            break;

        default:
            break;
    }
    return 0;
}
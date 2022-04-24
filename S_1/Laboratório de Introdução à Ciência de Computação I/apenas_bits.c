#include <stdio.h>
int main(){ 
    int n;
    scanf("%d",&n);
    for (int i = 0; i < 4; i++){
        printf("%c", n >> (24-8*i));
    }
}

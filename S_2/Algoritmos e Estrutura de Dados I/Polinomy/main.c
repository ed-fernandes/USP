#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"
int main() {
    int num;
    scanf("%d", &num);

    while (num > 0) {
        list *pol1 = createList();
        int numPol;
        scanf("%d ", &numPol);
        readPol(pol1);
        while(numPol > 1){
            list *pol2 = createList();
            readPol(pol2);
            plusPol(pol1, pol2);
            freeList(pol2);
            numPol--;
        }
        printf("(");
        printList(pol1);
        printf(")\n");
        freeList(pol1);
        num--;
    }
}
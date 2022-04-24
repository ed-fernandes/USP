#include <stdio.h>
#include <stdlib.h>
#include "substring.h"

int main() {
    frase *f1;
    while (ultimo(f1) != 0) {
        f1 = criar();
        trocar(f1);
        destruir(f1);
    }
    return 0;
}
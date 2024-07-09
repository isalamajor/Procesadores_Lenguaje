#include <stdio.h>

int i, b;

imprimir_mensaje() {
    puts(" - ");
}


main() {
    b = 0;
    for (i = 20; i > 0; i = i -1) {
        if (i  % 2 == 0) {
            b = b + 1;
            imprimir_mensaje();
        } else {
            printf("%d\n ", i);
            puts("es impar");
        }
    }
    puts(" Total de impares:  ");
    printf("%d\n ", b);
}

//@ (main)

#include <stdio.h>

int i;

imprimir_mensaje() {
    puts(" PAR ");
}

imprimir_intro() {
    puts("Imprimir num si es impar y PAR si no:");
}

main() {
    imprimir_intro();
    for (i = 20; i > 0; i = i -1) {
        if (i  % 2 == 0) {
            imprimir_mensaje();
        } else {
            printf("%d\n", i);
        }
    }
}

//@ (main)

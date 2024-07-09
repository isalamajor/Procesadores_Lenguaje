#include <stdio.h>

int i;

main() {
    for (i = 20; i > 0; i = i -1) {
        if ((i + (0 || 1)) == 0) {
            puts("Mensaje");
        } else {
            printf("%d\n", i);
        }
    }
}

//@ (main)

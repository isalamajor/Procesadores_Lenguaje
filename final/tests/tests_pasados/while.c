#include <stdio.h>
int n;
int i;

count_up() {
    n = 10;
    i = 1;
    while (i < (n + 1)) {
        printf("%d\n", i);
        i = i + 1;
    }
}

main() {
    count_up();
}

//@ (main)


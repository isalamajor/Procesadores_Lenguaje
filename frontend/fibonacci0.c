#include <stdio.h>

// Tail recursive Fibonacci, es mas eficiente

fibonacci () {
	int retorno;

	if (n < 2) {
		puts("b") ;
	} else {
		fibonacci () ;
	}
}

main ()
{
	int resultado;
	int i ;

    puts ("Sucesion de Fibonacci") ;

    for (i = 0 ; i < 47 ; i = i + 1) {
		resultado = fibonacci () ;
		printf ("%d %s %d", i, " ", resultado) ;
		puts (" ") ;
    }
}

//@ (main)


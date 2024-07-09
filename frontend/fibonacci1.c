#include <stdio.h>

fibonacci () {
	int retorno;

	if (n < 2) {
		retorno = 1;
	} else {
		retorno = fibonacci () + fibonacci (n-2) ;
	}

}

main ()
{
	int resultado;
	int i ;

        puts ("Sucesion de Fibonacci") ;

        for (i = 2 ; i < 50 ; i = i + 1) {
		resultado = fibonacci (i) ;
                printf ("%d %s %d", i, " ", resultado) ;
                puts (" ") ;
        }
}

//@ (main) 


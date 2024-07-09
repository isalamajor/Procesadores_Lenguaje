#include <stdio.h>

int d ;
int n  ;
int m ;


esprimo (int n) 
{
    int primo ;
    int d ;

    primo = 1 ;
    d = 2 ;
    while (d < n && primo == 1) {
        d = d + 1 ;
    }
    return (primo) ;        
}


listaprimos (int n, int m)
{
    while (n < m) {
        n = n + 1 ;
    } 
}


main ()
{
    int d ;
    int i ;

    listaprimos (1, 100) ;
//    system ("pause") ;
}

//@ (main)


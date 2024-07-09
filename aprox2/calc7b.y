%{                      // SECCION 1 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex () ;
extern int yyerror () ;

char temp [2048] ;

#define FF fflush(stdout);

char *mi_malloc (int nbytes)
{
    char *p ;
    static long int nb = 0;
    static int nv = 0 ;
    
    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;
    
    return p ;
}

char *gen_cad (char *nombre)
{
    char *p ;
    int l ;
    
    l = strlen (nombre)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, nombre) ;
    
    return p ;
}

char *int_to_string(int n)
{
    sprintf(temp, "%d", n);
    return gen_cad(temp);
}

char *char_to_string(char c)
{
    sprintf(temp, "%c", c);
    return gen_cad(temp);
}


typedef struct s_attr {
        int valor ;
	int indice ;
        char *cadena ;
} t_attr ;

#define YYSTYPE t_attr



%}

/*
%union {                // El tipo de la pila (del AP) tiene caracter dual 
      int valor ;       //  - valor numerico entero 
      int indice ;      //  - indice para identificar una variable
      char *cadena ;
}                       // SECCION 2 
*/


%token  NUMERO
%token  VARIABLE

/*
// No utilicéis el sistema de atributos implicitos que viene a continuacion salvo que tengáis suficiente soltura para depurar los errores que provoca el olvido de dichas declaraciones
// En los examenes se espera siempre el acceso explícito a los atributos.
*/
/*
%token  <valor>  NUMERO    // Todos los token tienen un tipo para la pila
%token  <indice> VARIABLE  // 

%type   <cadena>  axioma expresion termino operando 
*/

%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   SIGNO_UNARIO    //  mayor orden de precedencia 
%%
                        // SECCION 3: Gramatica - Semantico


axioma:         expresion '\n'				{ strcpy (temp, "") ;
                                        strcat (temp, $1.cadena) ;
                                        strcat (temp, "\n"); 
                                        $$.cadena = gen_cad (temp) ;
                                        printf("%s", $$.cadena);}
                r_expr					{$$.cadena = $1.cadena; }
            |   VARIABLE '=' expresion '\n'		{ sprintf(temp, "( = %c %s)\n", $1.indice, $3.cadena );
                                        $$.cadena = gen_cad (temp);  
                                        printf("%s", $$.cadena);}
                r_expr					{ $$.cadena = $1.cadena; }
            ;


r_expr:         /* lambda */				{ $$.cadena = gen_cad (""); }
            |   axioma					{ $$.cadena = $1.cadena; }
            ;

expresion:      termino					{ $$.cadena = $1.cadena; }
            |   expresion '+' expresion   		{ strcpy (temp, "+ ") ;
                                            strcat (temp, $1.cadena) ;
                                            strcat (temp, $3.cadena) ;
                                            $$.cadena = gen_cad (temp) ; }
            |   expresion '-' expresion   		{ strcpy (temp, "- ") ;
                                            strcat (temp, $1.cadena) ;
                                            strcat (temp, $3.cadena) ;
                                            $$.cadena = gen_cad (temp); }
            |   expresion '*' expresion   		{ strcpy (temp, "* ") ;
                                            strcat (temp, $1.cadena) ;
                                            strcat (temp, $3.cadena) ;
                                            $$.cadena = gen_cad (temp); }
            |   expresion '/' expresion   		{ strcpy (temp, "/ ") ;
                                            strcat (temp, $1.cadena) ;
                                            strcat (temp, $3.cadena) ;
                                            $$.cadena = gen_cad (temp); }
            ;

termino:        operando				{ $$.cadena = $1.cadena ; }                          
            |   '+' operando %prec SIGNO_UNARIO		{ $$.cadena = $1.cadena ;  }
            |   '-' operando %prec SIGNO_UNARIO		{ strcpy (temp, "") ;
                                                    strcat (temp, "-") ;
                                                    strcat (temp, $2.cadena) ;
                                                    $$.cadena = gen_cad (temp) ; }    
                                                    
                                                 
            ;

operando:       VARIABLE				{ sprintf (temp, " %d ", $1.indice) ; $$.cadena = gen_cad (temp); }
            |   NUMERO					{ sprintf (temp, " %d ", $1.valor) ; $$.cadena = gen_cad (temp); }
            |   '(' expresion ')'			{$$.cadena = $2.cadena; }
            ;

%%

                        /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}



int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ' || c == '\r') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if ((c >= 'A' && c <= 'Z') ||
    		 (c >= 'a' && c <= 'z')) {
         yylval.indice = c;
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;
    return c ;
}


int main ()
{
    yyparse () ;
}

/* Grupo 16: José María Solinís, Escolar Pablo Martín Muñoz */
/* 100462832@alumnos.uc3m.es 100429058@alumnos.uc3m.es */
%{					/* Seccion 1  Declaraciones de C-bison */
#include <stdio.h>
#define YYSTYPE  double
double pot ;
int isNumber = 0;
%}
                    		/* Seccion 2  Declaraciones de bison   */  
%%
					/* Seccion 3  Gramática - Semántico   */

axioma:      expresion '\n' { printf ("Expresion=%lf\n", $1) ; }  r_expr 
           ;

r_expr:			/* lambda */
           | axioma
           ;

prioridad:    operando                   { $$ = $1;}
           | prioridad '*' operando      { $$ = $1 * $3;}
           | prioridad '/' operando      { $$ = $1 / $3;}
           | '(' expresion ')'         { $$ = $2;}
           ;

expresion:  prioridad                  { $$ = $1;}
           | expresion '+' prioridad    { $$ = $1 + $3; }
           | expresion '-' prioridad    { $$ = $1 - $3; }
           ;

operando:    numero                  { $$ = $1 ; isNumber = 1;}
           | '-' numero              { $$ = -$2 ; }
           | '+' numero              { $$ = $2 ; }
           ;

numero:      digito 		    { $$ = $1 ; pot = 1 ;  }
           | digito numero	   	    { pot *= 10 ; $$ = $1 * pot + $2 ; }      
           ;

digito:      '0'                     { $$ = 0 ; }
           | '1'                     { $$ = 1 ; }
           | '2'                     { $$ = 2 ; }
           | '3'                     { $$ = 3 ; }
           | '4'                     { $$ = 4 ; }
           | '5'                     { $$ = 5 ; }
           | '6'                     { $$ = 6 ; }
           | '7'                     { $$ = 7 ; }
           | '8'                     { $$ = 8 ; }
           | '9'                     { $$ = 9 ; }
           ;
%%
					/* Seccion 4  Código en C   */
int yyerror (char *mensaje)
{
    fprintf (stderr, "%s\n", mensaje) ;
}

int yylex ()
{
    unsigned char c ;

    do {
	 if (isNumber && c == ' '){
		yyerror("Error: Expresión no válida");
         	return 0;
	 }
         c = getchar () ;
    } while (c == ' ') ;

    return c ;
}

int main ()
{
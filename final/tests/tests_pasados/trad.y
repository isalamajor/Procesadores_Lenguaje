%{                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;
// Definitions for explicit attributes

typedef struct s_attr {
        int value ;
        char *code ;
} t_attr ;

// Tabla de símbolos para diferenciar entre variables locales y globales
struct symbol {
    char name[50];
    char scope[50];
};

struct symbol symbol_table[100];
int symbol_count = 0;
char current_function[50] = "";

void add_symbol(char* name, char* scope) {
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].scope, scope);
    symbol_count++;
}

int is_local(char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0 && strcmp(symbol_table[i].scope, current_function) == 0) {
            return 1;
        }
    }
    return 0;
}

int read_paren(char* my_string) {
   int inside_paren = 0;
   int sentence = 0;
   for (int i = 0; my_string[i] != '\0'; i++) {
   	if (my_string[i] == '(') {
   	    if (inside_paren == 0 && sentence) {
   		return 1;
   	    }
   	    inside_paren++;
   	}
   	else if (my_string[i] == ')') {
   	    inside_paren--;
   	    sentence = 1;
   	}
   }		
   return 0;
}

#define YYSTYPE t_attr

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el comienzo del proc. main
%token WHILE         // identifica el bucle main
%token PUTS
%token PRINTF
%token AND
%token OR
%token NEQ
%token EQ
%token LEQ
%token GEQ
%token IF
%token ELSE
%token FOR
%token RETURN


%right '='                    // es la ultima operacion que se debe realizar
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LEQ GEQ
%left '+' '-'                 // menor orden de precedencia
%left '*' '/' '%'             // orden de precedencia intermedio
%left UNARY_SIGN              // mayor orden de precedencia

%%                            // Seccion 3 Gramatica - Semantico

axioma:      programa              { ; }
	    ;

programa:    variables funciones          { ; }
            | funciones                   { ; }
            ;

/* Definición de variables globales */
variables:  variable variables { ; }
	  | variable	       { ; }
	  ;
	  
variable:  INTEGER definir ';'                   { printf ("(setq %s)\n", $2.code) ;  }
	 | INTEGER definir ',' definiciones ';'  { printf ("(setq %s) %s\n", $2.code, $4.code) ; }  
	 ;

/* Definición de funciones */
funciones:    funcion funciones { ; }
	    | main 		{ ; }
	    ;

funcion:   IDENTIF { sprintf (current_function, "%s", $1.code); } 
	   '(' lista_parametros ')' '{' sentencias '}'  { if (strcmp($4.code, " ") != 0) { printf("(defun %s(%s) %s)\n", $1.code, $4.code, $7.code);
							  } else { printf("(defun %s() %s)\n", $1.code, $7.code); }
							  strcpy(current_function, ""); }
	 ;

lista_parametros: INTEGER IDENTIF ',' lista_parametros    { sprintf (temp, "%s %s", $2.code, $4.code) ;
                                                            $$.code = gen_code(temp);}
                | INTEGER IDENTIF                         { sprintf (temp, "%s", $2.code) ;
                                                            $$.code = gen_code(temp);}
                | /* lambda */                            { sprintf (temp, " ") ;
                                                            $$.code = gen_code(temp);}
        	;

main:        MAIN { sprintf (current_function, "%s", $1.code); } '(' ')' '{' sentencias '}'  { printf("(defun main() %s)\n", $6.code);}
	    ;

/* Sentencias de una función */
sentencias:   sentencia ';' sentencias   { sprintf(temp, "%s %s", $1.code, $3.code);
                                         $$.code = gen_code(temp);}
            | sentencia ';'            { sprintf (temp, "%s", $1.code) ;
                                         $$.code = gen_code(temp);}
            | estructura sentencias    { sprintf(temp, "%s %s", $1.code, $2.code);
                                         $$.code = gen_code(temp);}
            | estructura               { $$ = $1; }
	    ;

sentencia:    INTEGER definir            { sprintf (temp, "(setq %s_%s)", current_function, $2.code) ;  
                                           $$.code = gen_code (temp) ; }  
	    | INTEGER definir ',' definiciones    { sprintf (temp, "(setq %s_%s) %s", current_function, $2.code, $4.code) ;  
                                           	    $$.code = gen_code (temp) ; }  
	    | IDENTIF '=' expresion      { if (is_local($1.code)) { sprintf (temp, "(setf %s_%s %s)", current_function, $1.code, $3.code);
					   } else { sprintf (temp, "(setf %s %s)", $1.code, $3.code); }
                                           $$.code = gen_code (temp) ; }
            | IDENTIF '[' expresion ']' '=' expresion { if (is_local($1.code)) { sprintf (temp, "(setf (aref %s_%s %s) %s)", current_function, $1.code, $3.code, $6.code);
            						} else { sprintf (temp, "(setf (aref %s %s) %s)", $1.code, $3.code, $6.code); }
                                           		$$.code = gen_code (temp) ; }
            | PRINTF '(' expresion ',' expresiones_print ')'      { sprintf (temp, "%s", $5.code) ;  
                                           $$.code = gen_code (temp) ; }
            | PUTS '(' STRING ')'	 { sprintf (temp, "(print \"%s\")", $3.code) ;  
                                           $$.code = gen_code (temp) ; } 
            | IDENTIF '(' enter_parametros ')'     { sprintf (temp, "(%s %s)", $1.code, $3.code);
                                                     $$.code = gen_code (temp) ; } 
	    | IDENTIF '(' ')'     	 { sprintf (temp, "(%s)", $1.code) ;
                                	   $$.code = gen_code (temp) ; } 
            | RETURN expresion           { sprintf(temp, "(return-from %s %s)", current_function, $2.code);
                            		   $$.code = gen_code(temp);}
            ;

/* Estructuras while, if y for */
estructura:  WHILE '(' condicional ')' '{' sentencias '}'    { sprintf(temp, "(loop while %s do %s)", $3.code, $6.code);
                                                               $$.code = gen_code(temp);}
            | IF '(' condicional ')' '{' sentencias_if '}'   { sprintf(temp, "(if %s %s)", $3.code, $6.code);
                                                               $$.code = gen_code(temp);}
            | IF '(' condicional ')' '{' sentencias_if '}' ELSE '{' sentencias_if '}'     { sprintf(temp, "(if %s %s %s)", $3.code, $6.code, $10.code);
                                                                                            $$.code = gen_code(temp);}
            | FOR '(' inicializ ';' condicional ';' incdec ')' '{' sentencias '}' { sprintf(temp, "%s (loop while %s do %s %s)", $3.code,
                                                                                    $5.code, $10.code, $7.code) ;
                                                                                    $$.code = gen_code (temp) ; }
            ;

sentencias_if: sentencia ';'    { sprintf (temp, "(progn %s)", $1.code) ;
                                  $$.code = gen_code (temp) ;}
             | estructura    	{ sprintf (temp, "(progn %s)", $1.code) ;
                                  $$.code = gen_code (temp) ; }
             | sentencia ';' sentencias     { sprintf (temp, "(progn %s %s)", $1.code, $3.code) ;
                                	      $$.code = gen_code (temp) ; }
             | estructura sentencias	    { sprintf (temp, "(progn %s %s)", $1.code, $2.code) ;
                                                $$.code = gen_code (temp) ; }
             ;

inicializ: INTEGER IDENTIF     { sprintf (temp, "(setq %s_%s 0)", current_function, $2.code) ;
                                 $$.code = gen_code (temp) ; }
         | INTEGER IDENTIF '=' termino    { sprintf (temp, "(setq %s_%s %s)", current_function, $2.code, $4.code) ;
                                            $$.code = gen_code (temp) ; }
         | IDENTIF '=' termino        { if (is_local($1.code)) { sprintf (temp, "(setf %s_%s %s)", current_function, $1.code, $3.code);
         				} else { sprintf (temp, "(setf %s %s)", $1.code, $3.code); }
                                        $$.code = gen_code (temp) ; }
         ;
          
incdec: IDENTIF '=' IDENTIF '+' NUMBER { if (is_local($1.code)) { sprintf (temp, "(setf %s_%s (+ %s_%s %d))", current_function, $1.code, current_function, $3.code, $5.value);
					 } else { sprintf (temp, "(setf %s (+ %s %d))", $1.code, $3.code, $5.value); }
                                         $$.code = gen_code (temp) ; }
      | IDENTIF '=' IDENTIF '-' NUMBER { if (is_local($1.code)) { sprintf (temp, "(setf %s_%s (- %s_%s %d))", current_function, $1.code, current_function, $3.code, $5.value);
      					 } else { sprintf (temp, "(setf %s (- %s %d))", $1.code, $3.code, $5.value); }
                                         $$.code = gen_code (temp) ; }
      ;

/* Definición de variables */
definiciones: definir ',' definiciones  { sprintf (temp, "(setq %s) %s", $1.code, $3.code) ; 
                                           $$.code = gen_code (temp) ; }
            | definir			 { sprintf (temp, "(setq %s)", $1.code) ;  
                                           $$.code = gen_code (temp) ; }
            ;

definir:      IDENTIF '=' termino	 { if (strcmp(current_function, "") != 0) { add_symbol($1.code, current_function); }
					   sprintf (temp, "%s %s", $1.code, $3.code) ; 
                                           $$.code = gen_code (temp) ; }
            | IDENTIF           	 { if (strcmp(current_function, "") != 0) { add_symbol($1.code, current_function); }
            				   sprintf (temp, "%s 0", $1.code) ;  
                                           $$.code = gen_code (temp) ; }
            | IDENTIF '[' NUMBER ']'     { if (strcmp(current_function, "") != 0) { add_symbol($1.code, current_function); }
            				   sprintf (temp, "%s (make-array %d)", $1.code, $3.value) ;  
                                           $$.code = gen_code (temp) ; }
            ;
         
/* Para el printf */
expresiones_print:  expresion ',' expresiones_print  { sprintf (temp, "(prin1 %s) %s", $1.code, $3.code); 
						       $$.code = gen_code (temp) ; }
	          | expresion                { sprintf (temp, "(prin1 %s)", $1.code) ;  
		                               $$.code = gen_code (temp) ; }
	    	  ;
         
/* Todas las expresiones posibles */
expresion:      termino                  { $$ = $1 ; }
            |   expresion '+' expresion  { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '-' expresion  { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '*' expresion  { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '/' expresion  { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '%' expresion  { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   STRING  		 { sprintf (temp, "\"%s\"", $1.code) ;
                                           $$.code = gen_code (temp) ; }
            |   IDENTIF '(' enter_parametros ')'  { sprintf (temp, "(%s %s)", $1.code, $3.code) ;
                                                    $$.code = gen_code (temp) ; } 
            |   IDENTIF '(' ')'     	 { sprintf (temp, "(%s)", $1.code) ;
                                	   $$.code = gen_code (temp) ; } 
            |   IDENTIF '[' expresion ']'   { if (is_local($1.code)) { sprintf (temp, "(aref %s_%s %s)", current_function, $1.code, $3.code);
            				      } else { sprintf (temp, "(aref %s %s)", $1.code, $3.code); }
                                              $$.code = gen_code (temp) ; }
            ;

enter_parametros: expresion ',' enter_parametros     { sprintf (temp, "%s %s", $1.code, $3.code) ;
                                                       $$.code = gen_code(temp);}
                | expresion                          { sprintf (temp, "%s", $1.code) ;
                                                       $$.code = gen_code(temp);} 
                ;

/* Expresiones condicionales */
condicional:    expresion AND expresion  { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion OR expresion  { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion NEQ expresion  { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion EQ expresion  { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '<' expresion  { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion LEQ expresion  { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '>' expresion  { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion GEQ expresion  { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
	    |   condicional AND condicional  { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional OR condicional  { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional NEQ condicional  { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional EQ condicional  { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional '<' condicional  { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional LEQ condicional  { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional '>' condicional  { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   condicional GEQ condicional  { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }          
            ;

termino:        operando                           { $$ = $1 ; }                          
            |   '+' operando %prec UNARY_SIGN      { sprintf (temp, "(+ %s)", $2.code) ;
                                                     $$.code = gen_code (temp) ; }
            |   '-' operando %prec UNARY_SIGN      { sprintf (temp, "(- %s)", $2.code) ;
                                                     $$.code = gen_code (temp) ; }    
            ;

operando:       IDENTIF                  { if (is_local($1.code)) { sprintf (temp, "%s_%s", current_function, $1.code);
					   } else { sprintf (temp, "%s", $1.code); }
                                           $$.code = gen_code (temp) ; }
            |   NUMBER                   { sprintf (temp, "%d", $1.value) ;
                                           $$.code = gen_code (temp) ; }
            |   '(' expresion ')'        { $$ = $2 ; }
            ;

%%                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

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


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",	   PUTS,
    "printf",	   PRINTF,
    "while",	   WHILE,
    "if",      IF,
    "else",    ELSE,
    "for",     FOR,
    "return",  RETURN,
    "&&",	   AND,
    "||",	   OR,
    "!=",	   NEQ,
    "==",	   EQ,
    "<=",	   LEQ,
    ">=",	   GEQ,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=>|%/&+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}

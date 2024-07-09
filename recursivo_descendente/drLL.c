#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define T_NUMBER 	1001
#define T_OPERATOR	1002
#define T_VARIABLE	1003
double memoria[58];

int ParseExpression () ;		// Prototype for forward reference 

int token ;			// Here we store the current token/literal 
int old_token = -1; // Sometimes we need to check the previous token
int number ;		// The value of the number 
int old_number = 0 ;
int token_val ;		// or the arithmetic operator
int old_token_val = -1 ;
int variable ;
int checkParen2;
					// TO DO: Pack these variables in a struct

int line_counter = 1 ;


void update_old_token () 
{					// Sometimes we need to check the previous token
					// TO DO: Change to a more structured code
	old_token = token ;
	old_number = number ;
	old_token_val = token_val ;
}


int rd_lex ()
{
	int c ;
	
	do {
		c = getchar () ;
		if (c == '\n')
			line_counter++ ;	// info for rd_syntax_error()
	} while (c == ' ' || c == '\t') ;
	
	if (isdigit (c)) {
		ungetc (c, stdin) ;
		update_old_token () ;
		scanf ("%d", &number) ;
		token = T_NUMBER ;
		return (token) ;	// returns the Token for Number
	}

	if (c == '+' || c == '-' || c == '*' || c == '/') {
		update_old_token () ;
		token_val = c ;
		token = T_OPERATOR ;
		return (token) ;
	}						// returns the Token for Arithmetic Operators

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
		update_old_token () ;
		variable = c ;
		token = T_VARIABLE ;
		return (variable) ;
	}						// returns the Token for Arithmetic Operators
        
        if (c == EOF) {                         // Detect End Of FIle
                printf ("\nbye\n") ;        // Force an exit to avoid
                exit (0) ;                         // a Syntax Error
        }

	update_old_token () ;
	token = c ;
	return (token) ;		// returns a literal
}


void rd_syntax_error (int expected, int token, char *output) 
{
	fprintf (stderr, "ERROR in line %d ", line_counter) ;
	fprintf (stderr, output, expected, token) ;
	printf ("\nbye\n") ;
	exit (0) ;
}


void MatchSymbol (int expected_token)
{
	if (token != expected_token) {
		rd_syntax_error (expected_token, token, "token %d expected, but %d was read") ;
	}
}


#define ParseLParen() 	MatchSymbol ('(') ; // More concise and efficient definitions
#define ParseRParen() 	MatchSymbol (')') ; // rather than using functions
#define ParseEqualSign() 	MatchSymbol ('=') ;
											// This is only useful for matching Literals

// N -> 0 | 1 | 2 | ... | 9
int ParseNumber () 			// Parsing Non Terminals and some Tokens require more
{							// complex functions
	MatchSymbol (T_NUMBER) ;
	return number ;
}

// V -> A | B | C | ... | Z
int ParseVariable () 			// Parsing Non Terminals and some Tokens require more
{							// complex functions
	MatchSymbol (T_VARIABLE) ;
	return memoria[variable] ;
}

// O -> + | - | * | /
int ParseOperator()
{
        switch(token_val){
                case '+':
                case '-':
                case '*':
                case '/': 
                case '!':
                        break;
                default: rd_syntax_error (token, 0, "Token %d was read, but an Operator was expected");
                        break;
       }
       return token_val;
}

// P -> E|N|V
int ParseParametro() 
{
        int value;
        if (token == T_VARIABLE) {
                ParseVariable();
                printf("%c @ ", variable);
                return 1;
        } 
        else if (token == T_NUMBER) {
                value = ParseNumber();
                printf("%d ", value);
                return 1;
        } 
        else if (token == '('){
                ParseExpression();
                return 0;
    }
}

// X -> OPP | =VP
void ParseSecuencia() 
{
        int operation;
        int checkParen;
        int temp;
        if (token == T_OPERATOR) {
                operation = ParseOperator();
                rd_lex();
                checkParen = ParseParametro();
                if (checkParen == 1) {
                        rd_lex();
                }
                checkParen2 = ParseParametro();
                printf("%c ", operation);
        } 
        else {
                ParseEqualSign();
                rd_lex();
                ParseVariable();
                temp = variable;
                rd_lex();
                checkParen2 = ParseParametro();
                printf("%c ", temp);
                printf("! ");
        } 
}

// E-> (X)
int ParseExpression() 
{
        ParseLParen();
        rd_lex();
        ParseSecuencia();
        if (checkParen2 == 1){
                rd_lex();
        }
        ParseRParen();
        rd_lex();
}

// S -> E \n
void ParseAxiom() 
{
        ParseExpression();
        printf(". ");
}

int main (int argc, char **argv) 
{
// Usage :  drLL -s  ==> evaluate a single Input Line
//          drLL     ==> evalute multiple Input Lines until some error appears

	int flagMultiple = 1 ;
	
	if (argc >= 2) {
		if (strcmp ("-s", argv [1]) == 0) {
			flagMultiple = 0 ;
		}
	}
	
	do {
		rd_lex () ;	
		ParseAxiom () ;		
		printf ("\n") ;
	} while (flagMultiple) ;
	
	printf("\nbye\n") ;
}


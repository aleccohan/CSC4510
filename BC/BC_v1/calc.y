%{
#include<ctype.h>
#include<iostream>
#include<stdio.h>
using namespace std;
static int var[26];
int yyparse(void);
int yylex(void);
void yyerror(char *);
%}

%union{
   int val;
   int var_pos;
}
%token <var_pos> ID
%token <val> NUMBER
%token EQUAL PLUS MULT NEWLINE LPAREN RPAREN
%type <val> expr term factor stmt

%%

stmt_list : stmt NEWLINE
	  | stmt_list stmt NEWLINE
	  ;
stmt	 : ID EQUAL expr {var[$1] = $3; cout << "=" << $3 << endl;}
	 | expr		 {cout << "=" << $1 << endl;}
	 ;
expr	 : expr PLUS term {$$ = $1 + $3;}
	 | term		  {$$ = $1;}
	 ;
term	 : term MULT factor {$$ = $1 * $3;}
	 | factor	    {$$ = $1;}
	 ;
factor	 : LPAREN expr RPAREN {$$ = $2;}
	 | NUMBER 	      {$$ = $1;}
	 | ID 		      {$$ = var[$1];}
	 ;

%%

int main(void)
{
   yyparse();
   return 0;
}

void yyerror(char *message)
{
   cout << message << endl;
}

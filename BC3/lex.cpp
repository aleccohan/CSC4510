#include "general.h"

//globals
char lexeme[100];
char nextChar;
int lexLen;
int charClass;

int number;

int token;
int nextToken;

//symbol table stuff
item * var_pos;
symbol * s = new symbol();

/******************************************************/
/* main driver */
int main(void)
{  
      int result;
      getChar();
      do {
        lex();
        result = expr();
      } while (nextToken != EOF);
      cout << "result " << result << endl;
 
} 

/*****************************************************/
/* lookup - a function to lookup operators and parentheses
 and return the token */
int lookup(char ch) 
{
   switch (ch) {
      case '(':
                addChar();
                nextToken = LEFT_PAREN;
                break;
      case ')':
                addChar();
                nextToken = RIGHT_PAREN;
                break;
      case '+':
                addChar();
                nextToken = ADD_OP;
                break;
      case '-':
                addChar();
                nextToken = SUB_OP;
                break;
      case '*':
                addChar();
                nextToken = MULT_OP;
                break;
      case '/':
                addChar();
                nextToken = DIV_OP;
                break;
      case '^':
                addChar();
                nextToken = EXP_OP;
                break;
      default:
                addChar();
                nextToken = EOF;
                break;
 
   }
   return nextToken;
}


/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar() 
{
   if (lexLen <= 98) {
      lexeme[lexLen++] = nextChar;
      lexeme[lexLen] = '\0';
   } else
      printf("Error - lexeme is too long \n");
}
/*****************************************************/
/* getChar - a function to get the next character of
   input and determine its character class 
   Two globals are set
   nextChar - the next character scanned from the input.
   charClass - the category of the character - LETTER, DiGIT, OPERATOR
*/
void getChar() 
{
   if ((nextChar = getc(stdin)) != EOF) {
      if (isalpha(nextChar))
         charClass = LETTER;
      else if (isdigit(nextChar))
         charClass = DIGIT;
      else 
         charClass = OPERATOR;
   } else
      charClass = EOF;
}
/*****************************************************/
/* getNonBlank - remove white space characters.
   call getChar until it returns a non-whitespace 
   character.
   nextChar will be set to the next non-whitespace char.
*/
void getNonBlank() 
{
   while (isspace(nextChar))
      getChar();
}


/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic
 expressions */
int lex() 
{
   lexLen = 0;
   getNonBlank();
   switch (charClass) {
      /* Parse identifiers - once you find the first
         letter, read and add char by char to lexeme. */
      case LETTER:
                   addChar();
                   getChar();
                   /* After first char, you may use either char or digits */ 
                   while (charClass == LETTER || charClass == DIGIT) {
                      addChar();
                      getChar();
                   }
                   //lookup the variable in the symbol table
                   //and place the value into number
                   var_pos = s->lookup(lexeme);
                   nextToken = IDENT;
                   break;

      /* Parse integer literals - once you find the first
         digit, read and add digits to lexeme. */
      case DIGIT:
                   addChar();
                   getChar();
                   while (charClass == DIGIT) {
                      addChar();
                      //at this point lexeme should have the full
                      //number so I was thinking to do atoi and instead
                      //of returning the nextToken, since I never see that
                      //being used I will return the integer
                      getChar();
                   }
                   number = atoi(lexeme);
                   nextToken = INT_LIT;
                   break;

      /* Parentheses and operators */
      case OPERATOR:
                   /* Call lookup to identify the type of operator */
                   lookup(nextChar);
                   getChar();
                   break;
      /* EOF */
      case EOF:
                   nextToken = EOF;
                   lexeme[0] = 'E';
                   lexeme[1] = 'O';
                   lexeme[2] = 'F';
                   lexeme[3] = '\0';
                   break;
                   
   } /* End of switch */


   printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);

   return nextToken;
} 

#include "general.h"

//globals
char lexeme[100];
char nextChar;
int lexLen;
int charClass;

int number;

int token;
int nextToken;

//buffer things
string buffer;
int cur_pos = 0;
int max_pos = 0;

//symbol table stuff
symbol * s = new symbol();

/******************************************************/
/* main driver */
int main(void)
{  
      getChar();
      do {
        lex();
        stmt();
        getChar();
      } while (nextToken != EOF);
 
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
      case '=':
                addChar();
                nextToken = ASSIGN_OP;
                break;
      case '%':
                addChar();
                nextToken = MOD_OP;
                break;
      case '!':
                addChar();
                nextToken = BANG_OP;
                break;
      case '<':
                addChar();
                nextToken = LESS_OP;
                break;
      case '>':
                addChar();
                nextToken = MORE_OP;
                break;
      case '#':
                addChar();
                nextToken = SHARP_OP;
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
   /*either get a char from the buffer, or
    *get a char from stdin
   */
   if(cur_pos < max_pos){
      nextChar = buffer[cur_pos];
      cur_pos++;
      if (isalpha(nextChar))
         charClass = LETTER;
      else if (isdigit(nextChar))
         charClass = DIGIT;
      else if (nextChar == '\n')
         charClass = NEWLINE;
      else 
         charClass = OPERATOR;
   } 
   else if((nextChar = getc(stdin)) != EOF) {
      buffer += nextChar;
      max_pos++;
      cur_pos++;
      if (isalpha(nextChar)){
         charClass = LETTER;
      }
      else if (isdigit(nextChar)){
         charClass = DIGIT;
      }
      else if (nextChar == '\n')
         charClass = NEWLINE;
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
   while (isspace(nextChar) && nextChar != '\n')
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
                   //check to see if the word is dump or quit
                   if(strcmp(lexeme,"quit")==0){
                      nextToken = QUIT;
                   }
                   else if(strcmp(lexeme,"dump")==0){
                      nextToken = DUMP;
                   }
                   else if(strcmp(lexeme,"if")==0){
                      nextToken = IF;
                   }
                   else if(strcmp(lexeme,"then")==0){
                      nextToken = THEN;
                   }
                   else if(strcmp(lexeme,"fi")==0){
                      nextToken = FI;
                   }
                   else if(strcmp(lexeme,"else")==0){
                      nextToken = ELSE;
                   }
                   else if(strcmp(lexeme,"while")==0){
                      nextToken = WHILE;
                   }
                   else if(strcmp(lexeme,"do")==0){
                      nextToken = DO;
                   }
                   else if(strcmp(lexeme,"done")==0){
                      nextToken = DONE;
                   }
                   else if(strcmp(lexeme,"print")==0){
                      nextToken = PRINT;
                   }
                   //lookup the variable in the symbol table
                   //and place the value into number
                   else{
                      nextToken = IDENT;
                      s->insert(lexeme);
                   }
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

      /*new line to end a stmt*/
      case NEWLINE:
                  nextToken = NEWLINE;
                  lexeme[0] = 'E';
                  lexeme[1] = 'N';
                  lexeme[2] = 'D';
                  lexeme[3] = 'L';
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


  //printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);

   return nextToken;
} 

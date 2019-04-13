#include "general.h"

/* stmt
 *
 * <stmt> → {id = } <expr> | DUMP | QUIT
 */
void stmt() 
{
   int left;
   item * var_pos;

   if ( nextToken == DUMP ) {
   	s->dump();
   } else if ( nextToken == QUIT ) {
   	exit(1);
   //if the next token is not dump or quit, you need to check
   //for any of the possible ways an expr can begin
   } else if(nextToken == IDENT){
      var_pos = s->lookup(lexeme);
      lex();
      if(nextToken == ASSIGN_OP){
         lex();
         left = expr();
         var_pos->val = left;
      }else
         error("expected equals after Id");
   } else if(nextToken == IF){
      if(cond()){
         if(nextToken == THEN){
            lex();
            if(nextToken == NEWLINE){
               getChar();
               lex();
            }
            while(nextToken != FI){
               stmt();
               if(nextToken == NEWLINE){
                  getChar();
                  lex();
               }
            }
            lex();
         }else
            error("expected a then after a cond");
      }else{
         optionals();   
      }
   //this code block is to handle while loops,
   //the while can be on one line or it can be broken
   //into multi lines as long as the while <cond> do
   //is on the same line
   } else if(nextToken == WHILE){
      int cond_pos = cur_pos;
      int cond_class = charClass;
      char cond_char = nextChar;
      while(cond()){
         if(nextToken == DO){
            lex();
            if(nextToken == NEWLINE){
               getChar();
               lex();
            }
            //this while loop allows for a while 
            //to have multiple stmts in it.
            while(nextToken != DONE){
               stmt();
               if(nextToken == NEWLINE){
                  //if the next token is a new line then we need to
                  //lex to see if another stmt is next or a done is next
                  //without calling getChar() lex will still see '\n'
                  //as the nextChar and not update it.
                  getChar();
                  lex();
               }
            }
            //reset the buffer pos to before the cond.
            cur_pos = cond_pos;
            nextChar = cond_char;
            charClass = cond_class;
         }
      }
      //while(nextToken != DONE)
      //   lex();
      cur_pos = max_pos;
      lex();
   }else {
   	error("expected DUMP, QUIT, assignment, or expression");
   }
} /* End of function stmt_list */

/* This function handles either an else or fi
 * after the stmts in an if. If there is an else it will
 * handle several stmts in the else part before the fi
 * 
 */
void optionals()
{
  lex();
  //since the cond was false we need to take off all
  //the lines until we get to either a FI or ELSE
  while(nextToken != FI && nextToken != ELSE){
     lex();
     if(nextToken == NEWLINE){
        getChar();
     }
  }
  if(nextToken == ELSE){
     lex();
     //these next three lines handle the case where
     //else is on a line of it's own.
     if(nextToken == NEWLINE){
        getChar();
        lex();
     }
     //this loop handles a multi line else block
     while(nextToken != FI){
        stmt();
        if(nextToken == NEWLINE){
           getChar();
           lex();
        }
     }
     lex();
  }
  else{
     lex();
  } 
}

/* This is the function to handle
 * a cond in a if or while statement
 * it can only a handle <cond> <rel_op> <cond>
 * rel_op -> < | > | <= | >= | == | !=
 */
bool cond()
{
   lex();
   int left,right;
   left = expr();
   
   switch(nextToken)
   {
      case ASSIGN_OP:
                     lex();
                     if(nextToken == ASSIGN_OP){
                        lex();
                        right = expr();
                        return (left == right);
                     }else 
                        error("expected equals after equals");   
                   break;
      case BANG_OP:
                   lex();
                   if(nextToken == ASSIGN_OP){
                      lex();
                      right = expr();
                      return (left != right);
                   }else
                       error("expected equals after bang");
                   break;
      case LESS_OP:
                   lex();
                   if(nextToken == ASSIGN_OP){
                      lex();
                      right = expr();
                      return (left <= right);
                   }else if(nextToken == INT_LIT || nextToken == IDENT ||
                            nextToken == SUB_OP || nextToken == LEFT_PAREN){
                      right = expr();
                      return (left < right);
                   }else
                      error("expected something different");
                   break;
      case MORE_OP:
                   lex();
                   if(nextToken == ASSIGN_OP){
                      lex();
                      right = expr();
                      return (left >= right);
                   }else if(nextToken == INT_LIT || nextToken == IDENT ||
                            nextToken == SUB_OP || nextToken == LEFT_PAREN){
                      right = expr();
                      return (left > right);
                   }else
                      error("expected something different");
                   break;
       default:
                    error("expected something different");
                    break;
   }
      
}

/* expr
   Parses strings in the language generated by the rule:
   <expr> -> <term> {(+ | -) <term>}
 */
int expr() 
{
   int right,left,operation;

   /* Parse the first term */
   left = term();

   /* As long as the next token is + or -, get
      the next token and parse the next term */
   while (nextToken == ADD_OP || nextToken == SUB_OP) {
      operation = nextToken;
      lex();
      right=term();
      if(operation == ADD_OP)
         left+=right;
      else if(operation == SUB_OP)
         left-=right;
      else
         error("expected - or +");
   }

   return left;
} /* End of function expr */


/* term
 *  Parses strings in the language generated by the rule:
 *  <term> -> <sfactor> {(* | /) <sfactor>)
 */
int term() 
{
   /* Parse the first factor */
   int right,left,operation;

   left=sfactor();
   /* As long as the next token is * or /, get the
      next token and parse the next factor */
   while (nextToken == MULT_OP || nextToken == DIV_OP || nextToken == MOD_OP) {
      operation = nextToken;
      lex();
      right=sfactor();
      if(operation == MULT_OP){
         left*=right;
      }else if(operation == DIV_OP){
         if(right !=0){
            left/=right;
         } else
            error("division by zero");
      }else if(operation == MOD_OP){
         left%=right;
      }
      else
         error("expected * or /");
   }

   return left;
} /* End of function term */

/* sfactor
 * Parses strings in the language generated by the rule:
 * 
 *   <sfactor> -> - <efactor> | <efactor>
 *
 */
int sfactor() 
{
   int val;
   /* Determine which RHS */
   if ( nextToken == SUB_OP ) {
      lex();
      val = efactor();
      val = -1 * val;
   } else {
      val = efactor();
   }
   return val;
}/* End of function efactor */

/* efactor
 * Parses strings in the language generated by the rule:
 * 
 *  <efactor> → {<pfactor> ^} <pfactor>
 *
 */
int efactor() 
{
   int left, right, operation;
   /* Determine which RHS */
   left = pfactor();
   while( nextToken == EXP_OP ) {
      lex();
      right = pfactor();
      left = pow(left,right);
   }

   return left;
}/* End of function efactor */

/* pfactor
 * Parses strings in the language generated by the rule:
 * 
 *   <pfactor> -> id | int_constant | ( <expr> )
 *
 */
int pfactor() 
{
   int val;
   item * var_pos;

   /* Determine which RHS */
   //if the next token is an ID we need to check to see if
   //the token following that is an assign op
   if (nextToken == IDENT){
      var_pos = s->lookup(lexeme);
      val = var_pos->val;
      lex();
    }
    //if the token following a number is an assignment then
    //we should try to stop execution of the statement.
    //however if the statement is something like a=b+3=10
    //then a=b+3 will still be executed normally.
    else if(nextToken == INT_LIT){
         val = number;
         lex();
         if(nextToken == ASSIGN_OP){
            error("next expecting assign op after int literal");
            while(nextToken != NEWLINE){
               lex();
            }
         }
   }
   /* If the RHS is ( <expr> ), call lex to pass over the left 
      parenthesis, call expr and check for the right parenthesis */
   else if (nextToken == LEFT_PAREN) {
         lex();
         val = expr();
         if (nextToken == RIGHT_PAREN){
            lex();
         }
         else
            error("left without right paren");
   } else {
   /* It was not an id, an integer literal, or a left
       parenthesis */
       error("expected an id, integer, or a left paren");
   } /* End of else */

   return val;
}/* End of function pfactor */

void error(const char *message)
{
   printf("Error: %s\n",message);
}

/* 
  Calculator.cpp - A simple arithmetic interpreter.
  Names: Alec Cohan, Matthew Olker, Issac Shore
  Class: CSC-4510
  
  The program demonstrates two main components of
  an interpreter/compiler.
  1) A lexical analyzer to scan the input for
     LETTERs, DIGITs, or OPERATORs
     
     An IDENT consist of a LETTER followed by
     a LETTER or DIGIT (max 99 characters)
     AN INT_LIT consists of a sequence of DIGITs
     (max 99 digits).     
   
     An OPERATOR =, +, -, *, /, (, )
     lexeme[] holds the item read from source
     nextToken holds the type
  2) A recursive descent parser
     The Grammar - EBNF description
     <expr> → <term> {(+ | -) <term>}
     <term> → <factor> {(* | /) <factor>}
     <factor> → id | int_constant | ( <expr>  ) 
     NOTE: the recusive descent starts at <expr>     
 */

#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;

//header guards
#ifndef GENERAL_H
#define GENERAL_H

/* Global declarations */
/* Variables */
extern char lexeme [100];  
extern char nextChar;     
extern int lexLen;
//FILE *in_fp, *fopen();

/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();

int expr();
int term();
int factor();
void error(const char *);
  
/* Character classes */
extern int charClass;
#define LETTER 0
#define DIGIT 1
#define OPERATOR 99

/* Token codes */
extern int token;
extern int nextToken;
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

//header guards
#endif

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
     <stmt> → id = <expr> | <expr> | DUMP | QUIT
     <expr> → <term> {(+ | -) <term>}
     <term> → <sfactor> {(* | /) <sfactor>}
     <sfactor> → - <efactor>
     <efactor> → {<efactor> ^} <efactor>
     <pfactor> → id |id = <expr> | int_constant | ( <expr>  ) 
     NOTE: the recusive descent starts at <expr>     
 */

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctype.h>
#include<cmath>
#include<cstring>

#include "symbol.h"
using namespace std;

//header guards
#ifndef GENERAL_H
#define GENERAL_H

/* Global declarations */
/* Variables */
extern char lexeme [100];  
extern char nextChar;     
extern int lexLen;
extern int number;
extern char result[500];
//symbol table stuff
extern symbol * s; 
//FILE *in_fp, *fopen();

/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();

//parser functions
void stmt();
int expr();
int term();
int sfactor();
int efactor();
int pfactor();
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
#define EXP_OP 27
#define NEWLINE 28
#define DUMP 29
#define QUIT 30

//header guards
#endif

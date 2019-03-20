LEX=flex
YACC=bison
CC=g++
bc:	calc.tab.o lex.yy.o symbol.o
	$(CC) -o bc calc.tab.o lex.yy.o symbol.o -lfl -lm

lex.yy.o:	lex.yy.cc calc.tab.hpp

lex.yy.o calc.tab.o:	general.h

calc.tab.cpp calc.tab.hpp:	calc.ypp
	$(YACC) -d calc.ypp

lex.yy.cc:	calc.l
	$(LEX) -+ calc.l

symbol.o:	symbol.cpp symbol.h
	$(CC) -c symbol.cpp

clean:
	rm bc lex.yy.* calc.tab.* symbol.o

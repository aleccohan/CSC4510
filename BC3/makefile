CC=g++

parser: lex.o parser.o symbol.o
	$(CC) -o calc lex.o parser.o symbol.o

lex.o: lex.cpp general.h
	$(CC) -c lex.cpp

parser.o: parser.cpp general.h
	$(CC) -c parser.cpp

symbol.o: symbol.cpp symbol.h
	$(CC) -c symbol.cpp

clean:
	rm calc lex.o parser.o symbol.o 

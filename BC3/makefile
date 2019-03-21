CC=g++

parser: lex.o parser.o
	$(CC) -o calc lex.o parser.o
  
lex.o: lex.cpp general.h
	$(CC) -c lex.cpp

parser.o: parser.cpp general.h
	$(CC) -c parser.cpp

clean:
	rm calc lex.o  parser.o 

# BC2
> Authors: Alec Cohan, Isaac Shore, Matthew Olker 
>
> Date: 2/26/2019
> 
> Class: CSC4510
>
> Source: molker/csc4510/BC_v2/

The BC is an executable file created through a lexx and yacc compiler that is able to follow a hard coded in grammar. The grammar should be able to execute basic math equations. 

## Compiling BC2
### If you haven't compiled it yet:
Use the command "make" with the provided make file and the executable named "bc" should be created in the same directory as where make was run.
```bash
make
```

#If you have compiled it already:
Before running "make" again, use the command "make clean" to remove old object files and files that need to be recreated. 
```bash
make clean
```

## How to run BC2
BC is a executable file used to do basic math, so the input that will be needed is basic math. This can either be done from the command line or by using I/O redirection with an input file. 
```bash
cat input.txt
5 + 6
bc < input.txt
=11
```
or 
```bash
bc
5 + 6
=11
```

## Upgrades from BC1
### More Operators
BC1 only allowed for addition and multiplication, while BC2 allows for subtraction, division, modular dvision, and exponents. 

### Symbol Table
BC2 implements a symbol table which is capable of storing any variable/ID's needed in each run of the program. The variable names are hashed before being inserted into the table to make looking them up later simpler. Now, when a new variable is defined, a message will pop up telling the user it has been added to the table. 
```bash
a = 3
Called insert with a
=3
b = 12
Called insert with b
=12
```
This also now allows for the "dump" command, which will print out every variable being stored in the table and their respective value. 
```bash
dump
 3 a
 12 b
```

### New Commands
1. dump
	* As stated and shown above, dump prints out the contents of the symbol table. 
2. quit
	* Quit exits the current run of bc. 

## Syntax
### Operators
Currently, even though minus is in the code, it has not been implemented into the grammar. 
* Plus +
* Subtract - 
* Mulitply *
* Divide /
* Modulo %
* Exponent ^ 
* Equal =
	* Input can include assignment statements for creating variables

### Other Symbols 
* Parenthesis ( )
	* Input can include expressions using parentheis to better control order of operations
* Unary Minus (Negative) - 

### Noteable Syntax
* Make sure your input always ends with a NEWLINE.
	* The way the grammar is set up, every statement should end with a NEWLINE, meaning an error will be printed out if a statement ends without a NEWLINE
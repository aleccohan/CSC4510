# BC2
> Authors: Alec Cohan, Isaac Shore, Matthew Olker 
> Date: 2/26/2019 
> Class: CSC4510
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
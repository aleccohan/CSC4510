# BC4
> Authors: Alec Cohan, Isaac Shore, Matthew Olker 
>
> Date: 4/9/2019
> 
> Class: CSC4510
>
> Source: molker/csc4510/BC4/

The BC is an executable file created through a lexx and yacc compiler that is able to follow a hard coded in grammar. The grammar should be able to execute basic math equations. This version is no longer using lexx and yacc, and is instead done only in C++ by adding math functionality to a lex style interpreter. 

## Compiling BC4
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

## How to run BC4
BC is a executable file used to do basic math, so the input that will be needed is basic math. This can either be done from the command line or by using I/O redirection with an input file. 
```bash
cat input.txt
5 + 6
calc < input.txt
=11
```
or 
```bash
calc
5 + 6
=11
```

## Changes From Other Versions
### Solely C++
Past versions of our BC has included using lexx, yacc, or bison to create most of the functionality centered around a grammar we programmed in. This version utilizes only C++ to do all of the analysis and math on it's own, following a similar method. 

### Different Method
BC and BC2 were both good examples of ways to accomplish the same goal while using a bottom-up parser. BC3 differs from both by solving the same problem using a recursive descept top-down parser. What this means is the program will recursively implement useable non-terminals of the grammar until it gets to the desired answer, and going about it from the top-to-bottom of a parse tree.

### New Statements
The goal with BC up until BC4 has mainly been to make a functional calculator. BC4 is designed to go a step further by adding statements that are closer to a programming language than a caluclator, such as: if statements, if-else statements, while statements, print statements, and comments. 

To use a print statement, write "print" and then a variable already in the symbol table.

### Multi-Line Statements
It is rare that someone will want to make an if or while statement that only has one line inside for what to happen, so we made sure to include the ability to make it functional on multiple lines. The proper setup is as follows: 
```bash
while <conditional> do
	statement
	statement
	...
	statement done
```
or
```bash
if <conditional> then
	statement
	statement
	...
	statement fi
```
if statements also work with else statements. Those look like:
```bash
if <conditional> then
	statement
else
	statement fi
```
*** all above spacing not required ***

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
* Comments #
	* Comments are done by putting a "#" and then any text on that line

### Noteable Syntax
* Make sure your input always ends with a NEWLINE.
	* The way the grammar is set up, every statement should end with a NEWLINE, meaning an error will be printed out if a statement ends without a NEWLINE
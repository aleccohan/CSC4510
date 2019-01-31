#!/bin/bash
# Compile.sh
# Name: Matthew Olker and Alec Cohan
# Date: 1-22-2019
# Class: CSC-4510
# Location: molker/csc4510/P1/Script
# This script compiles the source code so it can be tested. 
 
#Parameters: 
#	0: Compile.sh
#	1: Language
#	2: source File Name

# if the second argument is not an actual file then return error 
if [ ! -e $2 ]; then
	echo "Compile.sh: File $2 does not exist"
	exit 1
fi

# depending on the language entered the case will run the coresponding compiler
case "$1" in 
	ada)
		gnatmake -q $2
		;;
	c++) g++ -Wall $2
		;;
	*) echo "Compile.sh: Make sure you wrote the language name correctly!"
		;;
esac

echo "Compiling Successful"

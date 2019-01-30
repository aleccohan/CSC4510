#!/bin/bash
#Be in the directory with the correct file 
#Parameters: 
#	0: Compile.sh
#	1: Language
#	2: source File Name

if [ ! -e $2 ]; then
	echo "File does not exist"
	exit 1
fi

case "$1" in 
	ada)
		gnatmake -q $2
		;;
	fortran)
		gfortran $2
		;;
	java) javac $2
		;;
	c++) g++ -Wall $2
		;;
	*) echo Make sure you wrote the language name correctly!
		;;
esac
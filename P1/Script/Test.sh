#!/bin/bash
#Be in the directory with the correct executable 
#Parameters: 
#	0: Test.sh
#	1: Language
#	2: Executable file name

#Test Answers function
#Parameters:
#	0: Test.sh
#	1: Executable file name
testAnswers()
{
	for file in `ls ../TestFiles/`
	do
		if test -L $file
		then
			echo $file is a link
		elif [[ -d $file ]]; then
			echo $file is a directory
		else
			$1 < "../TestFiles/$file" > "../OutFiles/$file"
		fi

	done
}

if [ ! -x $2 ]; then
	echo "Executable does not exist"
	exit 1

case "$1" in 
	ada)
		testAnswers $2
		;;
	fortran) testAnswers $2
		;;
	java) testAnswers "java $2"
		;;
	c++) testAnswers $2
		;;
	*) echo Make sure you wrote the language name correctly!
		;;
esac

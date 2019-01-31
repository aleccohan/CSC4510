#!/bin/bash
# Test.sh
# Name: Matthew Olker and Alec Cohan
# Date: 1-22-2019
# Class: CSC-4510
# Location: molker/csc4510/P1/Script
# This script is used to test the compiled code and execute it against the
# files in the TestFiles directory. The output is then put into a directory
# called OutFiles.

#Test Answers function
#Parameters:
#	0: Test.sh
#	1: Executable file name
testAnswers()
{
	# If the Directory TestFiles doesn't exist then exit script
	if [ ! -d "../TestFiles/" ]; then
		echo "Test.sh: TestFiles directory doesn't exist or isn't in the right place"
		exit 1
	fi
	
	# If the Directory OutFiles doesn't exist then create the Directory
	if [ ! -d "../OutFiles/" ]; then
		mkdir "../OutFiles/"
		echo "Test.sh: OutFiles directory made"
	fi
	
	# for each file in TestFiles test if it is a link / directory
	# if neither then create a file in OutFiles to hold output data and run code
	for file in `ls ../TestFiles/`
	do
		if test -L $file
		then
			echo "Test.sh: $file is a link"
		elif [[ -d $file ]]; then
			echo "Test.sh: $file is a directory"
		else
			if [ ! -a "../OutFiles/$file" ]; then
				touch "../OutFiles/$file"
			fi
			$1 < "../TestFiles/$file" > "../OutFiles/$file"
		fi

	done
}

#Parameters: 
#	0: Test.sh
#	1: Language
#	2: Executable file name
if [ ! -x $2 ]; then
	echo "Test.sh: Executable does not exist"
	exit 3
fi

# depending on the 1st argument run the code through testAnswers and then run it
case "$1" in 
	ada)
		testAnswers a.out
		;;
	c++) testAnswers a.out
		;;
	*) echo "Test.sh: Make sure you wrote the language name correctly!"
		;;
esac

echo "Testing Successful"

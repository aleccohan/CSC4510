#!/bin/bash
#Compare the output of testing the file with the known answers
for file in `ls ../OutFiles/`
do
	if test -L $file
	then
		echo "$file is a link"
	elif [[ -d $file ]]; then
		echo "$file is a directory"
	else
		error="$(diff "../OutFiles/$file" "../Correct/$file")"
		if [ ! -z "$error" ]
		then
			echo "$file Failed"
		fi
	fi
done

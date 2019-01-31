# CSC-4510 Program 1
* Authors: Matthew Olker and Alec Cohan
* Date: 1-22-2019
* Class: CSC4510
* Source: molker/csc4510/P1/

## How to Run
* To run this correctly, make sure to run the scripts from the Source directory. This makes sure that any of the executable files or .ali files from ada are kept in the Source directory and don't start flooding the Script directory. 
* The language options for this version of the scripts includes: 
	* ADA
	* C++

### Compile.sh
* After making sure to be in the Source directory, to use Compile.sh format your script call like this: 
```bash
../Script/Compile.sh <language> <File to Compile>
```
* If it runs correctly, you should expect to see the message: "Compiling Successful"
* If the file given doesn't exist or the 

### Test.sh
* To use Test.sh, format your script call like this: 
```bash
../Script/Test.sh <language>
```
* If it runs correctly, you should expect to see the message: "Testing Successful"
* If the user doesn't already have a directory labeled OutFiles, for the output, the script will make it and print out the message: "Test.sh: OutFiles directory made"

### Compare.sh
* To use Compare.sh, format your script call like this: 
```bash
../Script/Compare.sh
```
* There is no parameter for this one because it only includes checking the Correct directory against the OutFiles directory created by Test.sh
* If it runs correctly, you should expect to see the message: "Comparing Successful"
* If it runs incorrectly, or if you are testing a program that will specifically give different output than what is in the Correct direcotry, you should expect to see the message: "Comparing Unsuccesful: Some inconsitent output from Corerct."

### CTC.sh
* CTC stands for "Compile, Test, Compare"
* To use CTC.sh, format your script call like this; 
```bash
../CTC.sh <language> <File to Compile>
```
* This will make sure to run all the above mentioned scripts, so if it runs correctly you should expect to see all three success statements mentioned above
```bash
Compiling Successful
Testing Successful
Comparing Successful
```
* It is also possible you'll see the message included for creating the OutFiles directory which will then make the output read
```bash
Compiling Successful
Test.sh: OutFiles directory made
Testing Successful
Comparing Successful
```

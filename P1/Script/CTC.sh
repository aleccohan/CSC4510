#!/bin/bash
# CTC.sh
# Name: Matthew Olker and Alec Cohan
# Date: 1-22-2019
# Class: CSC-4510
# Location: molker/csc4510/P1/Script
# This script is used to call the Compile script, Test script, and Compare script
# in that order to complete the whole process of using the programs made correctly

# Parameters: 
# 	0: CTC.sh
#  1: language 
#	2: File to Compile

../Script/Compile.sh $1 $2
../Script/Test.sh $1 
../Script/Compare.sh
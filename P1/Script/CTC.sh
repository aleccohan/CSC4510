#!/bin/bash

../Script/Compile.sh $1 $2
../Script/Test.sh $1 $3
../Script/Compare.sh
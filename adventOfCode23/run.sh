#!/bin/bash

file=$1
g++ $file.cpp -o $file
./$file < input.txt

rm $file

# print all executables
# find . -maxdepth 1 -type f -executable

# delete all executables
# find . -maxdepth 1 -type f -executable -exec rm {} +
#!/bin/bash

file=$1
g++ $file.cpp
./a.out < input.txt
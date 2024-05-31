#!/bin/sh
make clean
make all
./parser -d < input.txt > output.txt
exit 0


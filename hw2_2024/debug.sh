#!/bin/sh
make clean
make all

./parser -d < problem.txt  > output.txt
exit 0


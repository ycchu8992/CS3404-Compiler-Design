#!/bin/sh
make clean
make all
./parser -d < input.txt
exit 0


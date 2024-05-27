#!/bin/sh
make clean
make all
./parser < input.txt
exit 0


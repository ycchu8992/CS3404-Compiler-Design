#!/bin/sh
make clean
make all

./parser -d < a.txt  > output.txt
exit 0


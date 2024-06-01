#!/bin/sh
make clean
make all

./parser -d < test_case.txt  > output.txt
exit 0


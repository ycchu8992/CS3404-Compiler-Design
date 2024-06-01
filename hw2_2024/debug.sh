#!/bin/sh
make clean
make all

./parser -d < ./test_case/test_case_$1.c
make clean
exit 0


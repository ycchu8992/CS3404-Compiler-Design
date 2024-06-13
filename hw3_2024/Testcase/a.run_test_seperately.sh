#!/bin/bash
make clean
make all

./parser < ./Testcase/ArithmeticExpression/0.c  > result.c

exit 0

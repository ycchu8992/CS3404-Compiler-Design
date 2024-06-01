#!/bin/sh
make clean
make all

parser_name=golden_parser_static
test_case=problem.txt
./${parser_name} < ${test_case} > sol.txt
./parser < ${test_case} > out.txt
diff out.txt sol.txt > diff.txt
rm -f out.txt sol.txt
exit 0
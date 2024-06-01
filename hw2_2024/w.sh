#!/bin/sh
make clean
make all

parser_name=golden_parser_static
test_case=a.txt
./${parser_name} < ${test_case} > sol.txt
./parser < ${test_case} > out.txt
diff out.txt sol.txt > diff.txt
exit 0
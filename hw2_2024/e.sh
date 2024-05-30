#!/bin/sh
make clean
make all

parser_name=golden_parser_static
./${parser_name} < input.txt > sol.txt
./parser < input.txt > out.txt
diff out.txt sol.txt > diff.txt
exit 0
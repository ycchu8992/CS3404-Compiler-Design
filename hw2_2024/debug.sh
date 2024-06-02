#!/bin/sh
make clean
make all
./golden_parser_static < test.c > sol.txt
./parser < test.c > out.txt
diff out.txt sol.txt > diff.c
make clean
rm -f out.txt sol.txt
exit 0


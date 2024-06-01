#!/bin/sh
make clean
make all
./golden_parser_static < test.c > sol.txt
./parser -d < test.c > out.txt
diff out.txt sol.txt > diff.c
make clean
exit 0


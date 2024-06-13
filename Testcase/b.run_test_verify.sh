#!/bin/sh
make clean
make all


PATH=./parser

./golden_parser_static < ./test_case/testcases_in_one_file.c > sol.txt
${PATH} < ./test_case/testcases_in_one_file.c > out.txt
diff out.txt sol.txt > comp.txt
rm -f out.txt sol.txt
if ! test -s comp.txt
then
    echo "Correct"!
    rm -f comp.txt
fi
exit 0
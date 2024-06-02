#!/bin/bash
make clean
make all

PATH_gp=./golden_parser_static

test_case=( array_decl.c  cast.c  func_decl.c  loop.c  scalar_init.c  test_case.c array_init.c  expr.c  func_def.c   scalar_decl.c  scanner_test.c string.c overflow.c)
max=13
for (( i=0; i < $max; ++i))
do
    echo -e ${test_case[$i]}":"
    ${PATH_gp} < ./test_case/${test_case[$i]} > sol.txt
    ./parser < ./test_case/${test_case[$i]} > out.txt
    diff out.txt sol.txt > ./test_result/${test_case[$i]}
    if ! test -s ./test_result/${test_case[$i]}
    then
        rm -f ./test_result/${test_case[$i]}
    fi
done

rm -f lex.yy.c y.tab.c y.tab.h scanner parser out.txt sol.txt

exit 0
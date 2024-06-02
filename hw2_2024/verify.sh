#!/bin/sh
make clean
make all

int=2

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=4

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=6

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=7

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=8

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=9

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=10

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=11

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=12

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=15

./golden_parser_static < ./test_case/test_case_${int}.c > sol.txt
./parser < ./test_case/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi



./golden_parser_static < ./test_case/test_case_a.c > sol.txt
./parser < ./test_case/test_case_a.c > out.txt
diff out.txt sol.txt > ./test_result/diff_a.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_a.c
then
    rm -f ./test_result/diff_a.c
fi

int=b

./golden_parser_static < ./test_case/test_case_b.c > sol.txt
./parser < ./test_case/test_case_b.c > out.txt
diff out.txt sol.txt > ./test_result/diff_b.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_b.c
then
    rm -f ./test_result/diff_b.c
fi



./golden_parser_static < ./test_case/test_case_d.c > sol.txt
./parser < ./test_case/test_case_d.c > out.txt
diff out.txt sol.txt > ./test_result/diff_d.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_d.c
then
    rm -f ./test_result/diff_d.c
fi


./golden_parser_static < ./test_case/test_case_c.c > sol.txt
./parser < ./test_case/test_case_c.c > out.txt
diff out.txt sol.txt > ./test_result/diff_c.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_c.c
then
    rm -f ./test_result/diff_c.c
fi

rm -f lex.yy.c y.tab.c y.tab.h scanner parser

exit 0
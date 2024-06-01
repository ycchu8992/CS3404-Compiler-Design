#!/bin/sh
make clean
make all

echo test_case_a.c:
./golden_parser_static < ./test_case/test_case_a.c > sol.txt
./parser < ./test_case/test_case_a.c > out.txt
diff out.txt sol.txt > ./test_result/diff_a.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_a.c
then
    rm -f ./test_result/diff_a.c
fi

int=b
echo test_case_b.c:
./golden_parser_static < ./test_case/test_case_b.c > sol.txt
./parser < ./test_case/test_case_b.c > out.txt
diff out.txt sol.txt > ./test_result/diff_b.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_b.c
then
    rm -f ./test_result/diff_b.c
fi

echo test_case_c.c:
./golden_parser_static < ./test_case/test_case_c.c > sol.txt
./parser < ./test_case/test_case_c.c > out.txt
diff out.txt sol.txt > ./test_result/diff_c.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_c.c
then
    rm -f ./test_result/diff_c.c
fi

echo test_case_d.c:
./golden_parser_static < ./test_case/test_case_d.c > sol.txt
./parser < ./test_case/test_case_d.c > out.txt
diff out.txt sol.txt > ./test_result/diff_d.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_d.c
then
    rm -f ./test_result/diff_d.c
fi

make clean

exit 0
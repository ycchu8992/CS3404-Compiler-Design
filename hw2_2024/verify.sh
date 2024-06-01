#!/bin/sh
make clean
make all

int=2
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=4
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=6
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=7
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=8
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=9
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=10
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=11
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=12
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi

int=15
echo test_case_${int}.c:
./golden_parser_static < ./test_case_part2/test_case_${int}.c > sol.txt
./parser < ./test_case_part2/test_case_${int}.c > out.txt
diff out.txt sol.txt > ./test_result/diff_${int}.c
rm -f out.txt sol.txt

if ! test -s ./test_result/diff_${int}.c
then
    rm -f ./test_result/diff_${int}.c
fi
make clean

exit 0
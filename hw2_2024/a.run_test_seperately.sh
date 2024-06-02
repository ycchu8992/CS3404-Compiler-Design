#!/bin/bash
make clean
make all

test_case=( array_decl.c  cast.c  func_decl.c  loop.c  scalar_init.c  my_test_case.c array_init.c  expr.c  func_def.c   scalar_decl.c  scanner_test.c string.c extra_test_case.c overflow.c)

for (( i=0; i < 14; ++i))
do
    
./golden_parser_static < ./test_case/${test_case[$i]} > sol.txt
./parser < ./test_case/${test_case[$i]} > out.txt
diff out.txt sol.txt > ./test_result/${test_case[$i]}
if ! test -s ./test_result/${test_case[$i]} 
then
rm -f ./test_result/${test_case[$i]}
else 
echo -e ${test_case[$i]}":"
fi
done

rm -f out.txt sol.txt

exit 0
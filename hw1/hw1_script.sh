#!/bin/bash
# Program:
#	User to debug the lex annalysis scanner.
# History:
# 2023/04/10    cd23p064@2023spring     First release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin:~/hw1
export PATH
$(make clean)
$(make all)
for FILE in 0 1 2 3
do
    $(./scanner < ./test_case/input_${FILE}.cpp > out)
    $(golden_scanner < ./test_case/input_${FILE}.cpp > sol) 
    $(diff sol out > ./test_result/output_${FILE}.cpp -s -y -W 200 --suppress-common-lines)
done
$(rm -f sol out)
exit 0
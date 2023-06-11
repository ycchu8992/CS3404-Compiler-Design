#!/bin/bash
# Program:
#	User to debug the lex annalysis scanner.
# History:
# 2023/04/10    cd23p064@2023spring     First release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin:~/hw2
export PATH
$(make clean)
$(flex scanner.l)
$(make all)
$(golden_parser  < ./test_case/stmt.txt > ./test_result/sol.txt) 

exit 0

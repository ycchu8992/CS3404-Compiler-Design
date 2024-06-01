#!/bin/sh

parser_name=golden_parser_static
test_case=a.txt
./${parser_name} < ${test_case} > output.txt
cat output.txt
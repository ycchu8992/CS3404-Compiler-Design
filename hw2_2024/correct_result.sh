#!/bin/sh

parser_name=golden_parser_static
test_case=problem.txt
./${parser_name} < ${test_case} > output.txt
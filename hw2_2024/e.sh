#!/bin/sh
flex scanner.l
gcc -o scanner lex.yy.c -lfl
exit 0
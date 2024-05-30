CC = gcc
CFLAG = -lfl
DFLAG = -DYYDEBUG

# Part 1: Compile the scanner.
RUNFIRST:=$(shell )

all: parser.y

.PHONY: parser.y
parser.y: lex.yy.c y.tab.c
	
	$(CC) -o parser lex.yy.c y.tab.c $(CFLAG) $(DFLAG)

y.tab.c:
	yacc -d parser.y

.PHONY: scanner.l
lex.yy.c: y.tab.c
	flex scanner.l

# Part 2: Clean up previous Compilation of the scanner.
clean:
	rm -f lex.yy.c y.tab.c y.tab.h scanner parser
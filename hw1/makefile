CC = gcc
CFLAG = -lfl

# Part 1: Compile the scanner.
RUNFIRST:=$(shell flex scanner.l)
all: scanner.l

.PHONY: scanner.l
scanner.l:
	$(CC) -o scanner lex.yy.c $(CFLAG)

.PHONY: lex.yy.c
lex.yy.c:
	$(CC) -o scanner lex.yy.c $(CFLAG)

# Part 2: Clean up previous Compilation of the scanner.
clean:
	rm -f lex.yy.c scanner

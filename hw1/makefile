CC = gcc
CFLAG = -lfl

# Part 1: Compile the scanner.
all: scanner.l

.PHONY: LEX
LEX:
	flex scanner.l

scanner.l: LEX
	$(CC) -o scanner lex.yy.c $(CFLAG)

.PHONY: lex.yy.c
lex.yy.c:
	$(CC) -o scanner lex.yy.c $(CFLAG)

# Part 2: Clean up previous Compilation of the scanner.
clean:
	rm -f lex.yy.c scanner

# Part 3: Run the scanner on the terminal.
.PHONY: run
run:
	./scanner

# Part 4: Run the scanner for debug or reset debug.
debug:
	./scanner < ../hw1_debug/testcase_basic > ../hw1_debug/out
	golden_scanner < ../hw1_debug/testcase_basic > ../hw1_debug/sol
	-diff ../hw1_debug/sol ../hw1_debug/out > error

.PHONY: erase
erase:
	rm -f ../hw1_debug/sol ../hw1_debug/out error

# Part 5: Fast Command.
.PHONY: c d r e a
c:clean
d:debug
r:run
e:erase
a: e c scanner.l d
	

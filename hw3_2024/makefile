CC = gcc
CFLAG = -lfl
DFLAG = -DYYDEBUG
TC_PATH=../Testcase/Jump
#Jump
# Part 1: Compile the scanner.
RUNFIRST:=$(shell )

all: parser.y

.PHONY: parser.y
parser.y: lex.yy.c y.tab.c
	
	$(CC) -o parser lex.yy.c y.tab.c reduce.h symtb.h $(CFLAG) 

y.tab.c:
	byacc -d parser.y

.PHONY: scanner.l
lex.yy.c: y.tab.c
	flex scanner.l
#ArithmeticExpression
.PHONY: run
run: 
	./parser < $(TC_PATH)/0.c  > result.c

.PHONY: print
print: 
	head stack.c

# Part 2: Clean up previous Compilation of the scanner.
clean:
	rm -f lex.yy.c y.tab.c y.tab.h scanner parser symbol.c result.c

.PHONY: q
q: 
	@rm -f lex.yy.c y.tab.c y.tab.h scanner parser symbol.c result.c
	@flex scanner.l
	@byacc -d parser.y
	@$(CC) -o parser lex.yy.c y.tab.c reduce.h symtb.h $(CFLAG)
	@rm -f lex.yy.c y.tab.c y.tab.h scanner
	@./parser < $(TC_PATH)/0.c  > result.c
	@rm -f parser result.c
	


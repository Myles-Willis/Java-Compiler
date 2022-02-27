CC = gcc
CFLAGS=-g -Wall

targets=lab2_2

all: j0

jzero_bison :
	bison -d j0gram.y
	bison j0gram.y

jzero_lexical : j0lex.l
	flex j0lex.l

lex.yy.o : lex.yy.c tree.h
	$(CC) $(CFLAGS) -c lex.yy.c

j0 : jzero_bison jzero_lexical jmain.c lex.yy.o defs.h tree.h token.h error.h
	$(CC) $(CFLAGS) -c jmain.c
	$(CC) $(CFLAGS) -c token.c
	$(CC) $(CFLAGS) -c error.c
	$(CC) $(CFLAGS) -c j0gram.tab.c
	$(CC) $(CFLAGS) jmain.o lex.yy.o j0gram.tab.o token.c error.c tree.c -o j0

clean :
	rm -f lex.yy.c
	rm -f j0gram.tab.h j0gram.tab.c
	rm -f *.o

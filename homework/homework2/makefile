CC = gcc
CFLAGS=-g -Wall

targets=lab2_2

all: j0

jzero_lexical : jzero.l
	flex jzero.l

j0 : jzero_lexical jmain.c
	$(CC) $(CFLAGS) -c jmain.c
	$(CC) $(CFLAGS) -c lex.yy.c
	$(CC) $(CFLAGS) -c token.c
	$(CC) $(CFLAGS) jmain.o lex.yy.o token.c -o j0

clean :
	rm -f lex.yy.c
	rm -f *.o

CC = gcc
CFLAGS=-g -Wall

targets=lab2_2

all: lab2_2

jzero_lexical : jzero.l
	flex jzero.l

lab2_2 : jzero_lexical jmain.c
	$(CC) $(CFLAGS) -c jmain.c
	$(CC) $(CFLAGS) -c lex.yy.c
	$(CC) $(CFLAGS) jmain.o lex.yy.o -o lab2_2

clean :
	rm -f lex.yy.c
	rm -f *.o

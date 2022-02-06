CC = gcc
CFLAGS=-g -Wall

targets=lab2_1

all: lab2_1

lab2_1_lexical : flex-wc.l
	flex flex-wc.l

lab2_1 : lab2_1_lexical main.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c lex.yy.c
	$(CC) $(CFLAGS) main.o lex.yy.o -o lab2_1

clean :
	rm -f lex.yy.c
	rm -f *.o

CC = gcc
CFLAGS=-g -Wall

targets=ns

all: ns

lab3_lexical : nnws.l
	flex nnws.l

lab3_bison :
	bison -d ns.y
	bison ns.y

ns : lab3_lexical lab3_bison main.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c lex.yy.c
	$(CC) $(CFLAGS) -c ns.tab.c
	$(CC) $(CFLAGS) main.o lex.yy.o ns.tab.o -o ns

clean :
	rm -f *.o
	rm -f lex.yy.c
	rm -f ns.tab.h ns.tab.c
	rm -f ns

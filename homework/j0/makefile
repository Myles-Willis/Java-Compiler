CC = gcc
CFLAGS=-g -Wall

targets=lab2_2

all: j0

j0gram.tab.c : j0gram.y
	bison -d j0gram.y
	bison j0gram.y

j0gram.tab.o : j0gram.tab.c
	$(CC) $(CFLAGS) -c j0gram.tab.c

lex.yy.c : j0lex.l
	flex j0lex.l

lex.yy.o : lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

jmain.o : defs.h tree.h error.h symboltable.h jmain.c
	$(CC) $(CFLAGS) -c jmain.c

tac.o : tac.h tac.c
	$(CC) $(CFLAGS) -c tac.c

intermediate.o : intermediate.h intermediate.c
	$(CC) $(CFLAGS) -c intermediate.c

token.o : token.h token.c
	$(CC) $(CFLAGS) -c token.c

tree.o : tree.h tree.c
	$(CC) $(CFLAGS) -c tree.c

error.o : error.h error.c
	$(CC) $(CFLAGS) -c error.c

symboltable.o : symboltable.h symboltable.c
	$(CC) $(CFLAGS) -c symboltable.c

type.o : type.h type.c
	$(CC) $(CFLAGS) -c type.c

j0 : j0gram.tab.o lex.yy.o jmain.o type.o lex.yy.o token.o tree.o error.o \
j0gram.tab.o symboltable.o intermediate.o tac.o

	$(CC) $(CFLAGS) jmain.o lex.yy.o token.o tree.o error.o j0gram.tab.o \
	symboltable.o type.o intermediate.o tac.o -o j0

clean :
	rm -f lex.yy.c
	rm -f j0gram.tab.h j0gram.tab.c
	rm -f *.o
	rm -f .DS_Store
	rm -f j0

all: lab1_1 lab1_2 lab1_3 lab1_4

lab1_1: lab1_1.c
	gcc -o lab1_1 lab1_1.c

lab1_2: lab1_2.c
	gcc -o lab1_2 lab1_2.c

lab1_3: lab1_3.o yylex.o
	gcc -o lab1_3 lab1_3.o yylex.o

lab1_3.o: lab1_3.c
	gcc -c lab1_3.c

lab1_4.o: lab1_4.c
	gcc -c lab1_4.c

lab1_4: lab1_4.o yylex_category.o
	gcc -o lab1_4 lab1_4.o yylex_category.o

yylex.o: yylex.c
	gcc -c yylex.c

yylex_category.o: yylex_category.c
	gcc -c yylex_category.c

zip:
	rm ../lab1_ans.zip
	zip ../lab1_ans.zip *

clean:
	rm *.o lab1_1 lab1_2 lab1_3 lab1_4
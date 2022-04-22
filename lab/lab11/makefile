tac: main.o tac.o
	gcc main.o tac.o -o tac

main.o: main.c tac.h
	gcc -c main.c

tac.o: tac.c tac.h
	gcc -c tac.c

clean:
	rm *.o

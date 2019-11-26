all: cgol

cgol: cgol.o
	gcc -ansi -Wall -o cgol cgol.o

checkAlive: checkAlive.c
	gcc -ansi -Wall -c checkAlive.c

checkEqual: checkEqual.c
	gcc -ansi -Wall -c checkEqual.c

printGrid: printGrid.c
	gcc -ansi -Wall -c printGrid.c

clean:
	rm *.o



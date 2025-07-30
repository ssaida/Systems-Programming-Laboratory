program: prog.o calc.o
	gcc -ansi -pedantic -g -Wall prog.o calc.o -o program -lm
prog.o: prog.c data.h
	gcc -c -ansi -pedantic -g -Wall prog.c -o prog.o
calc.o: calc.c data.h
	gcc -c -ansi -pedantic -g -Wall calc.c -o calc.o -lm

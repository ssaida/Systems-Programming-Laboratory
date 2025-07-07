mycalc: prog.o calc.o
	gcc -ansi -g -Wall prog.o calc.o -o mycalc -lm
prog.o: prog.c data.h
	gcc -c -ansi -Wall prog.c -o prog.o
calc.o: calc.c data.h
	gcc -c -ansi -Wall calc.c -o calc.o -lm  

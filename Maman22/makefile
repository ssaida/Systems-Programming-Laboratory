mainmat: mainmat.o mymat.o
	gcc -g -ansi -pedantic -Wall mainmat.o -o mainmat
mainmat.o: mainmat.c mymat.h
	gcc -c -ansi -Wall -pedantic mainmat.c -o mainmat.o
mymat.o: mymat.c mymat.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o

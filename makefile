all: count histogram frequencies
count: count.c
	gcc -ansi -pedantic -g -Wall count.c -o count
histogram: histogram.c
	gcc -ansi -pedantic -g -Wall histogram.c -o histogram
frequencies: frequencies.c
	gcc -ansi -pedantic -g -Wall frequencies.c -o frequencies

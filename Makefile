all: PQ worst best abb main
	gcc -o trab2 PQ.o worst.o best.o abb.o main.o

PQ:
	gcc -c worstFit/PQ.c

worst:
	gcc -c worstFit/worst.c

best:
	gcc -c bestFit/best.c

abb:
	gcc -c bestFit/abb.c

main:
	gcc -c main.c

clean:
	rm -f *.o *.gch

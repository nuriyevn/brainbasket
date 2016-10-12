all: task1 hello sum

task1: task1.c hello.c hello.h sum.c sum.h
	gcc -c task1.c 
	gcc -c hello.c
	gcc -c sum.c
	gcc task1.o hello.o sum.o -o task1
	
clean:
	rm -f *.o
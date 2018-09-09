pointer.o: pointer.c
	gcc -c pointer.c -o pointer.o

all: pointer.o
	gcc -o pointer pointer.o
	./pointer

clean:
	rm -rf *.o
	rm -rf pointer

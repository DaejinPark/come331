struct.o: struct.c
	gcc -c struct.c -o struct.o

all: struct.o
	gcc -o struct struct.o
	./struct

clean:
	rm -rf *.o
	rm -rf struct

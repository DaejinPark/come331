help:
	@echo "make all"
	@echo "make clean"

increment.o: increment.c increment.h
	gcc -o increment.o 	-c increment.c
	
foo.o: foo.c
	gcc -o foo.o 		-c foo.c
	
all: foo.o increment.o
	gcc -o foo		foo.o increment.o
	./foo

clean:
	rm -rf *.o
	rm -rf foo

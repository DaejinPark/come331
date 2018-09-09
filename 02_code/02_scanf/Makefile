help:
	@echo "make all"
	@echo "make clean"

scanf.o: scanf.c
	gcc -o scanf.o 		-c scanf.c
	
all: scanf.o 
	gcc -o scanf scanf.o 
	./scanf

clean:
	rm -rf *.o
	rm -rf scanf

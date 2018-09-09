#include <stdio.h>

int main() {
	int data[10] = {10,20,30,40,50,60,70,80,90,100};

	int i;
	for(i=0; i<10; i++) {
		printf("data[%d] : %d\n", i, data[i]);
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	//int data[10] = {10,20,30,40,50,60,70,80,90,100};
	int* data;

	int s;
	printf("Enter array size: ");
	scanf("%d", &s);

	if(s > 100) {
		printf("size is too large\n");
		return -1;
	} 

	data = (int*)malloc(sizeof(int)*s);
	int i;
	for(i=0; i<s; i++) {
		printf("Enter data[%d]: ", i);
		scanf("%d", &data[i]);
	}


	printf("Entire data of data[]\n");
	for(i=0; i<s; i++) {
		printf("data[%d] : %d\n", i, data[i]);
	}
	
	return 0;
}

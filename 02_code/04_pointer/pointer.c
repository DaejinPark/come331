#include <stdio.h>

int main() {
	int a, b;
	a = 100;
	b = 200;

	printf("-- address access using & ---\n");
	printf("variable a value is %d, at address 0x%p\n", a, &a);
	printf("variable b value is %d, at address 0x%p\n", b, &b);

	int* a_p;
	int* b_p;

	a_p = &a;
	b_p = &b;

	printf("-- address access using pointer variable---\n");
	printf("variable a value is %d, at address 0x%p\n", a, a_p);
	printf("variable b value is %d, at address 0x%p\n", b, b_p);

		
	printf("-- Accessing data using pointer variable---\n");
	printf("variable a value is %d, at address 0x%p\n", *a_p, a_p);
	printf("variable b value is %d, at address 0x%p\n", *b_p, b_p);
}

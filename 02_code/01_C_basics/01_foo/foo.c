#include <stdio.h>
#include "increment.h"

int main() {
	int a;

	a = 7;
	printf("a value is %d\n", a);		

	a = increment(a);
	printf("a value is incremented to %d\n", a);
	return 0;

}

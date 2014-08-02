#include <stdio.h>
#define SWAP(x, y) { typeof(x) temp = x; x = y; y = temp; }
/* typeof is an operator provided by several programming languages which determines the data type of a given
variable. */
int main(void)
{
	int a = 10000, b = 2;
	float x = 99999.0f, y = 2.0f;
	int *pa = &a;
	int *pb = &b;
	printf("BEFORE:\n");
	printf("a = %d, b = %d\n", a, b);
	printf("x = %f, y = %f\n", x, y);
	printf("pa = %p, pb = %p\n", pa, pb);
	SWAP(a, b); // swap ints
	SWAP(x, y); // swap floats
	SWAP(pa, pb); // swap pointers
	printf("AFTER:\n");
	printf("a = %d, b = %d\n", a, b);
	printf("x = %f, y = %f\n", x, y);
	printf("pa = %p, pb = %p\n", pa, pb);
	return 0;
}


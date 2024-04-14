#include <stdlib.h>
#include <stdio.h>

//prototype
unsigned power(unsigned x, unsigned y);

int main(void) {
	unsigned a[] = {0, 1, 2, 3, 0, -2};
	unsigned b[] = {0, 1, 2, 3, 4, 3};
	unsigned res[] = {1, 1, 4, 27, 0, -8};

	for (int i=0; i < 6; i++) {
		if (res[i] != power(a[i],b[i])) {
				printf("%d elevado a %d en power da %d\n", a[i],b[i],power(a[i],b[i]));
				exit(EXIT_FAILURE);
				}
	}
	return EXIT_SUCCESS;
}

#include <stdlib.h>
#include <math.h>

unsigned power (unsigned x, unsigned y);

void check_power(unsigned x, unsigned y, unsigned (*power)(unsigned int, unsigned int)) {
	unsigned result = pow(x,y);
	if (result != power(x,y)) { 
		exit(EXIT_FAILURE);
	}
}

int main(void) {
	check_power(2,2,&power); 
	return EXIT_SUCCESS;
}

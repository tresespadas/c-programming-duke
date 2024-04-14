#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y) {
// x elevado a y
	if (y < 0){
		return 1/power(x,y);
	}
	else if (y == 0){
		return 1;
	}
	else if (y == 1){
		return x;
	}
	else {
		return x * power(x,y-1);
	}
}

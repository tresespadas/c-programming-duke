#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
	int months; // number of months it is applicable to
	double contribution; // dolars contributed or spent per month
	double rate_of_return; // rate of returns after inflation
}; 
typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired){
	for (int i = 0; i < working.months + retired.months; i++) {	
		printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, initial);
		if (i < working.months) {
			initial = (initial * working.rate_of_return) + working.contribution + initial;
		} else {
			initial = (initial * retired.rate_of_return) + retired.contribution + initial;
		}
		startAge++;
	}
}

int main (void) {
	retire_info working;
	working.months = 489;
	working.contribution = 1000;
	working.rate_of_return = 0.045/12.0;
	retire_info retired;
	retired.months = 384;
	retired.contribution = -4000;
	retired.rate_of_return = 0.01/12.0;
	retirement(327, 21345, working, retired);

	return EXIT_SUCCESS;
}

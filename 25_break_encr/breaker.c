#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int largest_num(const int * p, int n){
	int max = p[0];
	int pos = 0;
	for (int i = 0; i < n; i++){
		if (max < p[i]){
			max = p[i];
			pos = i;
		}
	}
	return pos;
}

void letter_counter(FILE * f){ int arr[26] = {0}; 
	int c;
	while ((c = fgetc(f)) != EOF){
		if (isalpha(c)){
			c = tolower(c);
			arr[c - 97]++;
		}
	}
	int res = largest_num(arr, 26);
	res += 'a';

	//printf("%c\n", res); // Printea la letra más repetida en input.txt
	if (res >= 101){
		printf("%d\n", res - 101); // 101 es el ascii de e, suponiendo que es la letra más repetirda
	} else {
		printf("%d\n", (122 + (res - 96)) - 101);
	}
}


int main (int argc, char **argv){
	if (argc != 2){
		fprintf(stderr, "Usage: ./breaker inputFileName\n");
		return EXIT_FAILURE;
	}
	FILE * f = fopen(argv[1], "r");
	if (f == NULL){
		fprintf(stderr, "Could not open file.\n");
		return EXIT_FAILURE;
	}
	letter_counter(f);
	if (fclose(f) != 0){
		perror("Failed to close the input file!");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

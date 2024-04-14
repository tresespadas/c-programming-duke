#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(char matrix[10][10]){
        for (int i = 0; i < 10 / 2; i++) {
                for (int j = i; j < 10 - i - 1; j++) {
                        int temp = matrix[i][j];
                        matrix[i][j] = matrix[10 - 1 - j][i];
                        matrix[10 - 1 - j][i] = matrix[10 - 1 - i][10 - 1 - j];
                        matrix[10 - 1 - i][10 - 1 - j] = matrix[j][10 - 1 - i];
                        matrix[j][10 - 1 - i] = temp;
                }
            }
}

int main(int argc, char **argv){
	if (argc != 2){
		fprintf(stderr, "Usage: ./rotateMatrix.c inputFileName\n");
		return EXIT_FAILURE;
	}
	
	FILE *f = fopen(argv[1], "r");
	if (f == NULL){
		fprintf(stderr, "Could not open file\n");
		return EXIT_FAILURE;
		}

	char buff[10][10];
	int c;
	int i = 0;
	int j = 0;
	int counter = 0;

	while((c = fgetc(f)) != EOF){
		if (counter > 9){	
			fclose(f);
			fprintf(stderr, "Too many lines\n");
			exit(EXIT_FAILURE);
		}
		if (c == '\n'){
			if (j < 10){
				fclose(f);
				fprintf(stderr, "Line too short\n");
				return EXIT_FAILURE;
			}
			if (j > 10){
				fclose(f);
				fprintf(stderr, "Line too long\n");
				return EXIT_FAILURE;
			}
			i++;
			j = 0;
			counter++;
		} else {
			buff[i][j] = c;
			j++;
		}
	}
	if (i < 10){	
		fclose(f);
		fprintf(stderr, "Too little lines\n");
		return EXIT_FAILURE;
	}
	//if (i > 10){	
	//	fclose(f);
	//	fprintf(stderr, "Too many lines\n");
	//	return EXIT_FAILURE;
	//}

	fclose(f);

	rotate(buff);

	for (int row = 0; row < 10; row++){
		for (int col = 0; col < 10; col++){
			printf("%c", buff[row][col]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}

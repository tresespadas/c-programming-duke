#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

int main (void) {
	int array0[] = {2};
	int array1[] = {0,0,0};
	int array2[] = {0}; // Testing n = 0
	int array3[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1}; //basic 123 mentioned in forum (3)
	int array4[] = {1, 2, 1, 3, 5, 7, 2, 4, 6, 9}; //example in next-README (4)
	int array5[] = {1, 3, 6, 8, 1, 2, 4, 1,99, 0}; //MaxSeq at beginning, OB1 case (4)
	int array6[] = {1, 3, 6, 8, 3, 2, 3, 4,10,99}; //MaxSeq at end, OB1 case (5)
	int array7[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //all the same (1)
	int array8[] = {10,9, 8, 7, 6, 5, 4, 3, 2, 1}; //all decreasing (1)
	int array9[] = {-3,-2,-1,0, 1, 2, 3, 0, 0, 0}; //increasing from negative (7)
	int array10[] = {0, 1, 2,-3,-4,-5, 0, 0, 0, 0}; //increasing into negative (3)


	if (maxSeq(array0, sizeof(array0)/sizeof(array0[0])) != 1){
	       printf("Failure on array0\n");	
	       exit(EXIT_FAILURE);
	}

	if (maxSeq(array1, sizeof(array1)/sizeof(array1[0])) != 1){
	       printf("Failure on array1\n");	
	       exit(EXIT_FAILURE);
	}

	if (maxSeq(array2, 0) != 0){
	       printf("Failure on array2 con n=0\n");	
	       exit(EXIT_FAILURE);
	}

	if (maxSeq(array2, 1) != 1){
	       printf("Failure on array2\n");	
	       exit(EXIT_FAILURE);
	}


	if (maxSeq(array3, sizeof(array3)/sizeof(array3[0])) != 3){
	       printf("Failure on array3\n");	
	       exit(EXIT_FAILURE);
	}
	
	if (maxSeq(array4, sizeof(array4)/sizeof(array4[0])) != 4){
	       printf("Failure on array4\n");	
	       exit(EXIT_FAILURE);
	}
	if (maxSeq(array5, sizeof(array5)/sizeof(array5[0])) != 4){
	       printf("Failure on array5\n");	
	       exit(EXIT_FAILURE);
	}
	if (maxSeq(array6, sizeof(array6)/sizeof(array6[0])) != 5){
	       printf("Failure on array6\n");	
	       exit(EXIT_FAILURE);
	}
	if (maxSeq(array7, sizeof(array7)/sizeof(array7[0])) != 1){
	       printf("Failure on array7\n");	
	       exit(EXIT_FAILURE);
	}
	if (maxSeq(array8, sizeof(array8)/sizeof(array8[0])) != 1){
	       printf("Failure on array8\n");	
	       exit(EXIT_FAILURE);
	}
	if (maxSeq(array9, sizeof(array9)/sizeof(array9[0])) != 7){
	       printf("Failure on array9\n");	
	       exit(EXIT_FAILURE);
	}
	if (maxSeq(array10, sizeof(array10)/sizeof(array10[0])) != 3){
	       printf("Failure on array9\n");	
	       exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

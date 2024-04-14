#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

#define NUM_TESTS 12
counts_t * createCounts(void) {
  //WRITE ME
	counts_t * ans = malloc(sizeof(counts_t));
	ans->array = NULL;
	ans->length = 0;
	ans->u_counter = 0;
	for (size_t i = 0; i < NUM_TESTS; i++) {
		// realloc + length++
		ans->array = realloc(ans->array, (ans->length + 1) * sizeof(one_count_t *));
		ans->array[i]->str = testData[i];
	       	ans->array[i]->counter = 0;	
		ans->length++;
	}
	return ans;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
	for (size_t i = 0; i < c->length; i++) {
		if (strstr(c->array[i]->str, name) != NULL) {
			c->array[i]->counter++;
		}
	}
	c->u_counter++;
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
	for (size_t i = 0; c->length; i++) {
		fprintf(outFile, "%s: %d\n", c->array[i]->str, c->array[i]->counter);
	}	
	if (c->u_counter > 0) {
		fprintf(outFile, "<unknown>: %d\n", c->u_counter);
	}
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (size_t i = 0; i < c->length; i++) {
	free(c->array[i]->str);
	free(c->array[i]->counter);
	free(c->array[i]);
	free(c->array);
	free(c);
}

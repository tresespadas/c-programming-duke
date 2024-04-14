#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

/*
 En createCounts solo creas 1 y en addCount vas reallocando a medida que no se repitan y no sean NULL.
 Si se repiten: counter++
 Si es NULL: u_counter++

 La idea no es que el array de punteros a struct no tenga 12 length si no que tenga la length de los únicos
 valores.
 REVISAR TAMBIEN LOS STRUCTS PARA QUE SEAN one_count_t ** array (Un puntero que apunta a un array de punteros
 que apuntan a structs one_cout_t)
  */

counts_t * createCounts(void) {
  //WRITE ME
	counts_t * ans = malloc(sizeof(counts_t));
	ans->array = NULL;
	ans->length = 0;
	ans->u_counter = 0;

	return ans;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
	if(name == NULL) {
		c->u_counter++;
		return;
	}
	for (size_t i=0; i < c->length; i++) {
		if (strcmp(c->array[i]->str, name) == 0) {
			c->array[i]->counter++;
			return;
		}
	}
	c->array = realloc(c->array, (c->length + 1) * sizeof(one_count_t *));
	c->array[c->length] = malloc(sizeof(one_count_t));
	c->array[c->length]->str = name;
	c->array[c->length]->counter = 1;
	c->length++;
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
	for (size_t i = 0; i < c->length; i++) {
		fprintf(outFile, "%s: %d\n", c->array[i]->str, c->array[i]->counter);
	}	
	if (c->u_counter > 0) {
		fprintf(outFile, "<unknown>: %d\n", c->u_counter);
	}
}

void freeCounts(counts_t * c) {
  //WRITE ME
	for (size_t i = 0; i < c->length; i++) {
		free(c->array[i]);
	}
	free(c->array);
	free(c);
}

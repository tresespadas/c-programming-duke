#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


char *keyGen(char *line) {
	if (line == NULL || *line == '\0') {
		return NULL; // Empty line, return NULL
	}
    char *igual = strchr(line, '=');
    if (igual == NULL) {
        return NULL;
    }

    // Calculate the length of the key
    size_t keyLength = igual - line;

    // Allocate memory for the key including space for the null terminator
    char *key = malloc((keyLength + 1) * sizeof(char));
    if (key == NULL) {
	    fprintf(stderr, "could not allocate memory for key");
	    exit(EXIT_FAILURE);
    }

    // Copy the key from 'line' into 'key' including the null terminator
    strncpy(key, line, keyLength);
    key[keyLength] = '\0'; // Ensure null termination
    return key;
}

char *valueGen(char *line) {
    char *igual = strchr(line, '=');
    if (igual == NULL) {
        return NULL;
    }

    char *end = strchr(line, '\0');

    // Calculate the length of the value
    size_t valueLength = end - (igual + 1) - 1;

    // Allocate memory for the value including space for the null terminator
    char *value = malloc((valueLength + 1) * sizeof(char));
    if (value == NULL) {
	    fprintf(stderr, "could not allocate memory for value");
	    exit(EXIT_FAILURE);
    }

    // Copy the value from 'line' into 'value' including the null terminator
    strncpy(value, igual + 1, valueLength);
    value[valueLength] = '\0'; // Ensure null termination
    return value;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
	if (fname == NULL){
		perror("fname equals to NULL\n");
		return NULL;
	  }
  	FILE * file = fopen(fname, "r");
	if (file == NULL){
	  fprintf(stderr, "Could not open file: %s. Exiting...\n", fname);  
	  exit(EXIT_FAILURE);
	}
	kvarray_t * ans = malloc(sizeof(kvarray_t));
	ans->array = NULL;
	ans->length = 0;

	char * line = NULL;
	size_t sz = 0;
	while(getline(&line,&sz,file) >= 0){
		ans->array = realloc(ans->array, (ans->length + 1) * sizeof(kvpair_t *));//sizeof?
		ans->array[ans->length] = malloc(sizeof(kvpair_t));
		ans->array[ans->length]->key = keyGen(line);
		ans->array[ans->length]->value = valueGen(line);
		ans->length++;
	}
	if (fclose(file) != 0){
		fprintf(stderr, "Could not close file: %s. Exiting...\n", fname);
		return NULL;	
	}
	free(line);
	return ans;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (size_t i = 0; i < pairs->length; i++) {
		free(pairs->array[i]->key);
		free(pairs->array[i]->value);
		free(pairs->array[i]);
	}
  	free(pairs->array);
	free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
	for (int i = 0; i < pairs->length; i++) {
		printf("key = '%s' value = '%s'\n", pairs->array[i]->key, pairs->array[i]->value);
		}
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
 for (size_t i = 0; i < pairs->length; i++) {
	 if(pairs->array[i]->key && pairs->array[i]->value) {
		if (strcmp(pairs->array[i]->key, key) == 0) {
			return pairs->array[i]->value;
		}
	 }
  }
  return NULL;	
}

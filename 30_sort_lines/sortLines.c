#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
	if (argc == 1){
		// Lee del stdin
		char **data = NULL;
		char *line = NULL;
		size_t sz = 0;
		int i = 0;
		while (getline(&line,&sz,stdin) >= 0) {
			if (*line == '\n'){
				break;
			}
			data = realloc(data, (i+1) * sizeof(data));
			data[i] = line;
			line = NULL;
			i++;
		}
		free(line);
		sortData(data,i);
		for (size_t n = 0; n < i; n++){
			printf("%s", data[n]);
			free(data[n]);
		}
		free(data);
	}
	if (argc > 1){
		for (size_t f = 1; f < argc; f++){ // f=file
			FILE * file = fopen(argv[f], "r");
			if (file == NULL){
				fprintf(stderr, "Could not open file: %s. Exiting...", argv[f]);
				return EXIT_FAILURE; 
			}
			char **data = NULL;
			char *line = NULL;
			size_t sz = 0;
			int i = 0;
			while (getline(&line,&sz,file) >= 0) {
				if (*line == EOF){
					break;
				}
				data = realloc(data, (i+1) * sizeof(data));
				data[i] = line;
				line = NULL;
				i++;
			}
			free(line);
			sortData(data,i);
			for (size_t n = 0; n < i; n++){
				printf("%s", data[n]);
				free(data[n]);
			}
			free(data);
			if (fclose(file) != 0){
				fprintf(stderr, "Failed to close file: %s. Aborting...", argv[f]);
				return EXIT_FAILURE;
			}
		}
	}

  return EXIT_SUCCESS;
}

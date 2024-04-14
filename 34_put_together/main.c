#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t *ans = createCounts();
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
	  fprintf(stderr, "Could not open file: %s. Exiting...\n", filename);
	  exit(EXIT_FAILURE);
  }
  char **data = NULL;
  char *line = NULL;	
  size_t sz = 0;
  size_t i = 0;
  while(getline(&line, &sz, f) >= 0) {
	  line[strcspn(line, "\n")] = '\0'; 
	  data = realloc(data, (i+1) * sizeof(char *));
	  data[i] = line;
	  addCount(ans, lookupValue(kvPairs, data[i]));
	  line = NULL;
	  i++;
  }
  free(line);
  //for (size_t j = 0; j < i; j++) {
  //        //const char *value = data[j];
  //        addCount(ans, lookupValue(kvPairs, data[j]));
  //}
  if (fclose(f) != 0) {
	  fprintf(stderr, "Could not exit file: %s. Exiting...", filename);
	  exit(EXIT_FAILURE);
  }
  
  for (size_t k = 0; k < i; k++) {
	  free(data[k]);
  }
  free(data);

  return ans;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
 //read the key/value pairs from the file named by argv[1] (call the result kv)
	if (argc < 3) {
		fprintf(stderr, "Usage: ./count_value key-value.txt value1 ...");
		exit(EXIT_FAILURE);
	}
	kvarray_t * kv = readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
	for (size_t i = 2; i < argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
		counts_t *c = countFile(argv[i], kv);	
    //compute the output file name from argv[i] (call this outName)
		char *outName = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    		FILE *f = fopen(outName, "w");
		if (f == NULL) {
			fprintf(stderr, "Could not open file: %s. Exiting...\n", outName);
			exit(EXIT_FAILURE);
		}
    //print the counts from c into the FILE f
		printCounts(c,f);
    //close f
		if (fclose(f) != 0) {
			fprintf(stderr, "Could not close file: %s. Exiting...\n", outName);
			exit(EXIT_FAILURE);
		}
    //free the memory for outName and c
		free(outName);
		freeCounts(c);
	}
 //free the memory for kv
  freeKVs(kv);

  return EXIT_SUCCESS;
}

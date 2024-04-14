#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n){
  if (n <= 0) {
    return 0;
  }
  if (array == NULL) { 
    return 0;
  }
  int seq = 1; 
  int seq2 = 0;
  int *p = array; 
  for (int i = 1; i < n; i++) {
    if (seq2 == 0 && *p < array[i]){
      seq++;
    } else if (seq2 != 0 && *p < array[i]){
      seq2++;
    } else {
      seq2 = 1;
    }
    p = &array[i];
    if (seq < seq2) {
      seq = seq2;
      seq2 = 0;
    }
  }
  return seq;
}

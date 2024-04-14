#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"
#include <string.h>

struct score_tag {
  unsigned *hands;
  size_t n_hands;
}; typedef struct score_tag score_t;

int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  if (argc > 3 || argc < 2) {
	  fprintf(stderr, "Usage: ./nameProgram inputFile.txt optionalValue");
	  exit(EXIT_FAILURE);
  }

  unsigned trial_value = 0;
  if (argc == 3) {
	  trial_value = atoi(argv[2]); 
  } else {
	  trial_value = 10000;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Could not open inputFile");
    exit(EXIT_FAILURE);
  }
  size_t n_hands = 52; //Not important - will get overwritten
  future_cards_t * fc = malloc(sizeof(future_cards_t));
  fc->decks = NULL;
  fc->n_decks = 0;

  deck_t **hands = read_input(f, &n_hands, fc); 
  deck_t *remaining_deck = build_remaining_deck(hands, n_hands);
  
  score_t *score = malloc(sizeof(score_t));
  score->hands = NULL;
  score->n_hands = 0;

  score->hands = realloc(score->hands, (n_hands + 2) * sizeof(unsigned)); //+1 for tie
  for (size_t i = 0; i < n_hands + 2; i++) {
  score->hands[i] = 0;
  }
  score->n_hands = n_hands;
  
  for (size_t i = 0; i < trial_value; i++) {
    shuffle(remaining_deck);
    future_cards_from_deck(remaining_deck, fc); // Asignas los ?0, ?1, ... cartas

    int index = 0; // Used as winner index too
    int n_ties = 0;
    for (size_t j = 1; j < n_hands; j++) {
      if (compare_hands(hands[index],hands[j]) == 1) {
        //score->hands[j]++;
        //index = j;
	continue;
      } else if (compare_hands(hands[index],hands[j]) == -1) {
         //score->hands[index]++;
	//continue; 
	index = j;
      } else {
        //score->hands[n_hands + 1]++;
	n_ties++;
      }
    }
      if (n_ties == n_hands - 1) {
	score->hands[n_hands + 1]++; // Allocated space for ties
      } else {
	score->hands[index]++;
      }
  }

  for (size_t i = 0; i < n_hands; i++) {
    printf("Hand %zu won %u/%u times (%.2f%%)\n", i, score->hands[i], trial_value, (double)score->hands[i] / (double)trial_value * 100);
  }
  //printf("And there where %u ties\n", score->hands[n_hands+1]);
  printf("And there where %u ties\n", score->hands[n_hands+1]);

  free(score->hands);
  free(score);

  return EXIT_SUCCESS;
}

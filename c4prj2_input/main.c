#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char ** argv) {
  FILE * f = fopen(argv[1], "r");
  size_t n_hands = 52;
  
  future_cards_t * fc = malloc(sizeof(future_cards_t));
  fc->n_decks = 0;
  fc->decks = NULL;

  deck_t ** hands = read_input(f, &n_hands, fc);
  printf("Here are the input hands:\n");
  for (size_t i = 0; i < n_hands; i++) {
    print_hand(hands[i]);
    printf("\n");
  }

  deck_t * deck = build_remaining_deck(hands, n_hands);
  printf("Here's the remaining deck:\n");
  print_hand(deck);
  //shuffle(deck);

  future_cards_from_deck(deck, fc); // Aquí está el problema
  printf("\n Here are the filler in hands:\n");
  for (size_t i = 0; i < fc->n_decks; i++) {
	  //for (size_t = 0; i < fc->decks[i].n_cards; j++) {
	    print_hand(&fc->decks[i]);
	    printf("\n");
	  }
  //}
  printf("\n Here are the resulting hands:\n");
  for (size_t i = 0; i < n_hands; i++) {
	  print_hand(hands[i]);
	  printf("\n");
  }

  free_deck(deck);
  for (size_t i = 0; i < n_hands; i++) {
    free_deck(hands[i]);
  }
  free(hands);
  for (size_t i = 0; i < fc->n_decks; i++) {
	  for (size_t j = 0; j < fc->decks[i].n_cards; j++) {
	    free(fc->decks[i].cards[j]);
	  }
  }
  free(fc->decks);
  free(fc);

  if (fclose(f) != 0) {
    fprintf(stderr, "problem closing input file\n");
    exit(EXIT_FAILURE);
  }
  
  return EXIT_SUCCESS;
}

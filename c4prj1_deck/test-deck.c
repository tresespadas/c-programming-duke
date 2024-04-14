#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"

int main(){
  deck_t * testDeck=malloc(sizeof(deck_t));
  testDeck->n_cards=0;
  testDeck->cards=NULL;
  
  card_t testCard;

  for (int i=0; i < 7; i++){
    testCard = card_from_num(i);
    add_card_to(testDeck, testCard);
  }
  printf("testDeck length is now %zu\n", testDeck->n_cards);
  print_hand(testDeck);
  printf("\n");

  unsigned *match_count = get_match_counts(testDeck);
  for (size_t i = 0; i < testDeck->n_cards; i++){
	  printf("%d ", match_count[i]);
  }

  printf("\nFreeing memory...\n");
  free_deck(testDeck);

  return 0;
}

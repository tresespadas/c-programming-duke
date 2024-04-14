#include <stdio.h>
#include <stdlib.h>
#include "cards.h" // card_t struct declaration
#include "deck.h" // deck_t struct declaration
#include "future.h" //future_cards_t struct declaration

//struct future_cards_tag {
//	deck_t * deck;
//	size_t n_decks;
//}; typedef struct future_cards_tag future_cards_t;	
	
void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
	if (index >= fc->n_decks) {
		fc->decks = realloc(fc->decks, (index + 1) * sizeof(deck_t));
		for (size_t i = fc->n_decks; i <= index; i++) {
			fc->decks[i].cards = NULL;
			fc->decks[i].n_cards = 0;
		}
		fc->n_decks = index + 1;
	}
	//add_card_to(&fc->decks[index], *ptr);
	fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards + 1) * sizeof(card_t *));
	fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
	fc->decks[index].n_cards++;
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {
	if (deck->n_cards < fc->n_decks) {
		fprintf(stderr, "Not enough cards to assign for future cards");
		return;
	}
	for (size_t i = 0; i < fc->n_decks; i++) {
		for (size_t j = 0; j < fc->decks[i].n_cards; j++) {
			*(fc->decks[i].cards[j]) = *(deck->cards[i]);
		}
	}
}

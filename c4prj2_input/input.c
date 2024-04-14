#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
	if (strlen(str) < 15){
		fprintf(stderr, "Not enough cards in hand");
		exit(EXIT_FAILURE);
	}
	deck_t *hand = malloc(sizeof(deck_t));
	hand->cards = NULL;
	hand->n_cards = 0;
	for (size_t i = 0; i < strlen(str); i++) {
		if (str[i] == '\n'  || str[i] == '\0' || str[i] == ' ') { 
			continue;
		} else if (str[i] == '?') {
			card_t *ptr = add_empty_card(hand);
			int index = atoi(&str[i+1]);
			add_future_card(fc, index, ptr);
			if (index > 9)  // Weird math to fix ?10
				i += 2;
			else 
				i++;
		} else {
			card_t card = card_from_letters(str[i], str[i+1]);
			add_card_to(hand, card);
			i++;
		}
	}
	return hand;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
	deck_t **deck = NULL;
	char *hand = NULL;
	size_t sz = 0;
	size_t i = 0;
	while(getline(&hand, &sz, f) >= 0) {
		deck = realloc(deck, (i + 1) * sizeof(deck_t *));
		deck[i] = hand_from_string(hand, fc);
		free(hand);
		hand = NULL;
		i++;
	}
	free(hand);
	*n_hands = i;

	return deck;
}

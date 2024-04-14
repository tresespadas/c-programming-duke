#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void add_card_to(deck_t *deck, card_t c) {
	deck->cards = realloc(deck->cards, (deck->n_cards + 1) * sizeof(card_t *));
	deck->cards[deck->n_cards] = malloc(sizeof(card_t)); // Al ser un array de punteros hacia card_t tienes que darle espacio
	*(deck->cards[deck->n_cards]) = c;
	deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck) {
	card_t empty_card = {0, 0};
	add_card_to(deck, empty_card);
	
	return deck->cards[deck->n_cards - 1];
}	

deck_t *make_deck_exclude(deck_t * excluded_cards) {
	deck_t *deck_exclude = malloc(sizeof(deck_t));
	deck_exclude->cards = NULL;
	deck_exclude->n_cards = 0;
	for (size_t i = 0; i < 52; i++) { // Pasas por las 52 cartas pero solo vas a añadir las que no estén
		card_t possible_card = card_from_num(i);
		if (deck_contains(excluded_cards, possible_card) == 0) {
			add_card_to(deck_exclude, possible_card);	
		}
	}
	return deck_exclude;
}

deck_t *build_remaining_deck(deck_t **hands, size_t n_hands) {
	deck_t *excluded_cards = malloc(sizeof(deck_t));
	excluded_cards->cards = NULL;
	excluded_cards->n_cards = 0;
	for (size_t i = 0; i < n_hands; i++) {
		for (size_t j = 0; j < hands[i]->n_cards; j++) {
			if (hands[i]->cards[j]->value != 0) {
				if (deck_contains(excluded_cards, *hands[i]->cards[j]) == 0) {
					add_card_to(excluded_cards, *hands[i]->cards[j]);
				}
			}
		}
	}
	deck_t *remaining_deck = make_deck_exclude(excluded_cards);

	free_deck(excluded_cards);

	return remaining_deck;
}

void free_deck(deck_t * deck) {
	for (size_t i = 0; i < deck->n_cards; i++) {
		free(deck->cards[i]);
	}
	free(deck->cards);
	free(deck);
}

void print_hand(deck_t * hand){
	for (int i=0; i < hand->n_cards; i++){
		print_card(*hand->cards[i]);
		printf(" ");
	}
}

int deck_contains(deck_t * d, card_t c) {
	for (int i=0; i < d->n_cards; i++){
		if (d->cards[i]->value == c.value && d->cards[i]->suit == c.suit){
			return 1;
		}
	}
	return 0;
}

void shuffle(deck_t * d){
	for (int i=0; i < d->n_cards; i++){
		int random = rand() % d->n_cards;
		card_t temp = *d->cards[i];
		*d->cards[i] = *d->cards[random];
		*d->cards[random] = temp;
	}
}

 
void assert_full_deck(deck_t * d) {
	for (int i=0; i < d->n_cards; i++){
		//if (deck_contains(d, card_from_num(i)) != 1){
		//	printf("ERROR: Deck contains %c%c card->", d->cards[i]->value, d->cards[i]->suit);
			assert(deck_contains(d, card_from_num(i)) == 1);
		//}
	}	
}

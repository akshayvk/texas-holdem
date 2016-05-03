#include <cstdlib>
#include "Deck.h"

Deck::Deck() {
	for(int i = 0; i < 13; ++i) {
		for(int j = 0; j < 4; ++j) {
			pack.push_back(Card((Rank)i, (Suit)j));
		}
	}
	next = 0;
}

void Deck::shuffle() {
	int index;
	for(int i = 0; i < DECK_SIZE; ++i) {
		index = rand() % (DECK_SIZE - i) + i;
		swap(pack[i], pack[index]);
	}
}

void Deck::reset() {
	next = 0;
	shuffle();
}

Card* Deck::dealNext() {	
	return &pack[next++];
}
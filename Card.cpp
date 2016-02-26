#include "Card.h"

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

void Card::printCard(){
	cout << RANK_NAMES[rank] << " of " << SUIT_NAMES[suit] << endl;
}

Rank Card::getRank(){
	return rank;
}

bool compareCards(Card* a, Card* b){
	return (a->getRank() > b->getRank());
}
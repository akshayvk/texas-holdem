#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS};

enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
            JACK, QUEEN, KING, ACE};

const int SUIT_SIZE = 4;
const int RANK_SIZE = 13;            
const char *const SUIT_NAMES[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const char *const RANK_NAMES[] = {"Two", "Three", "Four", "Five", "Six", 
                                  "Seven", "Eight", "Nine", "Ten", "Jack", 
                                  "Queen", "King", "Ace"};
class Card {
  Rank rank;
  Suit suit;

public:
	Card() {}
	Card(Rank r, Suit s) : rank(r), suit(s) {}
	void printCard();
	Rank getRank();
	Suit getSuit();

};

struct Compare {
	bool operator()(Card* a, Card* b) {
		return (a->getRank() > b->getRank());
	}
};

#endif

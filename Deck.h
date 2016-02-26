#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

using namespace std;

const int DECK_SIZE = 52;

class Deck {
  vector<Card> pack;
  int next; 
public:
	Deck();
	void shuffle();
	void reset();
	Card dealNext();
};



#endif

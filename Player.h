#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Player {
  string name;   // This Player's name
  vector<Card> hand; // Cards in this Player's hand
  int total;
public:
  Player(string name);
  void addCard(Card& a);
  void emptyHand();
};


#endif

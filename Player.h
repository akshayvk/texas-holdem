#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Player {
protected:
  string name;   // This Player's name
  int total;
  int activeBet;
  bool active;
  vector<Card*> hand; // Cards in this Player's hand
  
public:
  virtual void addCard(Card* a) = 0;
  virtual void emptyHand() = 0;
  virtual void wager(int& center) = 0;
  virtual void raise(int bet, int& center) = 0;
  virtual void winsMoney(int winnings) = 0;
  virtual void nextRound() = 0;

};


#endif

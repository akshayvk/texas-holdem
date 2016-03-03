#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;

enum Hands {HIGH, ONE_PAIR, TWO_PAIR, THREE_KIND, STRAIGHT, 
      FLUSH, FULL, FOUR_KIND, STRAIGHT_FLUSH};

class Player {
protected:
  string name;   // This Player's name
  int total;
  int activeBet;
  bool active;
  vector<Card*> hand; // Cards in this Player's hand
  vector<int> typeSuit;
  vector<int> typeRank;
  
public:
  virtual void addCard(Card* a) = 0;
  virtual void emptyHand() = 0;
  virtual void call(int highest, int& center) = 0;
  virtual void raise(int bet, int& center) = 0;
  virtual void winsMoney(int winnings) = 0;
  virtual void printHand(int num) = 0;
  virtual int getActiveBet() = 0;
  virtual int getMoney() = 0;
  virtual Hands getBestHand() = 0;
  bool getActive() {return active;}
};


#endif

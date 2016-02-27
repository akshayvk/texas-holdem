#ifndef USER_H
#define USER_H
#include "Player.h"

class User : public Player {
public:
	User(string s);
  	virtual void addCard(Card* a);
  	virtual void emptyHand();
	virtual void wager(int& center);
	virtual void raise(int bet, int& center);
	virtual void winsMoney(int winnings);
	virtual void nextRound();
};

#endif
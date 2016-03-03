#ifndef USER_H
#define USER_H
#include "Player.h"

class User : public Player {
public:
	User(string s);
  	virtual void addCard(Card* a);
  	virtual void emptyHand();
	virtual void call(int highest, int& center);
	virtual void raise(int bet, int& center);
	virtual void winsMoney(int winnings);
	virtual void printHand(int num);
	virtual int getActiveBet();
	virtual int getMoney();
	virtual Hands getBestHand();
};

#endif
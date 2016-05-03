#ifndef SMARTPLAYER_H
#define SMARTPLAYER_H
#include "Player.h"


class SmartPlayer : public Player {
	const int CALLMODE = 0;
	const int RAISEMODE = 1; 
	int confidenceScore;
	void strategyValid(int& curr, int& center, int mode);
public:
	int pid;
	SmartPlayer(string s);
  	virtual void addCard(Card* a);
  	virtual void emptyHand();
  	virtual Hands getBestHand();
  	virtual int getActiveBet();
	virtual void call(int highest, int& center);
	virtual void raise(int bet, int& center);
	virtual void winsMoney(int winnings);
	virtual void printHand(int num);
	virtual int getMoney();
	
};

#endif
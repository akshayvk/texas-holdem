#include "User.h"

User::User(string s) {
	name = s;
	total = 1000;
	activeBet = 0;
	active = true;
}

void User::addCard(Card* a) {
	hand.push_back(a);
}

void User::emptyHand() {
	hand.clear();
	activeBet = 0;
	active = false;
}

void User::wager(int& center) {
	total -= 5;
	activeBet += 5;
	center += 5;
}

void User::raise(int bet, int& center) {
	total -= bet;
	activeBet += bet;
	center += bet;
}

void User::winsMoney(int winnings) {
	total += winnings;
}

void User::nextRound() {
	emptyHand();
}
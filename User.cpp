#include "User.h"

User::User(string s) {
	name = s;
	total = 1000;
	activeBet = 0;
	active = true;
	typeSuit.reserve(4);
	typeRank.reserve(13);
}

void User::addCard(Card* a) {
	hand.push_back(a);
	typeSuit[(int)a->getSuit()]++;
	typeRank[(int)a->getRank()]++;
}

void User::emptyHand() {
	hand.clear();
	typeSuit.clear();
	typeRank.clear();
	activeBet = 0;
}

Hands User::getBestHand() {
	Hands best = HIGH;
	sort(hand.begin(), hand.end(), Compare());
	for(unsigned int i = 0; i < typeRank.size(); ++i) {
		if(typeRank[i] == 2 && best <= TWO_PAIR) {
			if(best == ONE_PAIR) {
				best = TWO_PAIR;
			}
			else {
				best = ONE_PAIR;
			}
		}
		else if(typeRank[i] == 3) {
			best = THREE_KIND;
		}
	}
	
	/*bool found = false;
	for(unsigned int i = 0; i < hand.size() - 5; ++i) {
		for(unsigned int j = i + 1; j < i + 5; ++j) {
			if(((int)hand[j - 1]->getRank()) + 1 == (int)(hand[j]->getRank())) {
				found = true;
			}
			else {
				found = false;
				break;
			}
		}
		if(found) {
			best = STRAIGHT;
		}
	}*/
	
	for(unsigned int i = 0; i < typeSuit.size(); ++i) {
		if(typeSuit[i] == 5) {
			if(best == STRAIGHT) {
				best = STRAIGHT_FLUSH;
			}
			else {
				best = FLUSH;
			}
		}
	}
	if(best != STRAIGHT_FLUSH) {
		bool first = false;
		for(unsigned int i = 0; i < typeRank.size(); ++i) {
			if(typeRank[i] == 2) {
				first = true;
			}
			else if(typeRank[i] == 3) {
				if(first && best < FOUR_KIND) {
					best = FULL;
				}
			}
			else if(typeRank[i] == 4) {
				best = FOUR_KIND;
			}
		}
	}

	return best;
}

void User::call(int highest, int& center) {
	int diff = highest - activeBet;
	total -= diff;
	activeBet = highest;
	center += diff;
}

void User::raise(int bet, int& center) {
	total -= bet;
	activeBet += bet;
	center += bet;
}

void User::winsMoney(int winnings) {
	total += winnings;
}

void User::printHand(int num) {
	cout << "YOU: " << endl;
	hand[0]->printCard();
	hand[1]->printCard();
	cout << endl;	
}

int User::getActiveBet() {
	return activeBet;
}

int User::getMoney() {
	return total;
}


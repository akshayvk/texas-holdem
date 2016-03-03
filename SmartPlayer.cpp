#include "SmartPlayer.h"

SmartPlayer::SmartPlayer(string s) {
	name = s;
	total = 1000;
	activeBet = 0;
	active = true;
	confidenceScore = 0;
	typeSuit.reserve(4);
	typeRank.reserve(13);
}

void SmartPlayer::addCard(Card* a) {
	hand.push_back(a);
	typeSuit[(int)a->getSuit()]++;
	typeRank[(int)a->getRank()]++;
}

void SmartPlayer::emptyHand() {
	hand.clear();
	activeBet = 0;
	active = false;
	confidenceScore = 0;
}

Hands SmartPlayer::getBestHand() {
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
	
	bool found = false;
	for(unsigned int i = 0; i < hand.size(); ++i) {
		for(unsigned int j = i + 1; j < i + 5; ++j) {
			if(hand[i - 1] + 1 == hand[i]) {
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
	}
	
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

int SmartPlayer::getActiveBet() {
	return activeBet;
}

void SmartPlayer::strategyValid(int& curr, int& center, int mode) {
	int confidenceScore = (int)(getBestHand());
	if(mode == CALLMODE) {
		if(activeBet + (confidenceScore * 100) > curr) {
			int diff = curr - activeBet;
			total -= diff;
			activeBet = curr;
			center += diff;
		}
		else {
			cout << "Opponent folds" << endl;
			emptyHand();
		}
	}
	else {
		if(confidenceScore > 1 && total > activeBet) {
			activeBet += (total * .05 * confidenceScore);
			center += (total * .05 * confidenceScore);
			total -= (total * .05 * confidenceScore);
		}
	}
}

void SmartPlayer::call(int highest, int& center) {
	strategyValid(highest, center, CALLMODE);
}

void SmartPlayer::raise(int bet, int& center) {
	strategyValid(bet, center, RAISEMODE);
}

void SmartPlayer::winsMoney(int winnings) {
	total += winnings;
}

void SmartPlayer::printHand(int num) {
	cout << "PLAYER " << num << ": " << endl;
	hand[0]->printCard();
	hand[1]->printCard();
	cout << endl;	
}


int SmartPlayer::getMoney() {
	return total;
}


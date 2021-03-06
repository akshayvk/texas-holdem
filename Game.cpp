#include "Card.h"
#include "Deck.h"
#include "User.h"
#include "SmartPlayer.h"

using namespace std;

const int BLIND = 5;
const char *const HAND_NAMES[] = {"High Card", "One Pair", "Two Pair", "Three of a Kind", 
									"Straight", "Flush", "Full House", "Four of a Kind",
									"Straight Flush"};
vector<Player*> table;

void printTable(vector<Card*>& sharedCards) {
	cout << endl;
	cout << "YOU: Bet =  " << table[0]->getActiveBet() << ", Total = " << table[0]->getMoney() << endl;	
	for(unsigned int i = 1; i < table.size(); ++i) {
		cout << "PLAYER " << table[i]->getName() << ": Bet =  " << table[i]->getActiveBet() << ", Total = " << table[i]->getMoney() << endl;
	}
	cout << endl;
	table[0]->printHand(0);
	cout << endl << "AT THE CENTER: " << endl;
	for(unsigned int i = 0; i < sharedCards.size(); ++i) {
		sharedCards[i]->printCard();
	}
	cout << endl;
}

int findWinner(){
	Hands best = table[0]->getBestHand();
	int winner = 0;
	for(unsigned int i = 1; i < table.size(); ++i) {

		Hands curr = table[i]->getBestHand();
		table[i]->printHand(i);
		if(curr > best) {
			winner = i;
			best = curr;
		}
	}
	if(winner == 0) {
		cout << "You win the hand with a" << HAND_NAMES[(int) best] << "!" << endl;
	}
	else {
		cout << "Player " << winner << " wins the hand with a " << HAND_NAMES[(int) best] << "!" << endl;
	}
	return winner;
}

void betting(int& center) {
	int bet, highest = BLIND;
	for(unsigned int i = 0; i < table.size(); ++i) {
		if(table[i]->getActive()) {
			if(i == 0) {
				if(table[i]->getActiveBet() < highest) {
					table[i]->call(highest, center);
				}
				else {
					cout << "What will you bet? ";
					cin >> bet;
					if(bet == 0) {
						cout << "You folded." << endl;
						table[0]->emptyHand();
					}
					else {
						table[i]->raise(bet, center);
					}
				}
			}
			else {
				if(table[i]->getActiveBet() < highest) {
					table[i]->call(highest, center);
				}
				else {
					table[i]->raise(0, center);
				}
			}
		}
	}
}

void simulate(string name, int numPlayers) {
	int center = 0;
	Deck d;
	table.resize(numPlayers);
	vector<Card*> sharedCards;

	
	table[0] = new User(name);
	Card* nextCard;
	for(int i = 1; i < numPlayers; ++i) {
		table[i] = new SmartPlayer("BOB" + char(i));
	}

	while(!table.empty()) {
		//DEAL CARDS
		d.shuffle();
		for(unsigned int i = 0; i < table.size() * 2; ++i) {
			nextCard = d.dealNext();
			table[i % table.size()]->addCard(nextCard);
		}
		//PLACE WAGER
		center += BLIND;
		betting(center);
		//FLIP 3
		nextCard = d.dealNext();
		sharedCards.push_back(nextCard);
		for(unsigned int i = 0; i < table.size(); ++i) {
			table[i]->addCard(nextCard);
		}
		nextCard = d.dealNext();
		sharedCards.push_back(nextCard);
		for(unsigned int i = 0; i < table.size(); ++i) {
			table[i]->addCard(nextCard);
		}
		nextCard = d.dealNext();
		sharedCards.push_back(nextCard);
		for(unsigned int i = 0; i < table.size(); ++i) {
			table[i]->addCard(nextCard);
		}
		printTable(sharedCards);
		//RAISES AND CALLS
		betting(center);
		//FLIP 1
		nextCard = d.dealNext();
		sharedCards.push_back(nextCard);
		for(unsigned int i = 0; i < table.size(); ++i) {
			table[i]->addCard(nextCard);
		}
		printTable(sharedCards);
		//RAISES AND CALLS
		betting(center);
		//FLIP FINAL
		nextCard = d.dealNext();
		sharedCards.push_back(nextCard);
		for(unsigned int i = 0; i < table.size(); ++i) {
			table[i]->addCard(nextCard);
		}
		printTable(sharedCards);
		//RAISES AND CALLS
		betting(center);
		//REVEAL HAND AND CHECK FOR WINNER
		printTable(sharedCards);
		int winner = findWinner();
		table[winner]->winsMoney(center);
		//RESET AND REMOVE BANKRUPT
		center = 0;
		if(table[0]->getMoney() == 0) {
			cout << "Sorry. You Lost!" << endl;
			//for(unsigned int i = 0; i < table.size(); ++i) {
			//	delete table[i];
			//}
			return;
		}
		else {
			table[0]->emptyHand();
		}
		for(unsigned int i = 1; i < table.size(); ++i) {
			table[i]->emptyHand();
			while(i < table.size() && table[i]->getMoney() <= 0) {
				//delete table[i];
				table.erase(table.begin() + i);
			}
		}
		d.reset();
		sharedCards.clear();
	}
}

int main() {
	int num;
	bool done = false;
	string name, temp;
	cout << "Let's Play Texas Hold'Em" << endl;
	cout << "Enter Your Name: ";
	cin >> name;
	cout << "How many players would you like to join you (You may select up to 9)?" << endl;
	cin >> num;
	while(!done) {
		simulate(name, num + 1);
		cout << "Do you want to play again? (Y/N)" << endl;
		cin >> temp;
		(temp == "Y") ? done = false : done = true;
	}
	return 0;
}
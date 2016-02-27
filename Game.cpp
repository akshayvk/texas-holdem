#include "Card.h"
#include "Deck.h"
#include "User.h"

using namespace std;

enum HANDS {HIGH, ONE_PAIR, TWO_PAIR, THREE_KIND, STRAIGHT, 
			FLUSH, FULL, FOUR_KIND, STRAIGHT_FLUSH};

void betting(vector<Player*> table, vector<Card*> sharedCards) {

}

void simulate(string name, int numPlayers) {
	Deck d;
	vector<Player*> table(numPlayers);
	vector<Card*> sharedCards;
	User u = User(name);
	table[0] = &u;
	for(int i = 1; i < numPlayers; ++i) {
		
	}
	while(!table.empty()){
		//DEAL CARDS
		//PLACE WAGER
		//FLIP 3
		//RAISES AND CALLS
		//FLIP 1
		//RAISES AND CALLS
		//FLIP FINAL
		//RAISES AND CALLS
		//REVEAL HAND
		//RESET
	}
}

int main() {
	int num;
	string name;
	cout << "Let's Play Texas Hold'Em" << endl;
	cout << "Enter Your Name: ";
	cin >> name;
	cout << "How many players would you like to join you (You may select up to 9)?" << endl;
	cin >> num;
	simulate(name, num + 1);
	return 0;
}
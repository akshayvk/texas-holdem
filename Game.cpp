#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

void simulate(string name, int numPlayers){
	Deck d;
	
}
int main(){
	int num;
	string name;
	cout << "Let's Play Texas Hold'Em" << endl;
	cout << "Enter Your Name: ";
	cin >> name;
	cout << "How many players would you like to join you (You may select up to 9)?" << endl;
	cin >> num;
	simulate(name, num);
	return 0;
}
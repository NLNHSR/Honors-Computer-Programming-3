#ifndef _CARD_H
#define _CARD_H
#include <string>
#include <iostream>

using namespace std;
class Card {
	public:
		Card();
		Card(int, int);

		string toString() {
			string sName;
			switch (suit) {
			case 1: sName = "Diamonds"; break;
			case 2: sName = "Spades"; break;
			case 3: sName = "Hearts"; break;
			case 4: sName = "Clubs"; break;
			}
			return (to_string(value) + " of " + sName);
		}

		void setVal(int);
		void setSuit(int);

	private:
		int value, suit;
};
Card::Card() {
	value = 1; suit = 1;
}
Card::Card(int v, int s) {
	value = v; suit = s;
}
void Card::setVal(int v) {
	value = v;
}
void Card::setSuit(int s) {
	suit = s;
}

#endif 
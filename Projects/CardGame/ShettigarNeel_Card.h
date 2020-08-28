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
		if (value < 10) {
			return (to_string(value) + " ." + to_string(suit));
		}
		else {
			return (to_string(value) + "." + to_string(suit));
		}
		
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
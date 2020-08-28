#ifndef _PLAYER_HAND_H
#define _PLAYER_HAND_H
#include "ShettigarNeel_Card.h"
#include "ShettigarNeel_Deck.h"

class pHand {
	public:

		void initialize() {
			for (int i = 1; i <= 52; i++) {
				hand->setSuit(0);
				hand->setVal(0);
			}
		}

		void fill(Deck deck) {
			for (int i = 1; i <= 7; i++) {
				hand[i].setVal(stoi(deck.deck[1].toString().substr(0, 2)));
				hand[i].setSuit(stoi(deck.deck[1].toString().substr(3, 1)));
				string test = deck.draw();
			}
		}

		void print(int count) {
			string sSuit, sHand = "Player Hand: ";

			for (int x = 1; x <= count; x++) {
				switch (stoi(hand[x].toString().substr(3, 1))) {
					case 1: sSuit = "C"; break;
					case 2: sSuit = "D"; break;
					case 3: sSuit = "S"; break;
					case 4: sSuit = "H"; break;
				}
				sHand += to_string(stoi(hand[x].toString().substr(0,2))) + sSuit + ", ";
			}
			cout << endl << sHand;
		}

		void add(int& count, Deck deck) {
			count++;
			deck.draw();
			hand[count].setVal(stoi(deck.deck[0].toString().substr(0, 2)));
			hand[count].setSuit(stoi(deck.deck[0].toString().substr(3, 1)));
		}

		void subtract(int& count, Deck deck, Card card) {
			for (int i = 1; i <= count; i++) {
				if ((hand[i].toString().substr(0, 2)) == (card.toString().substr(0, 2))) {
					if ((hand[i].toString().substr(3, 1)) == (card.toString().substr(3, 1))) {
						for (int x = i; x <= 51; x++) {
							hand[x] = hand[x + 1];
						}
					}
				}
			}
			count--;
		}
	private:
		Card hand[52];
};

#endif _PLAYER_HAND_H
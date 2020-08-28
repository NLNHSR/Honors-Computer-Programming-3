#ifndef _DECK_H
#define _DECK_H
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>
#include "ShettigarNeel_Card.h"

class Deck {
	public:

		void fill() {
			int i = 1;
			for (int x = 1; x <= 4; x++) {
				for (int y = 1; y <= 13; y++) {
					deck[i].setSuit(x);
					deck[i].setVal(y);
					i++;
				}
			}
		}

		void shuffle() {
			srand((unsigned)time(0));
			for (int i = 1; i <= 2704; i++) {
				int x = rand() % 52 + 1;
				int y = rand() % 52 + 1;
				Card temp = deck[x];
				deck[x] = deck[y];
				deck[y] = temp;
			}
		}

		void print() {
			for (int i = 1; i <= 52; i++) {
				std::cout << deck[i].toString() << endl;
			}
		}

		string topCard() {
			string sSuit;
			switch (stoi(this->draw().substr(3, 1))) {
				case 1: sSuit = "C"; break;
				case 2: sSuit = "D"; break;
				case 3: sSuit = "S"; break;
				case 4: sSuit = "H"; break;
			}
			return("Top Card: " + to_string(stoi(this->draw().substr(0, 2))) + sSuit);
		}

		string draw() {
			string card = deck[1].toString();
			for (int i = 1; i <= 51; i++) {
				deck[i] = deck[i + 1];
			}
			return card;
		}

		Card deck[53];

	private:

};

#endif
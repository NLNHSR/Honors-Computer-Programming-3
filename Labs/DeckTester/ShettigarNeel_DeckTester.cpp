#include <iostream>
#include "ShettigarNeel_Deck.h"

int main()
{
	Deck testDeck;
	std::cout << "Full Deck:\n";
	testDeck.fill();
	testDeck.print();

	std::cout << "\nShuffled Deck:\n";
	testDeck.shuffle();
	testDeck.print();
}


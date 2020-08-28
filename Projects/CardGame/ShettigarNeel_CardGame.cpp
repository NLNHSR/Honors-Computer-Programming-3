#include <iostream>
#include "ShettigarNeel_Deck.h"
#include "ShettigarNeel_PlayerHand.h"

using namespace std;
int main()
{
	Card testCard; Deck testDeck; pHand testHand;
	int pCount = 7, dCount = 7;
	
	/* 
	   Required classes to play any card game are set up
	   programmer just needs to logically order methods 
	   to create anygame they want.
	   ---------------------------------------------
	   all methods and constructors are tested below
	*/

	cout << "\nFull Deck Ordered:\n\n";
	testDeck.fill(); testDeck.print();
	cout << "\nFull Deck Shuffled:\n\n";
	testDeck.shuffle(); testDeck.print();
	cout << endl << testDeck.topCard() << endl;
	testDeck.fill();

	cout << "\nStarting Player Hand:\n\n";
	testHand.initialize();
	testHand.fill(testDeck);
	testHand.print(pCount);
	cout << "\nPlayer Hand Subtract 1 Card:\n\n";
	testCard.setSuit(1); testCard.setVal(8);
	testHand.subtract(pCount, testDeck, testCard);
	testHand.print(pCount);
	cout << "\nPlayer Hand Add 1 Card(Drawn from deck):\n\n";
	testHand.add(pCount, testDeck);
	testHand.print(pCount);

	return 0;
}
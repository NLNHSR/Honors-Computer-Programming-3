/*
Program Name: Snack Bar 9.3 Lab
Creator: Neel Shettigar
Date: 03/12/2020
Purpouse: 
Write a program that acts as a point of sale 
system at a rodeo bar that sells 6 items,and
outputs the total with tax , using functions
*/

// Include necessary librairies
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

// Function prototype
void Menu(float total);
void Add(char choice, int amount, float& total);
void Total(float total);
void changeColor(int desiredColor);

int main()
{
	// Initialize variables
	char choice;
	int amount;
	float total = 0;
	bool run = true;

	// While loop to keep running program again
	while (run == true) { 
		do {
			// Outputs the menu of options
			Menu(total);
			cin >> choice;

			// Checks for special cases
			if (choice != 'X' && choice != 'T') {
				cout << "How many do you want?: ";
				cin >> amount;
			}
			else {
				amount = 0;
			}
			Add(choice, amount, total);
		} while (choice != 'T');
		Total(total);

		// Check for "while loop"
		char repeat;
		cout << "\nDo you want to repeat(y/n)?: ";
		cin >> repeat;
		if (repeat != 'y') {
			run = false;
		}
		total = 0;
	}
}

// Store Menu function
void Menu(float total) {
	system("CLS");
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << setfill('=') << setiosflags(ios::right);
	changeColor(13);
	cout << setw(22) << "MENU" << setw(19) << "=\n\n" << setfill('.');
	changeColor(15);
	cout << "S-Sandwich:" << setw(29) << "$5.60\n";
	cout << "C-Chips:" << setw(32) << "$2.30\n";
	cout << "B-Brownie:" << setw(30) << "$3.50\n";
	cout << "P-Pickle:" << setw(31) << "$1.40\n";
	cout << "R-Regular Drink:" << setw(24) << "$4.10\n";
	cout << "L-Large Drink:" << setw(27) << "$6.60\n\n";
	changeColor(14);
	cout << "The total is($):" << setw(23) << total << endl<<endl;
	changeColor(12);
	cout << "X-Cancel sale and start over\n";
	changeColor(10);
	cout << "T-Total the sale\n";
	changeColor(15);
	cout << "\nWhat do you want?: ";
}

// Function to add items or clear
void Add(char choice, int amount, float& total) {
	const float SC = 5.6; const float CC = 2.3; const float BC = 3.5; const float PC = 1.4; const float RC = 4.1; const float LC = 6.6;
	switch (choice) {
	case 'S': total += SC * amount; break;
	case 'C': total += CC * amount; break;
	case 'B': total += BC * amount; break;
	case 'P': total += PC * amount; break;
	case 'R': total += RC * amount; break;
	case 'L': total += LC * amount; break;
	case 'X': total = 0; break;
	}
}

// Function to total everything together
void Total(float total) {
	changeColor(13);
	cout << setfill('#') << setw(39) << "#" << setiosflags(ios::right) << setfill('.') << endl;
	changeColor(15);
	cout << "Subtotal($):" << setw(27) << total << endl;
	cout << "Tax-6%($):" << setw(29) << (total * .06) << endl;
	cout << "Total($):" << setw(30) << (total * 1.06) << endl;
}

// Function to change color of console text
void changeColor(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
// Neel Shettigar
// 2-12-20
// Roman to Arabic and Arabic to Roman
// Convert Roman numerals to Arabic numbers and vice versa

#include <iostream>	// Include necessesary libraries
#include <string>
#include <iomanip>
using namespace std;

int GetVal(char numeral, char extra) {
	int val = 0;
	string num = "", num2 = ""; num += numeral; num2 += extra;

	if (num == "I") {
		val = 1;
	}
	else if (num == "V") {
		if (num2 == "b") {
			val = 5000;
		}
		else {
			val = 5;
		}
	}
	else if (num == "X") {
		if (num2 == "b") {
			val = 10000;
		}
		else {
			val = 10;
		}
	}
	else if (num == "L") {
		val = 50;
	}
	else if (num == "C") {
		val = 100;
	}
	else if (num == "D") {
		val = 500;
	}
	else if (num == "M") {
		val = 1000;
	}

	return val;
}

int main()
{
	bool run = true;
	while (run == true) {	// While loop to keep running program
		int Arabic, Choice;	// Initialize variables
		char Roman[32];
		int test = 0;
		string ARoman = "";

		cout << "1. Roman to Arabic\n";	// Choices 
		cout << "2. Arabic to Roman\n";
		cin >> Choice;

		if (Choice == 1) { // Roman to Arabic
			int TC = 0, CC = 0;
			Arabic = 0;

			cout << "\nEnter Roman Numeral <= XbarXbarXbarMXbarXCIX: ";
			cin.ignore();
			cin.getline(Roman, 32);

			while (Roman[TC] != '\0') {
				TC++;
			}

			for (int i = 0; i < TC; i++) {
				int first = GetVal(Roman[CC], Roman[CC + 1]), second = 0;
				if (first == 5000 || first == 10000) {
					second = GetVal(Roman[CC + 4], Roman[CC + 5]);
				}
				else {
					second = GetVal(Roman[CC + 1], Roman[CC + 5]);
				}
				if (first >= second) {
					test++;
					Arabic += first;
					if (first == 10000 || first == 5000) {
						CC += 4;
					}
					else {
						CC++;
					}
				}
				else if (first < second) {
					test++;
					Arabic = Arabic + (second - first);
					if (first == 10000 || first == 5000) {
						CC += 4;
					}
					else if (second == 10000 || second == 5000) {
						CC += 5;
					}
					else {
						CC += 2;
					}
				}
			}

			cout << test;
			cout << endl << test;

		}
		else if (Choice == 2) {	// Arabic to Roman
			int Xbar = 0, Vbar = 0, M = 0, D = 0, C = 0, L = 0, X = 0, V = 0, I = 0;
			cout << "\nEnter Arabic Number <= 39999: ";
			cin >> Arabic;

			while (Arabic >= 10000) {
				Arabic = Arabic - 10000;
				Xbar++;
				ARoman = ARoman + "Xbar";
			}
			while (Arabic >= 5000) {
				Arabic = Arabic - 5000;
				Vbar++;
				ARoman = ARoman + "Vbar";
			}
			while (Arabic >= 1000) {
				Arabic = Arabic - 1000;
				M++;
			}
			if ((M == 4) && (Vbar == 0)) {
				ARoman.pop_back();	// Remove the last character of a string
				ARoman.pop_back();
				ARoman.pop_back();
				ARoman.pop_back();
				ARoman = ARoman + "MVbar";
			}
			else if (M == 4) {
				ARoman.pop_back();
				ARoman.pop_back();
				ARoman.pop_back();
				ARoman.pop_back();
				ARoman = ARoman + "MXbar";
			}
			else if (M >= 1) {
				for (int i = 0; i < M; i++) {
					ARoman = ARoman + "M";
				}
			}
			while (Arabic >= 500) {
				Arabic = Arabic - 500;
				D++;
				ARoman = ARoman + "D";
			}
			while (Arabic >= 100) {
				Arabic = Arabic - 100;
				C++;
			}
			if ((C == 4) && (D == 0)) {
				ARoman.pop_back();
				ARoman = ARoman + "CD";
			}
			else if (C == 4) {
				ARoman.pop_back();
				ARoman = ARoman + "CM";
			}
			else if (C >= 1) {
				for (int i = 0; i < C; i++) {
					ARoman = ARoman + "C";
				}
			}
			while (Arabic >= 50) {
				Arabic = Arabic - 50;
				L++;
				ARoman = ARoman + "L";
			}
			while (Arabic >= 10) {
				Arabic = Arabic - 10;
				X++;
			}
			if ((X == 4) && (L == 0)) {
				ARoman.pop_back();
				ARoman = ARoman + "XL";
			}
			else if (X == 4) {
				ARoman.pop_back();
				ARoman = ARoman + "XC";
			}
			else if (X >= 1) {
				for (int i = 0; i < X; i++) {
					ARoman = ARoman + "X";
				}
			}
			while (Arabic >= 5) {
				Arabic = Arabic - 5;
				V++;
				ARoman = ARoman + "V";
			}
			while (Arabic > 0) {
				Arabic = Arabic - 1;
				I++;
			}
			if ((I == 4) && (V == 0)) {
				ARoman.pop_back();
				ARoman = ARoman + "IV";
			}
			else if (I == 4) {
				ARoman.pop_back();
				ARoman = ARoman + "IX";
			}
			else if (I >= 1) {
				for (int i = 0; i < I; i++) {
					ARoman = ARoman + "I";
				}
			}
			cout << "Roman Numberal: " << ARoman;
		}

		char repeat;
		cout << "\nDo you want to repeat (Y/N)?: ";	// Repeat code for while loop
		cin >> repeat;
		if (repeat != 'Y') {
			run = false;
		}
	}
	return 0;	// End program
}
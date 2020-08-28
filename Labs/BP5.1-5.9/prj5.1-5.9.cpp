/*
Date: 1/26/20
Program: CH 5.1-5.9
Name: Neel Shettigar
Description: Allow user to look through a menu of various programs(5.1-5.9) and chose one to execute.
*/

// Include necessary libraries
#include <iostream>

using namespace std;
int main()
{

	// Loop to run the program as many times as the user wants
	bool Run = true;
	while(Run == true) {

		// Output choices 
		cout << endl <<  "1.Charter Bus / Vans\n";
		cout << "2.Area of Eclipse\n";
		cout << "3.Degrees to Radians\n";
		cout << "4.Simple Interest\n";
		cout << "5.MPH to FPS\n";
		cout << "6.Current Calculator\n";
		cout << "7.Force Calculator\n";
		cout << "8.Energy Calculator\n";
		cout << "9.Speeding fine\n";

		// Get user choice
		char Choice;
		cout << endl << "What do you want to do ? (1 - 9): ";
		cin >> Choice;
		float A, B, Area, Radians, Degrees, MPH, FPS, I, P, R, T, V, F, M;
		const double PI = 3.14159265359;
		const unsigned int C = 299792458;
		
		// Check which choice the user selected 
		switch (Choice) {
		case '1':

			int People, NumBus, NumVan;
			cout << "How many people need transportation ?: ";
			cin >> People;
			if (People % 50 == 0) {
				NumBus = People / 50;
				cout << "The number of buses needed is: " << NumBus << endl;
			}
			else {
				NumBus = (People - (People % 50)) / 50;
				NumVan = People % 50;
				cout << "The number of buses needed is: " << NumBus << endl;
				cout << NumVan << " People are left over and need vans\n";
			}
			break;

		case '2':

			cout << "Major radius(a): ";
			cin >> A;
			cout << "Minor radius(b): ";
			cin >> B;
			Area = A * B * PI;
			cout << "The area of the eclipse is : " << Area << endl;
			break;

		case '3':

			cout << "Enter degrees: ";
			cin >> Degrees;
			Radians = Degrees / 57.3;
			cout << Radians << " Radians\n";
			break;

		case '4':

			cout << "Enter principal: ";
			cin >> P;
			cout << "Enter interest rate: ";
			cin >> R;
			cout << "Enter time(years): ";
			cin >> T;
			I = P * R * T;
			cout << "$" << I << endl;
			break;

		case '5':

			cout << "Enter MPH: ";
			cin >> MPH;
			FPS = MPH * 1.46667;
			cout << FPS << " FPS\n";
			break;

		case '6':

			cout << "Enter voltage(volts): ";
			cin >> V;
			cout << "Enter resistance(ohms): ";
			cin >> R;
			I = V / R;
			cout << "The current(amps) is : " << I << endl;
			break;

		case '7':

			cout << "Enter mass(kg): ";
			cin >> M;
			cout << "Enter acceleration(m / s): ";
			cin >> A;
			F = M * A;
			cout << "Force is : " << F << endl;
			break;

		case '8':

			double Energy, Mass;
			cout << "Enter mass(kg): ";
			cin >> Mass;
			Energy = Mass * (C ^ 2);
			cout << Energy << " Joules\n";
			break;

		case '9':

			int Speed, Limit;
			float Fine, Base, Fee;

			cout << "What is the speed limit?: ";
			cin >> Limit;
			cout << "Enter your speed(mph): ";
			cin >> Speed;
			cout << "What is the base fee?: ";
			cin >> Base;
			cout << "What is the fee per mile?: ";
			cin >> Fee;
			if (Speed > Limit) {
				Fine = Base + ((Speed - Limit) * Fee);
				cout << "Fine: $" << Fine << endl;
			}
			else {
				cout << "No fine\n";
				break;

			}
		}

		// Asks user if they want to repeat the program
		char Repeat;
		cout << endl << "Repeat program ? (y / n): ";
		cin >>  Repeat;

		if(Repeat == 'n') {
			Run = false;
		}
	}
}
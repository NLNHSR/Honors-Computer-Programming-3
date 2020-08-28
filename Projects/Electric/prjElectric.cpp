/*Project Name: Electric
Programmer: Neel Shettigar Period 5
Date: 1/13/20
Purpose:
Extra Credit:
-Change Color DONE
-Date DONE
-ASCII Art DONE
-Fix Date issue when cross over month end DONE
*/
//Includes the libraries needed for the project:
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std; //Uses the libraries included above

int main() {
	system("Color 1F"); //Set the console color to blue and the text color to white
	int KWH;
	float BR, SC, CT, LP;
	cout << "Enter KWH used: "; //Input the KWH from the user 
	cin >> KWH;
	cout << endl << setiosflags(ios::right) << setfill(' ') << setw(24) << "        C O M P S C I  Electric\n";
	cout << setfill('-') << setw(40) << "" << endl;
	cout << "Kilowatts Used" << setiosflags(ios::right) << setfill(' ') << setw(26) << KWH << endl;
	cout << setfill('-') << setw(40) << "" << endl << endl;
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
	BR = KWH * .0475;
	cout << "Base Rate" << setiosflags(ios::right) << setfill(' ') << setw(8) << to_string(KWH) << " @ $ 0.0475" << setw(7) << "$ " << BR << endl;
	SC = BR * .1;
	cout << "Surcharge" << setw(27) << "$ " << SC << endl;
	CT = BR * .03;
	cout << "City Tax" << setw(28) << "$ " << CT << endl;
	cout << setw(40) << "______" << endl << endl;
	cout << "Pay this amount" << setw(20) << "$ " << BR + SC + CT << endl << endl;
	LP = (BR + SC + CT) * 1.04;
	char sdate[9];
	_strdate_s(sdate); //Get the system date and assign it to an array of character called sdate 
	string sday, smonth, syear;
	int year = stoi("20" + syear + sdate[6] + sdate[7]), month = stoi(smonth + sdate[0] + sdate[1]), day = stoi(sday + sdate[3] + sdate[4]), days;
	//leap year condition, if month is 2
	if (month == 2) {
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			days = 29;
		else
			days = 28;
	} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){ //Checks which months have 31 days 
		days = 31;
	} else {
		days = 30;
	}
	sday = to_string(day);
	if (day + 10 > days) { //Checks if 10 days will cross over into the next month 
		day = 10 - (days - day);
		month += 1;
	} else {
		day = day + 10;
	}
	switch(month) { //Checks which month it is and sets a string variable equal to the current month 
		case 1: smonth = "January "; break;
		case 2: smonth = "February "; break;
		case 3: smonth = "March "; break;
		case 4: smonth = "April "; break;
		case 5: smonth = "May "; break;
		case 6: smonth = "June "; break;
		case 7: smonth = "July "; break;
		case 8: smonth = "August "; break;
		case 9: smonth = "September "; break;
		case 10: smonth = "October "; break;
		case 11: smonth = "November "; break;
		case 12: smonth = "December "; break;
	}
	//Sets the ending based on what the day is
	string ending;
	switch (day) {
		case 1: ending = "st "; break;
		case 2: ending = "nd "; break;
		case 3: ending = "rd "; break;
		default: ending = "th "; break;
	}
	cout << "After " << smonth << day << ending << "Pay" << setiosflags(ios::left) << setw(13) << "$ " << LP << endl << endl;
	//Creates the ASCII art:
	cout << ",---,---,---,---,---,---,---,---,---,---,---,---,---,-------," << endl;
	cout << "| ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | [ | ] | <-    |" << endl;
	cout << "|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|" << endl;
	cout << "| ->| |   | , | . | P | Y | F | G | C | R | L | / | = |  \  |" << endl;
	cout << "|-----',--',--',--',--',--',--',--',--',--',--',--',--'-----|" << endl;
	cout << "| Caps | A | O | E | U | I | D | H | T | N | S | - |  Enter |" << endl;
	cout << "|------'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'--------|" << endl;
	cout << "|        | ; | Q | J | K | X | B | M | W | V | Z |          |" << endl;
	cout << "|------,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|" << endl;
	cout << "| ctrl |  | alt |                          | alt  |  | ctrl |" << endl;
	cout << "'------'  '-----'--------------------------'------'  '------'" << endl;
	return 0;
}
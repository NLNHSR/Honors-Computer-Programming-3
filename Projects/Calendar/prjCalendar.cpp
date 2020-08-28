// Neel Shettigar
// 2-20-2020
// Calendar
// Create a monthly calendar based on a date that the user inputs

//B Monthly calendar using Zellers- DONE
//A Cells- DONE
//A++ Legend- DONE
//A+++ String or char array input(21/2/2020 or 21, 2, 2020)
//A++++ Holidays affect cells(color, symbol, asterick, etc)- DONE
//A+++++ Find formula for Easter

#include <iostream> // Include necessary libraries
#include <iomanip>
#include <Windows.h>

using namespace std;

int Zellers(int k, int m, int y) // Function for Zellers formula
{
	int c = y / 100;
	int d = int(y % 100);
	int f = 0;

	if (m == 1 || m == 2) {
		d--;
		if (d < 0) {
			d = 99;
			c--;
		}
	}

	switch (m) {
	case 1: m = 11; break;
	case 2: m = 12; break;
	case 3: m = 1; break;
	case 4: m = 2; break;
	case 5: m = 3; break;
	case 6: m = 4; break;
	case 7: m = 5; break;
	case 8: m = 6; break;
	case 9: m = 7; break;
	case 10: m = 8; break;
	case 11: m = 9; break;
	case 12: m = 10; break;
		return f;
	}
	f = k + ((13 * m - 1) / 5) + d + (d / 4) + (c / 4) - 2 * c;
	f -= 7 * (f / 7);
	if (f < 0) {
		f += 7;
	}

	return f;
}

int Days(int m, int y) {
	int num = 0;

	if (m == 2) {
		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
			num = 29;
		}
		else {
			num = 28;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		num = 30;
	}
	else {
		num = 31;
	}

	return num;
}

string Month(int m) {
	string name = "";
	switch (m) {
	case 1: name = "JANUARY"; break;
	case 2: name = "FEBRUARY"; break;
	case 3: name = "MARCH"; break;
	case 4: name = "APRIL"; break;
	case 5: name = "MAY"; break;
	case 6: name = "JUNE"; break;
	case 7: name = "JULY"; break;
	case 8: name = "AUGUST"; break;
	case 9: name = "SEPTEMBER"; break;
	case 10: name = "OCTOBER"; break;
	case 11: name = "NOVEMBER"; break;
	case 12: name = "DECEMBER"; break;
	}
	return name;
}

int Easter(int k, int m, int y) {
	return 1;
}
int Holiday(int k, int m, int y) {
	/*
	January(1):New years
	February(14):Valentines
	March(17):Saint Patrick's
	April(varies):Easter
	May(25):Memorial
	June(21):Father's
	July(4):Independance
	August(24):Kobe
	September(7):Labor
	October(31):Halloween
	November(26):Thanksgiving
	December(25):Christmas
	*/
	int color = 0;

	if (m == 1 && k == 1) {
		color = 1;
	}
	else if (m == 2 && k == 14) {
		color = 2;
	}
	else if (m == 3 && k == 17) {
		color = 3;
	}
	else if (m == 4 && k == Easter(k, m, y)) {
		color = 4;
	}
	else if (m == 5 && k == 25) {
		color = 5;
	}
	else if (m == 6 && k == 21) {
		color = 6;
	}
	else if (m == 7 && k == 4) {
		color = 8;
	}
	else if (m == 8 && k == 24) {
		color = 9;
	}
	else if (m == 9 && k == 7) {
		color = 10;
	}
	else if (m == 10 && k == 31) {
		color = 11;
	}
	else if (m == 11 && k == 26) {
		color = 13;
	}
	else if (m == 12 && k == 25) {
		color = 14;
	}
	else {
		if (Zellers(k, m, y) == 0) {
			color = 12;
		}
		else {
			color = 15;
		}
	}

	return color;
}

void changeColor(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void Legend(int k, int m, int y) {
	int d = 0;
	switch (m) {
	case 1: d = 1; changeColor(Holiday(d, m, y)); cout << "New Year's Day: 1st"; break;
	case 2: d = 14; changeColor(Holiday(d, m, y)); cout << "Valentines Day: 14th"; break;
	case 3:d = 17; changeColor(Holiday(d, m, y)); cout << "Saint Patrick's Day: 17th"; break;
	case 4:d = Easter(k, m, y); changeColor(Holiday(d, m, y));  cout << "Easter: " << Easter(k, m, y); break;
	case 5: d = 25; changeColor(Holiday(d, m, y)); cout << "Memorial Day: 25th"; break;
	case 6: d = 21; changeColor(Holiday(d, m, y)); cout << "Father's Day: 21st"; break;
	case 7: d = 4; changeColor(Holiday(d, m, y)); cout << "Independance Day: 4th"; break;
	case 8:d = 24; changeColor(Holiday(d, m, y));  cout << "Kobe Byrant Remeberance Day: 24th"; break;
	case 9:d = 7; changeColor(Holiday(d, m, y));  cout << "Labor Day: 26th"; break;
	case 10: d = 31; changeColor(Holiday(d, m, y)); cout << "Halloween: 31st"; break;
	case 11:d = 26; changeColor(Holiday(d, m, y)); cout << "Thanksgiving: 26th"; break;
	case 12:d = 25; changeColor(Holiday(d, m, y));  cout << "Christmas: 25th"; break;
	}

}

int main()
{
	changeColor(15);
	int k, m, y;

	cout << "Enter day, month, year: "; // User input for date
	cin >> k >> m >> y;

	int start = Zellers(1, m, y);
	int days = Days(m, y);

	int cc = 1;
	cout << endl << setiosflags(ios::right) << setw(14) << Month(m) << "   " << y;

	changeColor(12);
	cout << "\n Sun ";
	changeColor(15);
	cout << "MON TUE WED THU FRI SAT \n";
	cout << "_____________________________\n";
	cout << setiosflags(ios::right) << "|"; // Simple calendar setup
	for (int i = 1; i < 42; i++) {
		if (cc <= days && i > start) {
			changeColor(Holiday(cc, m, y));
			cout << setw(3) << cc;
			cc++;
			changeColor(15);
			cout << "|";
		}
		else {
			cout << setw(3) << "   |";
		}
		if (i % 7 == 0) { cout << endl << "-----------------------------" << endl << "|"; }
	}
	cout << endl;
	Legend(k, m, y);
}
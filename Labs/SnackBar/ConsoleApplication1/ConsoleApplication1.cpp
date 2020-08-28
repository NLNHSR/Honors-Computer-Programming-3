// Neel Shettigar
// 2-20-2020
// Calendar
// Create a monthly calendar based on a date that the user inputs

//B Monthly calendar using Zellers- DONE
//A Cells- DONE
//A++ Legend- DONE
//A+++ String or char array input(21/2/2020 or 21, 2, 2020)- DONE
//A++++ Holidays affect cells(color, symbol, asterick, etc)- DONE
//A+++++ Implement formula for Easter- Too lazy

#include <iostream> // Include necessary libraries
#include <iomanip>
#include <Windows.h>
#include <string>
#include <math.h>

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

void Easter(int y) {
	/*
	int a, b, c, k, p, q, m, n, d, e, day;
	string month = "";
	a = y % 19;
	b = y % 4;
	c = y % 7;
	k = floor(y / 100);
	p = floor((13 + 8 * k) / 25);
	q = floor(k / 4);
	m = (15 - p + k - q) % 30;
	n = (4 + k - q) % 7;
	d = (19 * a + m) % 30;
	e = (2 * b + 4 * c + 6 * d + n) % 7;
	if (n == 3) {
		month = "March ";
	}else if (n == 4) {
		month = "April: ";
	}
	if (d == 29 && e == 6) {
		day = 19;
	}
	else if (d == 28 && e == 6 && ((11 * m + 11) % 30) < 19) {
		day = 18;
	}else {
		if (month == "March ") {
			day = 22 + d + e;
		}else if (month == "April ") {
			day = d + e - 9;
		}
	}
	cout << "Easter is on: " << month << "-" << day;

	int bb, cc, aa, dd, ee, gg, hh, gm, ii, kk, gl, t1, nn, pp;
	bb = (y / 100);
	cc = y % 100;
	aa = y % 19;
	dd = bb / 4;
	ee = bb % 4;
	gg = (8 * bb + 13) / 25;
	hh = (19 * aa + bb - dd - gg + 15) % 30;
	gm = aa + 11 * hh / 319;
	ii = cc / 4;
	kk = cc % 4;
	gl = (2 * ee + 2 * ii - kk - hh + gm + 32) % 7;
	t1 = hh - gm + 18;
	nn = (t1 + 71) / 25;
	pp = (t1 + nn) % 32;
	t1 = hh - gm + gl + 19;
	nn = (t1 + 71) / 25;
	pp = (t1 + nn) % 32;
	cout << "Easter is on: " << pp << " / " << nn;

	int a = y;
	string day = "";
	a /= 19;
	a *= 19;
	int b;
	b = y - a;
	b++;
	switch (b) {
	case 0: day = "March 27"; break;
	case 1: day = "April 14"; break;
	case 2:day = "April 3"; break;
	case 3:day = "March 23"; break;
	case 4:day = "April 11"; break;
	case 5:day = "March 31"; break;
	case 6:day = "April 18"; break;
	case 7:day = "April 8"; break;
	case 8:day = "March 28"; break;
	case 9:day = "April 16"; break;
	case 10:day = "April 5"; break;
	case 11:day = "March 25"; break;
	case 12:day = "April 13"; break;
	case 13:day = "April 2"; break;
	case 14:day = "March 22"; break;
	case 15:day = "April 10"; break;
	case 16:day = "March 30"; break;
	case 17:day = "April 17"; break;
	case 18:day = "April 7"; break;
	case 19:day = "March 27"; break;
	}

	cout << "\nEaster is on: " << day << endl;
	*/
	int x = y;
	int a = x % 19;
	int b = x / 100;
	int c = x % 100;
	int d = b / 4;
	int e = b % 4;
	int g = (8 * b + 13) / 25;
	int h = (19 * a + b - d - g + 15) % 30;
	int m = (a + 11 * h) / 319;
	int j = c / 4;
	int k = c % 4;
	int l = (2 * e + 2 * j - k - h + m + 32) % 7;
	int n = (h - m + l + 90) / 25;
	int p = (h - m + l + n + 19) % 32;
	cout << "\nEaster is on: " << n << "/" << p << endl;
	//Easter Sunday is the pth day of the nth month
}
int Holiday(int k, int m, int y) {
	/*
	January(1):New years
	February(14):Valentines
	March(17):Saint Patrick's
	April(1):April Fool's
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
	else if (m == 4 && k == 1) {
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

int Today(int k, int cc) {
	if (k == cc) {
		return 240;
	}
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
	case 4:d = 1; changeColor(Holiday(d, m, y));  cout << "April Fool's Day: 1st"; break;
	case 5: d = 25; changeColor(Holiday(d, m, y)); cout << "Memorial Day: 25th"; break;
	case 6: d = 21; changeColor(Holiday(d, m, y)); cout << "Father's Day: 21st"; break;
	case 7: d = 4; changeColor(Holiday(d, m, y)); cout << "Independance Day: 4th"; break;
	case 8:d = 24; changeColor(Holiday(d, m, y));  cout << "Kobe Byrant Remeberance Day: 24th"; break;
	case 9:d = 7; changeColor(Holiday(d, m, y));  cout << "Labor Day: 26th"; break;
	case 10: d = 31; changeColor(Holiday(d, m, y)); cout << "Halloween: 31st"; break;
	case 11:d = 26; changeColor(Holiday(d, m, y)); cout << "Thanksgiving: 26th"; break;
	case 12:d = 25; changeColor(Holiday(d, m, y));  cout << "Christmas: 25th"; break;
	}
	Easter(y);
	cout << endl << Month(m) << "/" << k << "/" << y;
}

int main()
{
	bool run = true;
	while (run == true) {
		changeColor(15);
		int k, m, y;
		string stringdate;

		//cout << "Enter day, month, year: "; // User input for date
		//cin >> k >> m >> y;

		cout << "Enter MM/DD/YYYY: ";
		cin >> stringdate;

		m = stoi(stringdate.substr(0, 2));
		k = stoi(stringdate.substr(3, 2));
		y = stoi(stringdate.substr(6, 4));

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
				//changeColor(Today(cc, k));
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
		char ans;
		cout << "\nRepeat(y/n)?: ";
		cin >> ans;
		if (ans != 'y') {
			run = false;
		}
	}
}
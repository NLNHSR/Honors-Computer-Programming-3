#include <iomanip>
#include <iostream>
using namespace std;

void check(float [],char [], int);
void deposit(float[], char[], int);
void output(float[], char[], int);

int main() {
	bool play = true;
	while (play) {
		cout << "Welcome to KeyBank\nPlease enter this month's transactions:\nBalance:";

		bool run = true;
		float vals[100];
		char types[100] = { 'B','B' };
		cin >> vals[0];
		vals[1] = vals[0];
		int pos = 2;

		while (run) {
			char choice;
			cout << "Transaction: ";
			cin >> choice;

			switch (choice) {
			case 'C':
				check(vals, types, pos); break;
			case 'D':
				deposit(vals, types, pos); break;
			case 'E':
				run = false; break;
			default:
				float rand; cout << "Amount: "; cin >> rand;
				types[pos] = 'I';
				vals[pos] = 0;
			}
			pos++;
		}
		output(vals, types, pos);
		char again;
		cout << "\nDo you want to repeat(y/n)?: "; cin >> again; play = (again == 'Y' || again == 'y');
	}
	return 0;
}

void check(float vals[],char types[], int pos) {
	cout << "Amount: ";
	float amount;
	cin >> amount;
	if (vals[0] >= amount) {
		vals[pos] = amount;
		types[pos] = 'C';
		vals[0] -= amount;
	}
	else {
		vals[pos] = 10;
		types[pos] = 'F';
		vals[0] -= 10;
	}
}

void deposit(float vals[], char types[], int pos) {
	cout << "Amount: ";
	float amount;
	cin >> amount;
	vals[pos] = amount;
	types[pos] = 'D';
	vals[0] += amount;
}

void output(float vals[], char types[], int pos) {
	int cc = 0, dc = 0; float ct = 0, dt = 0;
	cout << "\n\nTransaction                    Amount               Balance\n";
	cout << setiosflags(ios::showpoint | ios::fixed) << setiosflags(ios::right) << setprecision(2) << fixed << setfill(' ');
	cout << "Beginning Balance" << setw(20) << vals[1] << setw(22) << vals[1]<<endl;
	vals[0] = vals[1];
	for (int i = 2; i <= (pos - 2); i++) {
		switch (types[i]) {
		case 'C':
			vals[0] -= vals[i]; cc++; ct += vals[i];
			cout << "Check" << setw(32) << vals[i] << setw(22) << vals[0]<<endl; break;
		case 'D':
			vals[0] += vals[i]; dc++; dt += vals[i];
			cout << "Deposit" << setw(30) << vals[i] << setw(22) << vals[0]<<endl; break;
		case 'F':
			vals[0] -= 10; cc++; ct += 10;
			cout << "Insufficient Funds" << setw(19) << "10.00" << setw(22) << vals[0]<<endl; break;
		case 'I':
			cout << "Illegal Transaction Code\n"; break;
		}
	}
	vals[0] -= 5; cc++; ct += 5;
	cout << "Service Charge" << setw(23) << "5.00" << setw(22) << vals[0] << endl << setfill('=') << setw(69) << '=' << endl << "Account Summary\n";
	cout << setfill(' ') << "                          Number     Amount\nBeginning Balance" << setw(24) << vals[1]<<endl;
	cout << "Plus Deposits" << setw(16) << dc << setw(12) << dt << endl;
	cout << "Less Withdrawals" << setw(13) << cc << setw(12) << ct<< endl;
	cout << "Ending Balance" << setw(27) << vals[0]<<endl;
	cout << setfill('=') << setw(69) << '='<<endl;
}
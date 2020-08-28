
// A++ reciept + date & time, What you bought + quantity
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
	system("color 70");
	char repeat;
	bool run = true;
	while (run == true)
	{
		cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
		float iPhone11ProMax = 1099.00;
		float AirPodsPro = 249.00;
		float Watch5 = 399.00;
		float MacbookPro = 2800.00;
		float iPadPro = 750.00;
		float AppleTv4K = 179.00;
		cout << " WELCOME TO THE APPLE STORE!\n";
		cout << "------------------------------\n\n";
		cout << "1.iPhone 11 Pro Max..$1,099.00\n";
		cout << "2.Airpods Pro..........$249.00\n";
		cout << "3.Watch Series 5.......$399.00\n";
		cout << "4.Macbook Pro 16.....$2,800.00\n";
		cout << "5.iPad Pro.............$750.00\n";
		cout << "6.Apple Tv 4K..........$179.00\n";
		int phone = 0;
		int airpods = 0;
		int watch = 0;
		int macbook = 0;
		int ipad = 0;
		int tv = 0;
		bool buy = true;
		while (buy == true)
		{
			char choice;
			int count;
			cout << endl << "What do you want to buy?: ";
			cin >> choice;
			cout << "Quantity?: ";
			cin >> count;
			switch (choice){
				case '1':
					phone = phone + count;
					break;
				case '2':
					airpods = airpods + count;
					break;
				case '3':
					watch = watch + count;
					break;
				case '4':
					macbook = macbook + count;
					break;
				case '5':
					ipad = ipad + count;
					break;
				case '6':
					tv = tv + count;
					break;
			}
			cout << endl << "Do you want to buy more(y/n)?: \n";
			cin >> repeat;
			if (repeat == 'n') {
				buy = false;
			}
		}
		// 30 total blocks

		float subtotal = (phone * iPhone11ProMax) + (airpods * AirPodsPro) + (watch * Watch5) + (macbook * MacbookPro) + (ipad * iPadPro) + (tv * AppleTv4K	), tender;
		const float tax = .07;
		float total = subtotal * (1 + tax);

		cout << "Total price : $" << total << endl;
		cout << "Enter tender: $";
		cin >> tender;
		float change = tender - total;
		
		char sdate[9];
		char stime[9];
		_strdate_s(sdate);
		_strtime_s(stime);
		cout << setfill('=') << setw(43) << "=\n";
		cout << "time: " << stime << " date: " << sdate << endl;

		cout << endl << "iPhone 11 Pro Max x " << phone  <<   setiosflags(ios::right) << setfill(' ') << setw(10) << "$" << (phone *  iPhone11ProMax) << endl;
		cout << "Airpods Pro       x " << airpods  <<   setiosflags(ios::right) << setfill(' ') << setw(10) << "$" << (airpods * AirPodsPro) << endl;
		cout << "Watch Series 5    x " << watch <<   setiosflags(ios::right) << setfill(' ') << setw(10) << "$" << (watch * Watch5) << endl;
		cout << "Macbook Pro       x " << macbook  <<   setiosflags(ios::right) << setfill(' ') << setw(10) << "$" << (macbook * MacbookPro) << endl;
		cout << "iPad Pro          x " << ipad << setiosflags(ios::right) << setfill(' ') << setw(10) << "$" << (ipad * iPadPro) << endl;
		cout << "Apple TV 4K       x " << tv << setiosflags(ios::right) << setfill(' ') << setw(10) << "$" << (tv * AppleTv4K) << endl;

		cout << endl<< "Subtotal is: $" << setiosflags(ios::right) << setw(25) << subtotal << endl;
		cout << "Tax is 7%\n";
		cout << "Total    " << setiosflags(ios::right) << setw(25)<< setfill('.') << "$" << total << endl;
		cout << "Cash paid" << resetiosflags(ios::right) << setw(25) << setfill('.') << "$" << tender << endl;
		cout << "Change   " << setiosflags(ios::right) << setw(25) << setfill('.') << change << endl;
		
		int C50 =0, C20=0, C10=0, C5=0, C1=0, CC25=0, CC10=0, CC5=0, CC1=0;
		while (change > 50) {
			change = change - 50;
			C50 = C50 + 1;
		}
		while (change > 20) {
			change = change - 20;
			C20 = C20 + 1;
		}
		while (change > 10) {
			change = change - 10;
			C10 = C10 + 1;
		}
		while (change > 5) {
			change = change - 5;
			C5 = C5 + 1;
		}
		while (change > 1) {
			change = change - 1;
			C1 = C1 + 1;
		}
		while (change > .25) {
			change = change - .25;
			CC25 = CC25 + 1;
		}
		while (change > .1) {
			change = change - .1;
			CC10 = CC10 + 1;
		}
		while (change > .05) {
			change = change - .05;
			CC5 = CC5 + 1;
		}
		while (change > .01) {
			change = change - .01;
			CC1 = CC1 + 1;
		}
		cout << "$50 bills x " << C50 << " = " << setiosflags(ios::right) << setw(11) << "$" << 50.00*C50 << endl;
		cout << "$20 bills x " << C20 << " = " << setiosflags(ios::right) << setw(11) << "$" << 20.00*C20 << endl;
		cout << "$10 bills x " << C10 << " = " << setiosflags(ios::right) << setw(11) << "$" << 10.00*C10 << endl;
		cout << "$5 bills  x " << C5 << " = " << setiosflags(ios::right) << setw(11) << "$" << 5.00*C5 <<endl;
		cout << "$1 bills  x " << C1 << " = " << setiosflags(ios::right) << setw(11) << "$" << C1<<endl;
		cout << "Quarters  x " << CC25 << " = " << setiosflags(ios::right) << setw(11) << "$" << 00.25 * CC25 << endl;
		cout << "Dimes     x " << CC10 << " = " << setiosflags(ios::right) << setw(11) << "$" << 00.1* CC10 << endl;
		cout << "Nickels   x " << CC5 << " = " << setiosflags(ios::right) << setw(11) << "$" << 00.05*CC5 << endl;
		cout << "Pennies   x " << CC1 << " = " << setiosflags(ios::right) << setw(11) << "$" << 00.01*CC1 << endl;
		
		cout << "				    _" << endl;
		cout << "	  			   | |" << endl;
		cout << "  __ _ _ __  _ __ | | ___" << endl;
		cout << " / _` | '_ \| '_ \| |/ _ \"" << endl;
		cout << "| (_| | |_) | |_) | |  __/" << endl;
		cout << " \__,_| .__/| .__/|_|\___|" << endl;
		cout << "    | |   | |" << endl;
		cout << "    |_|   |_|" << endl;

		cout << endl << "Do you want to repeat(y/n)?: \n";
		cin >> repeat;
		if (repeat == 'n') {
			run = false;
		}
	}
	return 0;
}


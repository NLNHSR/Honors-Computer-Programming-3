#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

int main()
{
	system("color F1");
	bool run = true;
	while (run == true) {
		int Choice, T1, T2, H1, H2, M1, M2, HD, MD;
		float A, B, C, X1, X2, Y1, Y2;
		cout << "1. Military Time\n";
		cout << "2. Parabola\n";
		cout << "What do you want to do?: ";
		cin >> Choice;

		if (Choice == 1) {
			cout << "\nEnter the first time: ";
			cin >> T1;
			cout << "\nEnter the second time: ";
			cin >> T2;

			H1 = T1 / 100;
			H2 = T2 / 100;
			M1 = T1 % 100;
			M2 = T2 % 100;

			if (H1 > H2) {
				HD = (24 - H1) + H2;
				if (M1 > M2) {
					MD = (60 - M1) + M2;
					HD = (24 - H1) + H2 - 1;
				}
				else if (M2 > M1) {
					MD = M2 - M1;
				}
				else {
					MD = 0;
				}
			}
			else if (H2 > H1) {
				HD = H2 - H1;
				if (M1 > M2) {
					MD = (60 - M1) + M2;
					HD = H2 - H1 - 1;
				}
				else if (M2 > M1) {
					MD = M2 - M1;
				}
				else {
					MD = 0;
				}
			}
			else if (H2 == H1) {
				if (M1 > M2) {
					HD = 24;
					MD = (60 - M1) + M2;
				}
				else if (M2 > M1) {
					HD = 0;
					MD = M2 - M1;
				}
			}

			cout << HD << " hours " << MD << " minutes";

		}
		else if (Choice == 2) {
			float R1, R2, I, I2, M, B, b, Int1x, Int2x, Int1y, Int2y;
			cout << "\nEnter A, B and C: ";
			cin >> A >> B >> C;
			if (((pow(B, 2)) - (4 * A * C)) > 0) {
				R1 = (-B - (sqrt(pow(B, 2) - (4 * A * C)))) / (2 * A);
				R2 = (-B + (sqrt(pow(B, 2) - (4 * A * C)))) / (2 * A);
				cout << "\nThe roots are: " << R1 << " , " << R2 << endl;
			}
			else if (((pow(B, 2)) - (4 * A * C)) < 0) {
				R1 = (-B) / (2 * A);
				I = ((pow(B, 2) - (4 * A * C)));
				I2 = (sqrt(-(I)))/(2*A);
				cout << "\nThe roots are(Fraction): " << R1 << " + (sqrt(" << I << ")/" << (2 * A) << ")i , " << R1 << " - (sqrt(" << I << ")/" << (2*A) << ")i\n";
				cout << "The roots are(Decimal): " << R1 << " + " << I2 << "i , " << R1 << " - " << I2 << "i\n";
			}
			else if (((pow(B, 2)) - (4 * A * C)) == 0) {
				R1 = -B / (2 * A);
				cout << "\nThe root is: " << R1 << endl;
			}
			cout << "\nEnter X1 and Y1: ";
			cin >> X1 >> Y1;
			cout << "\nEnter X2 and Y2: ";
			cin >> X2 >> Y2;

			M = ((X2 - X1) / (Y2 - Y1));
			b = Y2-(M * X2);
			cout << "Slope: " << M << endl;
			cout << "Y-intercept: " << b << endl;

			if ((sqrt(pow((B - M), 2) - (4 * A * (C - b)))) > 0) {
				Int1x = (-(B - M) + (sqrt(pow((B - M), 2) - (4 * A * (C - b))))) / (2 * A);
				Int2x = (-(B - M) - (sqrt(pow((B - M), 2) - (4 * A * (C - b))))) / (2 * A);
				Int1y = (M * Int1x) + b;
				Int2y = (M * Int2x) + b;
				cout << "The points of intersection: (" << Int1x << " , " << Int1y << ") and (" << Int2x << " , " << Int2y << ")\n";
			}
			else if ((sqrt(pow((B - M), 2) - (4 * A * (C - b)))) < 0) {
				cout << "There is no point of intersection";
			}
			else {
				Int1x = (-(B - M) + (sqrt(pow((B - M), 2) - (4 * A * (C - b))))) / (2 * A);
				Int1y = (M * Int1x) + b;
				cout << "\nThe point of intersection: (" << Int1x << " , " << Int1y << ")\n";
			}

		}
		char repeat;
		cout << "\nDo you want to repeat (Y/N)?: \n";
		cin >> repeat;

		if (repeat != 'Y') {
			run = false;
		}
	}
	return 0;
}

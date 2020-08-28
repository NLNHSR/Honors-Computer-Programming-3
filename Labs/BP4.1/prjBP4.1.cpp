// BP4.1.CPP
// Examples of variable declarations and
// initialization.

#include <iostream>

using namespace std;
int main()
{
	// declare a constant for the square root of two
	const double SQUARE_ROOT_OF_TWO = 1.414214;

	int i;				// declare i as an integer
	long j;				// j as long integer
	unsigned long k;	// k as an unsigned long integer
	float n;			// n as a floating point number
	int Hundred;
	int NThousand;
	unsigned int Forty;
	long NForty;
	
	i = 3;				// initialize i to 3
	j = -2048111;		// j to -2,048,111
	k = 4000000001;		// kk to 4,000,000,001
	n = 1.887;			// n to 1.887

	const float e = 2.7182818;				// Declare a constant float
	const long SPEED_OF_LIGHT = 300000000;	// Declare a constant long
	const float SPEED_OF_SOUND = 340.292;	// Declare a constant float

	Hundred = 100;
	NThousand = -1000;
	Forty = 40000;
	NForty = -40000;

	// output constants and variables to screen
	cout << "Square root of 2: " << SQUARE_ROOT_OF_TWO << '\n';
	cout << "i: " << i << '\n';
	cout << "j: " << j << '\n';
	cout << "k: " << k << '\n';
	cout << "n: " << n << '\n';
	cout << "e: " << e << endl;
	cout << "Speed of light (3.00 x 10^8): " << SPEED_OF_LIGHT << "m/s" << endl;
	cout << "Speed of sound: " << SPEED_OF_SOUND << "m/s" << endl;
	cout << "Hundred: " << Hundred << endl;
	cout << "Negative Thousand: " << NThousand << endl;
	cout << "Forty Thousand: " << Forty << endl;
	cout << "Negative Forty Thousand: " << NForty << endl;

	return 0;
}
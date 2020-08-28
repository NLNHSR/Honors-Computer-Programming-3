#include <iostream>
#include "circle.h"

using namespace std;
int main()
{
	char repeat;
	do{
		circle circ1, circ2;
		float rad;
		cout << "What is the radius of circle 1?: ";
		cin >> rad;
		circ1.SetRadius(rad);
		cout << "What is the radius of circle 2?: ";
		cin >> rad;
		circ2.SetRadius(rad);

		cout << "\nThe Area of circle 1 is: " << circ1.Area();
		cout << "\nThe Area of circle 2 is: " << circ2.Area();

		cout << "\n\nThe Circumference of circle 1 is: " << circ1.Circumference();
		cout << "\nThe Circumference of circle 2 is: " << circ2.Circumference();

		cout << "\nDo you want to repeat(y/n)?: ";
		cin >> repeat;
	} while (repeat == 'y');
}

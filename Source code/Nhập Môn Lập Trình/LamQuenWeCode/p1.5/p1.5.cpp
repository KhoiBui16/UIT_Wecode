#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int b;
	cin >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " x " << b << " = " << a * b << endl;
	cout << a << " : " << b << " = " << fixed << setprecision(2) << (float)a / b;
	return 0;
}
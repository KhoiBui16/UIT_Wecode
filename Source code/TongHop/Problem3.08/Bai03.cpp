#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int s = 0;
	int t = n;
	// tinh tong cac chu so
	while (t != 0)
	{
		int dv = t % 10;
		s += dv;
		t /= 10;
	}
	cout << s;
	return 0;
}
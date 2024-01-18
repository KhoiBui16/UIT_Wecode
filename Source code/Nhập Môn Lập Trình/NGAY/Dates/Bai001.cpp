#include <iostream>

using namespace std;

int main()
{
	char a[10];
	cin >> a;

	fgets(a, 9, stdin);
	return 0;
}
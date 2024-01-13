#include <iostream>

using namespace std;

bool IsPrime(int);

int main()
{
	int n;
	cin >> n;
	if (n == 1)
		cout << "-1";
	else if (IsPrime(n) == 1)
		cout << "1";
	else
		cout << "0";
	return 0;
}

bool IsPrime(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (!(k % i))
			dem++;
	return (dem == 2);
}
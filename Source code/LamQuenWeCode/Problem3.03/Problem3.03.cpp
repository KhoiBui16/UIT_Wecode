#include <iostream>
using namespace std;

bool KtNguyento(int);

int main()
{
	int n;
	cin >> n;
	if (KtNguyento(n))
		cout << "1";
	else if (n == 1)
		cout << "-1";
	else cout << "0";
	return 0;
}

bool KtNguyento(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (k % i == 0)
			dem++;
	if (dem == 2)
		return true;
	return false;
}


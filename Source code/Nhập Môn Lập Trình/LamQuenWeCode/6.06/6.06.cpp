#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[500];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int dem = 0;
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	for (int i = 0; i < n; i++)
		if (a[i] == max)
			dem++;
	cout << max << "\n" << dem;
	return 0;
}
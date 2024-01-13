#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	float S1, S2, S3;
	int a = 1;
	int mau = 0;


	for (int i = 1; i <= n; i++)
		S1 += pow(i, i);

	for (int i = 1; i <= n; i++)
	{
		a *= i;
		S2 += a;
	}

	for (int i = 1; i <= n; i++)
	{
		mau += i;
		S3 += (float)1 / mau;
	}
	cout << S1 << endl;
	cout << S2 << endl;
	cout << S3;
	return 0;
}
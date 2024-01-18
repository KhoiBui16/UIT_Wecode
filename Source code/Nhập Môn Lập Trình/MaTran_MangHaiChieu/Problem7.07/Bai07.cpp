#include <iostream>
using namespace std;

void TaoMaTran(float[][500], int&);
bool KtDoiXung(float[][500], int);

int main()
{
	int n;
	cin >> n >> n;
	float a[500][500];
	TaoMaTran(a, n);
	if (KtDoiXung(a, n) == 1)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

void TaoMaTran(float a[][500], int& n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

bool KtDoiXung(float a[][500], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != a[j][i])
				return false;
	return true;
}

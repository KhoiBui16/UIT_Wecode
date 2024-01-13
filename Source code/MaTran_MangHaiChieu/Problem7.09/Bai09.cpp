#include <iostream>
using namespace std;

void NhapMaTran(float [][100], float[][100], int&, int&, int&, int&);
void TongMaTran(float [][100], float[][100], int, int);

int main()
{
	int m, n, l, k;
	float a[100][100];
	float b[100][100];
	NhapMaTran(a, b, m, n, l, k);
	TongMaTran(a, b, m, n);
	return 0;
}

void NhapMaTran(float a[][100], float b[][100], int& m, int& n, int& l, int& k)
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	cin >> l >> k;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < k; j++)
			cin >> b[i][j];
}

void TongMaTran(float a[][100], float b[][100], int m, int n)
{
	float c[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = (a[i][j] + b[i][j]);
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}
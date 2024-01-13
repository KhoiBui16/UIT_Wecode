#include <iostream>
#include <iomanip>
using namespace std;

void NhapMaTran(float[][500], int&, int&);
float TongVet(float[][500], int, int);

int main()
{
	int m;
	int n;
	float a[500][500];
	NhapMaTran(a, m, n);
	cout << TongVet(a, m, n);
	return 0;
}

void NhapMaTran(float a[][500], int& m, int& n)
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

float TongVet(float a[][500], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				s += a[i][j];
	return s;

}
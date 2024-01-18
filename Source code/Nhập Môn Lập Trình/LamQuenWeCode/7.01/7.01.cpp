#include <iostream>
using namespace std;

void NhapMaTran(float a[][500], int& m, int& n)
{
	cin >> m;
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

void XuatMaTran(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int n;
	int m;
	float a[500][500];
	NhapMaTran(a, m, n);
	XuatMaTran(a, m, n);
	return 0;
}
#include <iostream>
using namespace std;

void TaoMaTran(float[][500], int&, int&);
void XuatMaTranChuyenVi(float[][500], int, int);

int main()
{
	int m, n;
	cin >> m >> n;
	float a[500][500];
	TaoMaTran(a, m, n);
	XuatMaTranChuyenVi(a, m, n);
	return 0;
}

void TaoMaTran(float a[][500], int& m, int& n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

void XuatMaTranChuyenVi(float a[][500], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[j][i] << " ";
		cout << endl;
	}
}
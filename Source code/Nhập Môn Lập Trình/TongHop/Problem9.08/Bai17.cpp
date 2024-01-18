#include <iostream>
#define MAX 50

using namespace std;


void NhapMaTran(float[][MAX], int&, int&);
float GiaTriLonNhat(float[][MAX], int, int, int);
void LonNhatTrenCot(float[][MAX], int, int);

int main()
{
	int m, n;
	float a[MAX][MAX];
	NhapMaTran(a, m, n);
	LonNhatTrenCot(a, m, n);

	return 0;
}

void NhapMaTran(float a[][MAX], int& m, int& n)
{
	// Nhap so hang
	cin >> m;
	// Nhap so cot
	cin >> n;
	// Nhap cac phan tu trong ma tran
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

float GiaTriLonNhat(float a[][MAX], int m, int n, int c)
{
	float lc = a[0][c];
	for (int i = 0; i < m; i++)
		if (a[i][c] > lc)
			lc = a[i][c];
	return lc;
}

void LonNhatTrenCot(float a[][MAX], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Gia tri lon nhat tren cot " << j << " la: " << GiaTriLonNhat(a, m, n, j) << endl;
	}
}
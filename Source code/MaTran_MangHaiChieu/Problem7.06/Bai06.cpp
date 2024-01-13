#include <iostream>
using namespace std;
#define MAX 100

void NhapMaTran(float [][MAX], int&);
bool KiemTraGiaTri(float [][MAX], int);

int main()
{
	int n;
	cin >> n;
	float a[100][100];
	NhapMaTran(a, n);
	if (KiemTraGiaTri(a, n) == true)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

void NhapMaTran(float a[][MAX], int& n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

bool KiemTraGiaTri(float a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if (a[i][j] != 0 && a[j][i] != 0) // kiem tra nhung phan tu khac duong cheo chinh
				return false;
	return true;
}
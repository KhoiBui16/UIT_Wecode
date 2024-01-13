#include <iostream>
using namespace std;

void NhapMaTran(int[], int&);
int GiaTriLonThuHai(int[], int);
int PhanTuDauTien(int[], int);

int main()
{
	int n;
	cin >> n;
	int a[500];
	NhapMaTran(a, n);
	cout << PhanTuDauTien(a, n);
	return 0;
}
void NhapMaTran(int a[], int& n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int GiaTriLonThuHai(int a[], int n)
{
	int max1 = a[0];
	int max2 = a[1];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max1)
		{
			max2 = max1;
			max1 = a[i];
		}
		else if (a[i] > max2 && a[i] < max1)
			max2 = a[i];
	}
	if (max1 == max2)
		return 0;
		return max2;
}

int PhanTuDauTien(int a[], int n)
{
	int max = GiaTriLonThuHai(a, n);
	for (int i = 0; i < n; i++)
		if (a[i] == max)
			return a[i];
	return 0;
}

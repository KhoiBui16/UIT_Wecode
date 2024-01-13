#include <iostream>
#define MAX 100

using namespace std;
void NhapMang(int[], int&);
int GiaTriLonNhat(int[], int);
int	SoLan(int[], int);
void Xuat(int[], int);
// Cach2: ngan gon
void XuatKq(int[], int);

int main()
{
	int n;
	int a[MAX];
	NhapMang(a, n);
	Xuat(a, n);
	return 0;
}

void NhapMang(int a[], int& n)
{
	// Nhap so phan tu trong ma tran
	cin >> n;
	// Nhap cac phan tu
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int GiaTriLonNhat(int a[], int n)
{
	int Max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > Max)
			Max = a[i];
	return Max;
}

int	SoLan(int a[], int n)
{
	int lc = GiaTriLonNhat(a, n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == lc)
			cnt++;
	return cnt;
}

void Xuat(int a[], int n)
{
	int max = GiaTriLonNhat(a, n);
	int cnt = SoLan(a, n);
	cout << max << endl;
	cout << cnt;
}

// Cach 2 ngan gon
void XuatKq(int a[], int n)
{
	int dem = 0;
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	int lc = max;
	for (int i = 0; i < n; i++)
		if (a[i] == lc)
			dem++;
	cout << lc << endl;
	cout << dem;
}
#include <iostream>
using namespace std;

void Nhap(int a[], int& n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (i % 2 != 0)
			cout << a[i] << " ";
}

int main()
{
	int n;
	cin >> n;
	int a[100];
	Nhap(a, n);
	Xuat(a, n);
	return 0;
}
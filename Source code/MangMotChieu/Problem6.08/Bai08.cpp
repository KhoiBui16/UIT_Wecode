#include <iostream>
using namespace std;

void Nhap(int[], int&, int&);
void XoaViTri(int[], int&, int);

int main()
{
	int n;
	int a[500];
	int x;
	Nhap(a, n, x);
	XoaViTri(a, n, x);
	return 0;
}

void Nhap(int a[], int& n, int& x)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
}

void XoaViTri(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] != x)
			cout << a[i] << " ";
}
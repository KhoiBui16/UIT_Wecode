#include <iostream>
using namespace std;

void Nhap(int[], int&, int&, int&);
void ChenViTri(int[], int&, int, int);

int main()
{
	int n;
	int a[500];
	int x;
	int k;
	Nhap(a, n, x, k);
	ChenViTri(a, n, x, k);
	return 0;
}

void Nhap(int a[], int& n, int& x, int& k)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	cin >> k;
}

void ChenViTri(int a[], int& n, int x, int k)
{
	for (int i = n - 1; i >= k; i--)
		a[i + 1] = a[i];
	a[k] = x;
	n++;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
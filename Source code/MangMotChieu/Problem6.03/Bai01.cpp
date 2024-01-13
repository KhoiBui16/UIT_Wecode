#include <iostream>
using namespace std;

void NhapMang(int[], int&);
void XuatMang(int[], int);

int main()
{
	int n;
	int a[500];
	NhapMang(a, n);
	XuatMang(a, n);
	return 0;
}

void NhapMang(int a[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];	
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (i % 2 != 0)
			cout << a[i] << " ";
}
#include <iostream>
using namespace std;

void NhapMang(int[], int&);
int KtNguyenTo(int);
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

int KtNguyenTo(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return n > 1;
}

void XuatMang(int a[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (KtNguyenTo(a[i]))
		{
			cout << a[i] << " ";
			cnt++;
		}
	if (cnt == 0)
		cout << "0";
}
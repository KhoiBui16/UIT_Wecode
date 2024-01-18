#include <iostream>
using namespace std;

void Nhap(int [500], int&);

int main()
{
	int n;
	int c[500];
	Nhap(c, n);

	return 0;
}

void Nhap(int c[500], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
}
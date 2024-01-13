#include <iostream>
#define MAX 100

using namespace std;
void TaoMang(int[], int&);
void XuatMang(int[], int);

int main()
{
	int n;
	int a[MAX];
	TaoMang(a, n);
	XuatMang(a, n);

	return 0;
}

void TaoMang(int a[], int& n)
{
	// enter number of index
	cin >> n;
	// enter numbers of array
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void XuatMang(int a[], int n)
{
	// check odd numbers
	for (int i = 0; i < n; i++)
		if (i % 2 != 0)
			cout << a[i] << " ";
}
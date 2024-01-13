#include <iostream>
using namespace std;

void NhapMaTran(int[], int&);
int GiaTriLonNhat(int[], int);
int TanSuat(int[], int);

int main()
{
	int n;
	cin >> n;
	int a[500];
	NhapMaTran(a, n);
	cout << GiaTriLonNhat(a, n) << endl;
	cout << TanSuat(a, n);

}

void NhapMaTran(int a[], int& n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int GiaTriLonNhat(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int TanSuat(int a[], int n)
{
	int max = GiaTriLonNhat(a, n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == max)
			cnt++;
	return cnt;
}
#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int[], int);
void Second(int[], int[], int[], int);
void HoanVi(int&, int&);

void Nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
}
void Second(int a[], int b[], int c[], int n1, int n2)
{
	int n3 = n1 + n2;
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) {
		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
		}
		else {
			c[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		c[k] = a[i];
		i++;
		k++;
	}
	while (j < n2) {
		c[k] = b[j];
		j++;
		k++;
	}
}

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	int a[500], b[500], c[500];
	int i, j;
	cin >> i;
	Nhapmang(a, i);
	cin >> j;
	Nhapmang(b, j);
	cout << endl;
	cout << endl;
	Second(a, b, c, i, j);
	cout << endl;
	cout << endl;
	int n3 = i + j;
	for (int i = 0; i < n3; i++)
		cout << c[i] << " ";
}
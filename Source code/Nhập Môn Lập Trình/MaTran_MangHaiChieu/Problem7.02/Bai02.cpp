// Template's header, these lines will goes before your code
#include <iostream>
using namespace std;
#define MAX 16

// Template's footer, These lines will goes after your code
void Nhapmang(int a[][MAX], int& n);
void Xuatmang(int a[][MAX], int n);

int main()
{
	int n, a[MAX][MAX];
	Nhapmang(a, n);
	Xuatmang(a, n);

	return 0;
}

// Your code
int FiboNumber(int n);

void Nhapmang(int a[][MAX], int& n)
{
	cin >> n;
	/*
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = FiboNumber(i + j + 1);
	*/
}

int FiboNumber(int n)
{
	int f1 = 0, f2 = 1, fn;
	if (n == 0)
		return f1;
	for (int i = 2; i <= n; i++)
	{
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return f2;
}

void Xuatmang(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = FiboNumber(i + j + 1);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
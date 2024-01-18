#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int[], int);
void Second(int[], int);

void Nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Second(int a[], int n)
{
	int deleter, keodai;
	cin >> deleter >> keodai;
	int temp = 0;
	for (int i = 0; i < deleter; i++)
	{
		cout << a[i] << " ";
		temp++;
	}
	for (int i = temp + keodai; i < n; i++)
	{
		cout << a[i] << " ";
	}

}

int main()
{
	int a[500];
	int n;
	cin >> n;
	Nhapmang(a, n);
	Second(a, n);

}
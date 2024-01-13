//	Template's header, these lines will goes before your code
#include <iostream>
using namespace std;
#define MAX 100

//	Your code: submit this part
void Nhapmang(int[], int);
bool isBenford(int[], int);

void Nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
bool isBenford(int a[], int n)
{
	int temp;
	int dem1 = 0;
	int dem4 = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[i] > 0)
		{
			temp = a[i] % 10;
			a[i] = a[i] / 10;
		}
		if (temp == 1)
			dem1++;
		else if (temp == 4)
			dem4++;
	}
	if (dem1 >= 3 && dem4 >= 1)
		return true;
	return false;
}

//	Template's footer, These lines will goes after your code
int main()
{
	int a[MAX], n = 10;
	Nhapmang(a, n);
	if (isBenford(a, n) == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	return 0;
}

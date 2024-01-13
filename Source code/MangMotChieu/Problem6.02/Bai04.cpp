//	Template's header, these lines will goes before your code
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int& n);
int SoPhanTuChuaY(int a[], int n, int y);

//	enter Your code: submit this part
bool ktNguyenTo(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (k % i == 0)
			dem++;
	if (dem == 2)
		return true;
	else
		return false;
}

void NhapmangSNT(int a[], int& n)
{
	cin >> n;
	int i = 2;
	int k = 0;
	while (k < n)
	{
		if (ktNguyenTo(i))
		{
			a[k++] = i;
		}
		i++;
	}
}

int SoPhanTuChuaY(int a[], int n, int y)
{
	int dem = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = a[i];
		bool daXuatHienY = false;
		while (temp > 0)
		{
			int chuSo = temp % 10;
			if (chuSo == y && !daXuatHienY)
			{
				dem++;
				daXuatHienY = true;
			}
			temp /= 10;
		}
	}
	return dem;
}


//	Template's footer, These lines will goes after your code
int main()
{
	int a[MAX], n, y;
	cin >> y;
	NhapmangSNT(a, n);
	cout << SoPhanTuChuaY(a, n, y) << endl;;
	return 0;
}
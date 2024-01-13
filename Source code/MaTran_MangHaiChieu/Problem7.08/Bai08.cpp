#include <iostream>
#define MAX 100

using namespace std;
void TaoMaTran(float[][MAX], int&);
bool KtMaTranFrobenius(float[][MAX], int);

int main()
{
	int n;
	cin >> n >> n;
	float a[MAX][MAX];
	TaoMaTran(a, n);
	if (KtMaTranFrobenius(a, n) == true)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

void TaoMaTran(float a[][MAX], int& n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

bool KtMaTranFrobenius(float a[][MAX], int n)
{
	int isDonVi = 1;
	int indexChecker = 0;	
	int flag = 1;
	// dieu kien 1: Tat ca cac phan tu tren duong cheo chinh la 1.
	for (int i = 0; i < n; i++)
		if (a[i][i] != 1) // neu dk khac 1 => gia tri tra ve false
			isDonVi = 0;
	// xet dk 2 + dk 3
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && a[i][j] != 0)
				indexChecker = j; // danh dau tai vi tri khac 0
	for (int i = 0; i < n; i++)
		for (int j = 0; j < indexChecker; j++) // xet tu dau den truoc vtri index - 1
			if (i != j && a[i][j] != 0)
				flag = 0;
	for (int i = 0; i < n; i++)
		for (int j = indexChecker + 1; j < n; j++)
			if (i != j && a[i][j] != 0) // xet tu vtri index + 1 -> n - 1
				flag = 0;
	if (isDonVi == 1 && flag == 1)
		return true;
	return false;
}



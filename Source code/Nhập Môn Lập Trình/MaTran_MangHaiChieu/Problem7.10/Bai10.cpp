#include <iostream>
using namespace std;

void TaoMaTran(float[][100], float[][100], int&, int&, int&);
void TichMaTran(float[][100], float[][100], int, int, int);

int main()
{
	int m, n, k;
	float arrA[100][100], arrB[100][100];
	TaoMaTran(arrA, arrB, m, n, k);
	TichMaTran(arrA, arrB, m, n, k);

	return 0;
}

void TaoMaTran(float arrA[][100], float arrB[][100], int& m, int& n, int& k)
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arrA[i][j];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			cin >> arrB[i][j];
}

void TichMaTran(float arrA[][100], float arrB[][100], int m, int n, int k)
{
	float arrTich[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			arrTich[i][j] = 0;
			for (int c = 0; c < n; c++)
				arrTich[i][j] += arrA[i][c] * arrB[c][j];
			cout << arrTich[i][j] << " ";
		}
		cout << endl;
	}
}
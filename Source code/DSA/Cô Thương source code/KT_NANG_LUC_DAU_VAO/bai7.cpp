#include <iostream>
using namespace std;

void nhapMaTran(int a[][100], int n, int m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Ma tran A(" << n << "x" << m << ") da nhap" << endl;
}

void xuatMaTranTheoCot(int a[][100], int n, int m)
{
    for (int i=0; i<m; i++)
    {
        cout << "Cot " << i << " gom cac so: ";
        for (int j=0; j<n; j++)
        {  
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[100][100], n, m;
    cin>>n>>m;
    nhapMaTran(a,n,m);
    xuatMaTranTheoCot(a,n,m);
    return 0;
}
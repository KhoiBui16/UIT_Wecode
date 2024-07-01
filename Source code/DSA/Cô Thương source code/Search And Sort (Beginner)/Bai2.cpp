
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <time.h>
using namespace std;

int isBinary(int **a, int m, int n)
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if(a[i][j]!=0&&a[i][j]!=1) // neu co 1 phan tu khong phai 0 hoac 1 thi khong phai ma tran nhi phan
            return 0;
    return 1;
}

void outputMatrix(int **a, int m, int n)
{
    cout << "\nMatrix: \n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
//###INSERT CODE HERE -
    srand(time(NULL));
    int m, n; cin >> m >> n;
    int **a = new int*[m];
    for (int i=0; i<m; i++) a[i] = new int[n];
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            a[i][j] = rand()%2;
        }
    }

    if (isBinary(a,m,n)==1) cout<<"Ma tran nhi phan";
    outputMatrix(a, m, n);
    return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>


//###INSERT CODE HERE -

using namespace std;

void input(int *a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void output(int *a, int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

void qs(int *a, int l, int r)
{
    int m = a[(l+r)/2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) 
        {
            swap (a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(a, l, j);
    if (i < r) qs(a, i, r);
}

void mergify(int *a, int n, int *b, int m, int *c, int &k)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

void Solve()
{
    int n, m; cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    input(a, n);
    input(b, m);
    qs(a, 0, n-1);
    qs(b, 0, m-1);
    int i = 0, j = 0;
    int *c = new int[n+m];
    int k = 0;
    mergify(a, n, b, m, c, k);
    output(c, k);
    delete[] a, b, c;
}


int main()
{
    int t; cin >> t;
    while (t--)
        Solve();
}
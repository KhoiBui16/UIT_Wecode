/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
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
    for (int i=0; i<n; i++) cout << a[i] << endl;
}

void qs(int *a, int l, int r)
{
    int i = l, j = r;
    int m = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (l < j) qs(a, l, j);
    if (i < r) qs(a, i, r);
}

void sorting(int *a, int n)
{
    int *b = new int[n], *c = new int[n];
    int curb = 0, curc = 0;
    for (int i=0; i<n; i++)
    {
        if (!(a[i]%2)) b[curb++] = a[i];
        else c[curc++] = a[i];
    }
    qs(b, 0, curb-1);
    qs(c, 0, curc-1);
    for (int i=0; i<curb; i++) a[i] = b[i];
    for (int i=curb; i<n; i++) a[i] = c[i-curb];
    delete[] b, c;
}

int main()
{
    int n; cin >> n;
    int *a = new int[10001];
    input(a, n);
    sorting(a, n);
    output(a, n);
}
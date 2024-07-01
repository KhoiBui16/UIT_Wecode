/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void inputArray(int *a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void outputArray(int *a, int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

void qs(int *a, int l, int r)
{
    int i = l, j = r;
    int m = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
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
    int resb = 0, resc = curc-1;
    for (int i=0; i<n; i++)
    {
        if (!(a[i]%2)) a[i] = b[resb++];
        else a[i] = c[resc--];
    }
    delete[] b;
    delete[] c;
}

int main()
{
    int n; cin >> n;
    int *a = new int[n];
    inputArray(a, n);
    sorting(a, n);
    cout << "Sorted Array: ";
    outputArray(a, n);
}
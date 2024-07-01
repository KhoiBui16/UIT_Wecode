/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

void input(int *a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

int bs(int *a, int n, int x)
{
    int l = 0, r = n-1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (a[m] == x) return m;
        else if (a[m] > x) r = m-1;
        else l = m+1;
    }
    return -1;
}

/*void MergeSort(int *a, int l, int r)
{
    int *b = new int[1000001];
    if (l >= r) return;
    int m = (l+r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    int i = l, j = m+1;
    int cur = 0;
    while (i <= m || j <= r)
    {
        if (i > m) b[cur++] = a[j++];
        else if (j > r) b[cur++] = a[i++];
        else if (a[i] < a[j]) b[cur++] = a[i++];
        else b[cur++] = a[j++];
    }
    for (int i=0; i<cur; i++) a[l+i] = b[i];
    delete[] b;
}*/

void Merge(int *a, int l, int mid, int r)
{
    mid = (l + r) / 2;
    int *c = new int[r - l + 1];
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j]) c[k] = a[i++];
        else c[k] = a[j++];
        k++;
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= r) c[k++] = a[j++];
    for (int i=0; i<k; i++) a[l+i] = c[i];
    delete[] c;
}

void MergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}

void Solve(int *a, int n)
{
    int x; cin >> x;
    // for (int i=0; i<n; i++) cout << a[i] << " "; - for debugging :')
    if (bs(a, n, x) != -1) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    int n, q; cin >> n >> q;
    int *a = new int[n];
    input(a, n);
    MergeSort(a, 0, n-1);
    while (q--)
    {
        Solve(a, n);
    }
    delete[] a;
}
#include <bits/stdc++.h>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

void inputArray(int* a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void outputArray(int *a, int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

void mergify(int *a, int n, int *b, int m, int *c)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

int main()
{
    int n; cin >> n;
    int *a = new int[n];
    inputArray(a, n);
    int m; cin >> m;
    int *b = new int[m];
    inputArray(b, m);
    int *c = new int[n+m];
    int l = 0, r = n-1, cnt = 0;
    mergify(a, n, b, m, c);
    outputArray(c, n+m);
}
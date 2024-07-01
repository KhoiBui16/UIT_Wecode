#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void input(int *a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

int bs(int *a, int l, int r, int x)
{
    if (l > r) return -1;
    int m = (l+r)/2;
    if (x == a[m]) return m;
    else if (x < a[m]) return bs(a, l, m-1, x);
    else if (x > a[m]) return bs(a, m+1, r, x);
    /*while (l <= r)
    {
        int m = (l+r)/2;
        if (x == a[m]) return m;
        else if (x < a[m]) r = m-1;
        else l = m+1;
    }
    return -1;*/
}

int main()
{
    int n, m; cin >> n;
    int *a = new int[n];
    input(a, n);
    cin >> m;
    while (m--) 
    {
        int x; cin >> x;
        if (x < a[0] || x > a[n-1]) cout << -1 << "\n";
        else cout << bs(a, 0, n-1, x) << "\n";
    }
}
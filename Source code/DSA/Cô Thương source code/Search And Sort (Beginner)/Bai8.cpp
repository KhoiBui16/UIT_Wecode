#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;
using ll = long long;

ll mod = (ll)(1e9+7);

void input(int *a, int n)
{
    for (int i=0; i<n-1; i++) cin >> a[i];
    a[n-1] = 0;
}

bool solve(int *a, int k, int n, int mxN)
{
    int cnt = 0;
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        if (sum + a[i] <= mxN) sum += a[i];
        else 
        {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt <= k;
}

int kq(int *a, int n, int k)
{
    int sum = 0;
    int mxN = 0;
    for (int i=0; i<n; i++)
    {
        sum += a[i];
        mxN = max(mxN, a[i]);
    }
    int l = mxN, r = sum, res = sum;
    while (l <= r)
    {
        int m = (l + (r-l)) / 2;
        if (solve(a, k, n, m))
        {
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}

int main()
{
    int n, k; cin >> n >> k;
    n++;
    int *a = new int[n];
    input(a, n);
    cout << kq(a, n, k);
}
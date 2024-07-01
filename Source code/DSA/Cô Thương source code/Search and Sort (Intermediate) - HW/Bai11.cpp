#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void Solve()
{
    ll k; cin >> k;
    bool check = 0;
    ll a = 2 * k, b = 0;
    for (ll m = sqrt(2 * k); m > 0; m--)
    {
        ll n = (2*k-m-1) / (1+2*m);
        if (n+m+2*n*m+1 == 2*k)
        {
            if (abs(a-b) > abs(n-m)) a = m, b = n;
            check = true;
        }
    }
    if (!check) cout << -1 << " " << -1 << endl;
    else cout << min(a, b) << " " << max(a, b) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) Solve();
}
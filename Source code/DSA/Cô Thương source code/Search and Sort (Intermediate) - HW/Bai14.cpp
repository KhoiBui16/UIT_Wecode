#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, x; cin >> n >> x;
    vector <int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    int ans = 0;
    sort(a.begin(), a.end(), greater<int>());
    int i = 0, j = a.size()-1;
    while (i < j)
    {
        if (a[i] + a[j] <= x) ans = max(ans, a[i] + a[j--]);
        else if (a[i] + a[j] > x) i++;
    }
    cout << ans;
}
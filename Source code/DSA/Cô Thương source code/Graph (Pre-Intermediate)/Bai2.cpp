#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int e, n;
    cin >> e >> n;
    map<string, map<string, ll>> G;
    for (int i = 0; i < e; i++) 
    {
        string s, s1;
        cin >> s >> s1;
        ll x;
        cin >> x;
        G[s][s1] = x;
    }
    while (n--)
    {
        vector<string> path;
        string s;
        while (1)
        {
            cin >> s;
            if (s == ".") break;
            path.push_back(s);
        }
        ll ans = 0;
        bool ok = 1;
        for (int i=0; i<path.size()-1; i++)
        {
            if (G[path[i]][path[i+1]]) ans += G[path[i]][path[i+1]];
            else
            {
                cout << "FALSE\n";
                ok = 0;
                break;
            }
        }
        if (ok) cout << ans << "\n";
    }
}
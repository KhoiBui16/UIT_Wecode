/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n; cin >> m >> n;
    map<int, set<int>> G;
    for (int i=0; i<n; i++)
    {
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    int ans = 0;
    for (int i=0; i<m; i++)
    {
        if (!G[i].size()) ans++;
    }
    cout << ans;
}
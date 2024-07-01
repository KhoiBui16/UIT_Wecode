#include <bits/stdc++.h>

using namespace std;


int main()
{
    int v, e; cin >> v >> e;
    map<string, set<string>> G;
    vector <string> vertises(v);
    for (int i=0; i<v; i++) cin >> vertises[i];
    for (int i=0; i<e; i++)
    {
        string x, y;
        cin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
    }
    for (int i=0; i<v; i++)
    {
        cout << G[vertises[i]].size() << " ";
    }
}
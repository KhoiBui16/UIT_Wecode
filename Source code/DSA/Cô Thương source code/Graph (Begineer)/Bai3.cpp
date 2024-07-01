#include <bits/stdc++.h>

using namespace std;


void inputGraph(vector<vector<int>>& G, int e)
{
    while (e--)
    {
        int u, i; cin >> u >> i;
        G[u][i] = G[i][u] = 1;
    }
}

void process(const vector<vector<int>>& G, int v, int u)
{
    bool ok = 0;
    for (int i=1; i<=v; i++)
    {
        if (G[u][i] || G[i][u])
        {
            ok = 1;
            cout << i << " ";
        }
    }
    if (!ok)
    {
        cout << "NONE";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e, n; cin >> v >> e >> n;
    vector <vector<int>> G(v+1, vector<int>(v+1, 0));
    inputGraph(G, e);
    while (n--)
    {
        int selection; cin >> selection;
        if (selection == 1)
        {
            int u, i; cin >> u >> i;
            (G[u][i]) ? cout << "TRUE\n" : cout << "FALSE\n";
        }
        else if (selection == 2)
        {
            int u; cin >> u;
            process(G, v, u);
            cout << "\n";
        }
    }
}
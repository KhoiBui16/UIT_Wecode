/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> adj[1001];
bool visited[1001];
vector<int> path;

void DFS(int u)
{
    path.push_back(u);
    visited[u] = true;
    for (int x : adj[u])
        if (!visited[x])
            DFS(x);
}

int main()
{
    cin >> m >> n;
    while (n--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0);
    if (adj[0].empty())
        cout << "KHONG";
    else
    {
        sort(path.begin() + 1, path.end());
        for (int i = 1; i < path.size(); i++)
            cout << path[i] << " ";
    }
    return 0;
}
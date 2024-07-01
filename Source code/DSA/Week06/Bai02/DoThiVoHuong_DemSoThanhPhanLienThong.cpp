/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> adjList[1001];
bool visited[1001];

void DFS(int u)
{
    visited[u] = true;
    for (int v : adjList[u])
        if (!visited[v])
            DFS(v);
}

int main()
{
    cin >> m >> n;
    while (n--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
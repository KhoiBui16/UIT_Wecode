/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

bool BFS(int u, int v)
{
    if (u == v)
        return true;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        visited[x] = true;
        for (int neighbor : adj[x])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                if (neighbor == v)
                    return true;
                visited[neighbor] = true;   
            }
        }
    }
    return false;
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int neighbor : adj[x])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                parent[neighbor] = x;
                visited[neighbor] = true;
            }
        }
    }
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
    /* for (int i = 1; i < m; i++)
    {
        if (BFS(0, i))
            cout << "CO" << endl;
        else
            cout << "KHONG" << endl;
        memset(visited, false, sizeof(visited));
    } */
    BFS(0);
    // DFS(0);
    for (int i = 1; i < m; i++)
    {
        if (!visited[i])
            cout << "KHONG" << endl;
        else
            cout << "CO" << endl;
    }
    return 0;
}